// 05_StringLinkedList_main.cpp
#include <iostream>
#include "05_StringLinkedList.h"

using namespace std;

int main() {

	StringLinkedList ll;
	if(ll.empty()) cout << "linked list is empty!" << endl;
	ll.addFront("BOS");
	ll.printList();
	if(ll.empty()) cout << "linked list is empty!" << endl;
	ll.addFront("ATL");
	ll.printList();
	ll.addFront("MSP");
	ll.printList();
	ll.addFront("LAX");
	ll.printList();
	cout << ll.front() << endl;
	ll.removeFront();
	cout << ll.front() << endl;
	ll.printList();
	return 0;

}

