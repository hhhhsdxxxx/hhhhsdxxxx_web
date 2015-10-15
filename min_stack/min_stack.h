#ifndef _MIN_STACK_H_
#define _MIN_STACK_H_

#include <stack>

template<typename T>
class min_stack{
	std::stack<T> m_stack, m_min_stack;
public:
	void push(const T&);
	void pop();
	const size_t size() const { return m_stack.size(); }
	bool empty() const { return m_stack.empty(); }
	const T& min() const;
	const T& top() const;
};

template<typename T>
void min_stack<T>::push(const T& m){
	m_stack.push(m);
	if(m_min_stack.empty() || m <= m_min_stack.top())
		m_min_stack.push(m);
}

template<typename T>
void min_stack<T>::pop(){
	if(size()){
		if(m_min_stack.top() == m_stack.top())
			m_min_stack.pop();
		m_stack.pop();
	}
}

template<typename T>
const T& min_stack<T>::min() const {
	assert(m_min_stack.size() > 0);
	assert(size() > 0);
	return m_min_stack.top();
}

template<typename T>
const T& min_stack<T>::top() const {
	assert(m_min_stack.size() > 0);
	assert(size() > 0);
	return m_stack.top();
}

#endif