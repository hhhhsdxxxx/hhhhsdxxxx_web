/**** MAX HEAP ****/
/**** by hhhhsdxxxx ****/

#ifndef _HEAP_H_
#define _HEAP_H_

#include <assert.h>

//#define _TEST_

template<typename T>
inline void __swap(T *a, T *b){
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

//for make_heap && pop
template<typename T>
void __up_down(T *begin, T *end, T *pos){
	T *left = begin + (((pos-begin) << 1) + 1), *right = left+1;
	while(left < end){
		right = right == end ? left : right;
		left = *left >= *right ? left : right;
		if(*pos < *left)
			__swap(pos, left);
		else
			break;
		pos = left;
		left = begin + (((pos-begin) << 1) + 1);
		right = left+1;
	}
}

//for push
template<typename T>
void __down_up(T *begin, T *end, T *pos){
	if(pos >= end)
		return;
	T *father = begin+(((pos-begin)>>1)-1);
	while(father >= begin){
		if(*pos > *father)
			__swap(pos, father);
		else
			break;
		pos = father;
		father = begin+(((pos-begin)>>1)-1)
	}
}

//random iterator
template<typename T>
void make_heap(T *begin, T *end){
	assert(begin <= end);
	for(T *pos = begin+(((end-begin)>>1)-1); pos >= begin; --pos)
		__up_down(begin, end, pos);
#ifdef _TEST_
	print_all(begin, end);
#endif
}

template<typename T>
void pop_heap(T *begin, T *end){
	assert(begin < end);
	__swap(begin, --end);
	__up_down(begin, end, begin);
#ifdef _TEST_
	print_all(begin, end+1);
#endif 
}

template<typename T>
void push_heap(T *begin, T *end, T *m_end, T &mem){
	assert(end < m_end);
	*end = mem;
	__down_up(begin, end+1, end); 
}

template<typename T>
void heap_sort(T *begin, T *end){
	make_heap(begin, end);
	while(begin < end)
		pop_heap(begin, end--);
}

#ifdef _TEST_
template<typename T>
void print_all(const T *begin, T *end){
	while(begin++ < end)
		cout << *(begin-1) << " ";
	puts("");
}
#endif

#endif