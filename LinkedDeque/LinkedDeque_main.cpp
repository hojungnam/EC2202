// LinkedDeque_main.cpp
#include <iostream>
#include "LinkedDeque.h"

using namespace std;

int main() {

	LinkedDeque ldq;
	ldq.insertFront("3");
	ldq.insertFront("5");

	cout << ldq.front() << endl;

	ldq.removeFront();
	ldq.insertBack("7");
	
	cout << ldq.front() << endl;
	cout << ldq.back() << endl;

	return 0;
}
