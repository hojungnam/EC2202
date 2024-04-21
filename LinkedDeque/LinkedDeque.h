// LinkedDeque.h

#ifndef LINKEDDEQUE_H_
#define LINKEDDEQUE_H_
#include "DLinkedList.h"
#include <stdexcept>


typedef string Elem;				// deque element type

class LinkedDeque {				// deque as doubly linked list
public:
	LinkedDeque();				// constructor
	int size() const;				// number of items in the deque
	bool empty() const;				// is the deque empty?
	const Elem& front() const throw(std::out_of_range); // the first element
	const Elem& back() const throw(std::out_of_range);	// the last element
	void insertFront(const Elem& e);		// insert new first element
	void insertBack(const Elem& e);		// insert new last element
	void removeFront() throw(out_of_range);	// remove first element
	void removeBack() throw(out_of_range);	// remove last element
private:					// member data
	DLinkedList D;				// linked list of elements
	int n;					// number of elements
};

#endif

