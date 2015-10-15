#ifndef _BSTREE_H_
#define _BSTREE_H_


#include <queue>
#include <assert.h>
#include "node.h"

#define _TEST_

template<typename BT>
class bstree{
	node<BT> *root;
#ifdef _TEST_
	size_t __lg_height;
	void __get_height(node<BT> *p, size_t h);
	size_t __lg(size_t n){ 
		size_t k = 0;
		for(; n > 0; n >>= 1)
			++k;
		return k+2;
	}
#endif
public:
#ifndef _TEST_
	bstree():root(NULL){}
#else
	bstree():root(NULL),__lg_height(0){}
#endif
	void insert(const BT&);
	void erase(const BT&);
	BT* find(const BT&);
	size_t size() const { return root == NULL?0:root->m_size; }
	BT& min() const { return root->min(); }
#ifdef _TEST_
	void get_height(){ 
		__lg_height = __lg(size());
		__get_height(root, 0); 
	}
	void level_print();
#endif
};

template<typename BT>
void bstree<BT>::insert(const BT& key){
	if(root == NULL)
		root = new node<BT>(key);
	else
		root = root->insert(key);
}

template<typename BT>
void bstree<BT>::erase(const BT& key){
	assert(root != NULL);
	root = root->erase(key);
}

template<typename BT>
BT* bstree<BT>::find(const BT& key){
	assert(root != NULL);
	return root->find(key);
}

#ifdef _TEST_

template<typename BT>
void bstree<BT>::level_print(){
	size_t cnt = 0, line = 1;
	queue<node<BT>*> que;
	que.push(root);
	while(!que.empty()){
		node<BT> *p = que.front();
		que.pop();
		if(cnt == line){
			cnt = 0;
			puts("");
			line <<= 1;
		}
		++cnt;
		if(p == NULL)
			continue;
		cout << p->m_key << " ";
		que.push(p->left);
		que.push(p->right);
	}
	puts("");
}

template<typename BT>
void bstree<BT>::__get_height(node<BT> *p, size_t h){
	if(p == NULL){
		if(h > __lg_height)
			cout << h << endl;
		return;
	}
	__get_height(p->left, ++h);
	__get_height(p->right, h);
}

#endif

#endif