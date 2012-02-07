
#include <functional> 
template<template<typename T> class Fn, typename T , int N> 
struct Apply 
{ 
	void To(T* r, T const* left, T const* right) const { 
		r[N-1] = Fn<T>()(left[N-1], right[N-1]); 
		Apply<Fn, T, N-1>().To(r, left, right); 
	} 
};
template<template<typename T> class Fn, typename T>
struct Apply<Fn,T,0>
{
	void To(T* r,T const* left, T const* right) const {}
};

int main() 
{ 
	int a[3], b[3], c[3]; 
	Apply<std::plus, int, 3>().To(a, b, c); // a = b + c; 
	return 0; 
} 

