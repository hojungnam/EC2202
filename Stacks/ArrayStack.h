// ArrayStack.h
#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include <stdexcept>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E>
class ArrayStack {
	enum { DEF_CAPACITY = 100 };		// default stack capacity
public:
	ArrayStack(int cap = DEF_CAPACITY);		// constructor from capacity
	int size() const;				// number of items in the stack
	bool empty() const;				// is the stack empty?
	const E& top() const throw(std::out_of_range);	// get the top element
	void push(const E& e) throw(std::out_of_range);	// push element onto stack
	void pop() throw(std::out_of_range);		// pop the stack
	// ...housekeeping functions omitted
private:	// member data
	E* S;					// array of stack elements
	int capacity;				// stack capacity
	int t;					// index of the top of the stack
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
: S(new E[cap]), capacity(cap), t(-1) { }       // constructor from capacity

template <typename E> int ArrayStack<E>::size() const
{ return (t + 1); }                             // number of items in the stack

template <typename E> bool ArrayStack<E>::empty() const
{ 
	//cout << t << endl;	
	return (t < 0); }                             // is the stack empty?

template <typename E>                           // return top of stack
const E& ArrayStack<E>::top() const throw(std::out_of_range) {
        try {
		if (empty()) {
			 throw std::out_of_range("Top of empty stack");
		}
	} catch (std::out_of_range &e) {
		cout << e.what() << endl;
	}
        return S[t];
}

template <typename E>                           // push element onto the stack
void ArrayStack<E>::push(const E& e) throw(std::out_of_range) {
        if (size() == capacity) throw std::out_of_range("Push to full stack");
                S[++t] = e;
}

template <typename E>                           // pop the stack
void ArrayStack<E>::pop() throw(std::out_of_range) {
        if (empty()) throw std::out_of_range("Pop from empty stack");
                --t;
}


#endif
