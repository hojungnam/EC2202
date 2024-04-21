// LinkedDeque.cpp
#include <iostream>
#include <stdexcept>
#include "LinkedDeque.h"



LinkedDeque::LinkedDeque() {
	n = 0;
}

const Elem& LinkedDeque::front() const throw(out_of_range) {
	return D.front();
}

const Elem& LinkedDeque::back() const throw(out_of_range) {
        return D.back();
}

void LinkedDeque::insertFront(const Elem& e) {
	D.addFront(e);
	n++;
}
						// insert new last element
void LinkedDeque::insertBack(const Elem& e) {
	D.addBack(e);
	n++;
}
						// remove first element
void LinkedDeque::removeFront() throw(out_of_range) {
	if (empty())
		throw out_of_range("removeFront of empty deque");
	D.removeFront();
	n--;
}
						// remove last element
void LinkedDeque::removeBack() throw(out_of_range){
	if (empty())
		throw out_of_range("removeBack of empty deque");
	D.removeBack();
	n--;
}

bool LinkedDeque::empty() const{
	return (n < 1);
}
