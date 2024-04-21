// DLinkedList_main.cpp
#include <iostream>
#include "DLinkedList.h"


int main() {

	DLinkedList dll;
	dll.addFront("SFO");
	dll.printList();
	dll.addFront("PVD");
	dll.printList();
	dll.addFront("JFK");
	dll.printList();
	
	return 0;
}
