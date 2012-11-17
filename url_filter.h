#include <iostream>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;

const int max_branch_num = 256;

class trie_node {
public:
    trie_node() {
        this->fail = NULL;
        memset(this->next, NULL, sizeof(next));
        this->count = 0;
    }
    ~trie_node(){

    }
    trie_node *fail;
    trie_node *next[max_branch_num];
    int count;

};

class url_filter
{
public:
    url_filter() {
        this->m_root = new trie_node();
    }
    ~url_filter() {
        destory(this->m_root);
        this->m_root = NULL;
    }
    void load(const std::string& pattern)
    {
        trie_node *p = this->m_root;
        for (int i = 0 ; i < pattern.length(); ++i)
        {
            int index = pattern[i];
            if (p->next[index] == NULL) 
                p->next[index] = new trie_node();
            p = p->next[index];
        }
        p->count++;
    }
    void build(){
        this->m_root->fail = NULL;
        queue<trie_node*> q;
        q.push(this->m_root);
        while(!q.empty()) 
        {
            trie_node *cur = q.front();
            q.pop();
            trie_node *p = NULL;
            for (int i = 0 ;i < max_branch_num; ++i) 
            {
                if (cur->next[i] != NULL)   
                {
                    if(cur == this->m_root) 
                    {
                        cur->next[i]->fail = this->m_root;
                    }
                    else
                    {
                        p = cur->fail;
                        while(p != NULL)
                        {
                            if(p->next[i] != NULL)
                            {
                                cur->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if (p == NULL) cur->next[i]->fail = this->m_root;
                    }
                    q.push(cur->next[i]);
                }       
            }
        }
    }
    bool find(std::string str)
    {
        trie_node *p = this->m_root;
        for(int i = 0; i < str.length(); ++i)
        {
            int index = str[i];
            while(p->next[index] == NULL && p != this->m_root) p = p->fail;
            p = p->next[index];
            p = (p == NULL)? this->m_root : p;
            if (p != this->m_root && p-> count > 0){
                return true;
            }
        }
        return false;
    }
    
    void destory(trie_node *p)
    {
        if (p == NULL) return;
        for (int i = 0; i < max_branch_num; ++i)
        {
            destory(p->next[i]);        
        }
        delete p;
    }
private:
    trie_node *m_root;
};
