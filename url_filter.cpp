#include "url_filter.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    url_filter filter = url_filter();
    filter.load(string("ss"));
    filter.load(std::string("abc"));
    filter.load(std::string("cas"));
    filter.build();
    cout << filter.find(string("ggggg")) << endl;
    return 0;
}
