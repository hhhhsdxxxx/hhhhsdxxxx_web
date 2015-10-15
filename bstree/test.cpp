#include <iostream>
#include "bstree.h"

using namespace std;

int main(){
	bstree<int> tree;
	cout << "size: " << tree.size() << endl;
	int k, m = 100000;
	freopen("data.txt", "r", stdin);
	while((cin >> k) && m--)
		tree.insert(k);
	tree.get_height();
	// cout << "size: " << tree.size() << endl;	
	// tree.level_print();
	// while((cin >> k) && k != -1){
	// 	tree.erase(k);
	// 	tree.level_print();
	// }
	// cout << "size: " << tree.size() << endl;	
	// tree.level_print();
	fclose(stdin);
	puts("finish");
	return 0;
}