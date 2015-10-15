#ifndef _INTROSORT_H_
#define _INTROSORT_H_

#include <assert.h>
#include "..\heap\heap.h"

#define CHANGE_TO_INSERT 16

template<typename T>
inline void __itro_swap(T *a, T *b){
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template<typename size>
size __lg(size n){
	size r;
	for(r = 0; n > 1; n >>= 1)
		++r;
	return r;
}

template<typename T>
void __insertion_sort(T *begin, T *end){
	assert(begin <= end);
	T *p = begin;
	while(++p < end){
		T value = *p, *ptr;
		for(ptr = p-1; ptr >= begin ; --ptr){
			if(*ptr > value)
				*(ptr+1) = *ptr;
			else
				break;
		}
		*(ptr+1) = value;
	}
}

template<typename T>
T *__partition(T *first, T *last, T pivot){
	while(first < last){
		while(*first < pivot)
			++first;
		while(*last > pivot)
			--last;
		__itro_swap(first, last);
		++first;
	}
	return first;
}

template <typename T>
inline const T& __median(const T& a, const T& b, const T& c){
	if(a > b){
		if(c < b)
			return b;
		else {
			if(c < a)
				return c;
			else
				return a;
		}
	}
	else {
		if(c > b)
			return b;
		else {
			if(c > a)
				return c;
			else
				return a;
		}
	}
}

template<typename T, typename size>
void __intro_sort_loop(T *begin, T *end, size deep){
	while(end - begin > CHANGE_TO_INSERT){
		if(deep == 0){
			heap_sort(begin, end);
			return;
		}
		--deep;
		T *med = __partition(begin, end-1, __median(*begin, *(begin+(end-begin)/2), *(end-1)));
		__intro_sort_loop(med, end, deep);
		end = med;
	}
}

template<typename T>
void __linear_insert(T *last, T value){
	// puts("linear");
	T *next = last;
	--next;
	while(value < *next){
		*last = *next;
		last = next;
		--next;
	}
	*last = value;
}


template<typename T>
inline void __un_linear_insert(T *begin, T *end){
	while(begin != end){
		__linear_insert<T>(begin, *begin);
		++begin;
	}
}

template<typename T>
void intro_sort(T *begin, T *end){
	__intro_sort_loop(begin, end, __lg<size_t>(end-begin));
	if(end - begin > CHANGE_TO_INSERT){
		__insertion_sort(begin, begin+CHANGE_TO_INSERT);
		__un_linear_insert(begin+CHANGE_TO_INSERT, end);
	}
	else
		__insertion_sort(begin, end);
}



#endif