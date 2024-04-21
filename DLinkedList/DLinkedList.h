// DLinkedList.h
#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

#include <string>

using namespace std;

typedef string Elem;				// list element type
class DNode {					// doubly linked list node
private:
	Elem elem;					// node element value
	DNode* prev;				// previous node in list
	DNode* next;				// next node in list
friend class DLinkedList;			// allow DLinkedList access
};

class DLinkedList {				// doubly linked list
public:
	DLinkedList();				// constructor
	~DLinkedList();				// destructor
	bool empty() const;				// is list empty?
	const Elem& front() const;			// get front element
	const Elem& back() const;			// get back element
	void addFront(const Elem& e);		// add to front of list
	void addBack(const Elem& e);		// add to back of list
	void removeFront();				// remove from front
	void removeBack();				// remove from back
	void printList();
private:					// local type definitions
	DNode* header;				// list sentinels
	DNode* trailer;
protected:					// local utilities
	void add(DNode* v, const Elem& e);		// insert new node before v
	void remove(DNode* v);			// remove node v
};

#endif
