#include <iostream>
#include "min_stack.h"

using namespace std;

int main(){
	min_stack<int> r;
	int n;
	while(cin >> n)
		r.push(n);
	cout << r.top() << " " << r.min() << endl;
	r.pop();
	r.pop();
	r.push(-3);
	cout << r.top() << " " << r.min() << endl;
	return 0;
}