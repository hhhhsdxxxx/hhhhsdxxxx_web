#include <iostream>
#include "introsort.h"

using namespace std;

const int MAX_LENGTH = 1000000;

bool is_sorted(int *begin, int *end){
	while(++begin < end)
		if(*begin < *(begin-1))
			return 0;
	return 1;
}

bool _is_same(int *s1, int *s2, int length){
	for(int i = 0; i < length; ++i)
		if(s1[i] != s2[i])
			return 0;
	return 1;
}

int main(int argc, char const *argv[]){
	int *num1 = new int[MAX_LENGTH], *num2 = new int[MAX_LENGTH];
	freopen("data.txt", "r", stdin);
	for(int i = 0; i < MAX_LENGTH; ++i){
		cin >> num1[i];
		num2[i] = num1[i];
	}
	intro_sort(num1, num1+MAX_LENGTH);
	heap_sort(num2, num2+MAX_LENGTH);
	cout << is_sorted(num1, num1+MAX_LENGTH) << endl;
	cout << is_sorted(num2, num2+MAX_LENGTH) << endl;
	cout << _is_same(num1, num2, MAX_LENGTH) << endl;
	// for(int i = 0; i < 10; ++i){
	// 	if(i)
	// 		cout << " ";
	// 	cout << num1[i];
	// }
	delete [] num1, num2;
	fclose(stdin);
	return 0;
}