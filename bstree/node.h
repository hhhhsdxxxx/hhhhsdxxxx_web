#ifndef _NODE_H_
#define _NODE_H_

#include <algorithm>

#define minus(x, y) ((x > y)?x-y:y-x)

template<typename T>
class node{
	template<typename T>
	friend class bstree;
	T m_key;
	size_t m_height, m_size;
	node<T> *left, *right;
	node<T> *insert(const T&);
	T* find(const T&);
	node<T> *erase(const T&);
	const T& min() const;
	T* point_min() const;
	node<T>* adjust();
	size_t get_height(node<T> *p){ if(p == NULL) return 0; else return p->m_height; }
	size_t get_size(node<T> *p){ if(p == NULL) return 0; else return p->m_size; }
	void update() { m_height = max(get_height(left)+1, get_height(right)+1); m_size = 1+get_size(left)+get_size(right); }
public:
	node():m_key(),left(NULL),right(NULL),m_size(1),m_height(1){}
	node(const T& key):m_key(key),left(NULL),right(NULL),m_size(1),m_height(1){}
};

template<typename T>
node<T>* node<T>::insert(const T& key){
	if(key < m_key){
		if(left == NULL)
			left = new node<T>(key);
		else
			left = left->insert(key);
	}
	else {
		if(right == NULL)
			right = new node<T>(key);
		else
			right = right->insert(key);
	}
	update();
	if(minus(get_height(left), get_height(right)) > 1)
		return adjust();
	return this;
}

template<typename T>
T* node<T>::find(const T& key){
	if(key == m_key)
		return this;
	else if(key < m_key && left != NULL)
		return left->find(key);
	else if(key > m_key && right != NULL)
		return right->find(key);
	return NULL;
}

template<typename T>
node<T>* node<T>::erase(const T& key){
	if(key < m_key){
		if(left == NULL)
			return this;
		else
			left = left->erase(key);
	}
	else if(key > m_key){
		if(right == NULL)
			return this;
		else
			right = right->erase(key);
	}
	else if(key == m_key){
		if(right == NULL){
			node<T> *ptr = left;
			delete this;
			return ptr;
		}
		else {
			m_key = right->min();
			//std::cout << m_key << endl;
			right = right->erase(m_key);
		}
	}
	update();
	if(minus(get_height(left), get_height(right)) > 1)
		return adjust();
	return this;
}

template<typename T>
const T& node<T>::min() const{
	if(left == NULL)
		return m_key;
	else
		return left->min();
}

template<typename T>
T* node<T>::point_min() const {
	if(left == NULL)
		return this;
	else 
		return left->point_min();
}

template<typename T>
node<T>* node<T>::adjust(){
	node<T> *re = NULL;
	if(get_height(left) > get_height(right)){
		if(get_height(left->left) > get_height(left->right)){ //RR
			re = left;
			this->left = re->right;
			re->right = this;
		}
		else {
			re = left->right;
			left->right = re->left;
			re->left = left;
			this->left = re->right;
			re->right = this;
		}
	}
	else {
		if(get_height(right->right) > get_height(right->left)){
			re = right;
			this->right = re->left;
			re->left = this;
		}
		else {
			re = right->left;
			right->left = re->right;
			re->right = right;
			this->right = re->left;
			re->left = this;
		}
	}
	re->left->update();
	re->right->update();
	re->update();
	return re;
}

#endif