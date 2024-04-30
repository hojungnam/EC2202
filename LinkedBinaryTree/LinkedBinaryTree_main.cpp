//LinkedBinaryTree_main.cpp

#include <iostream>
#include "LinkedBinaryTree.h"

using namespace std;

int main() {

	LinkedBinaryTree lbt;
	lbt.addRoot(1);
	LinkedBinaryTree::Position p = lbt.root();
	cout << *p << endl;


	lbt.expandExternal(p, 2, 3);
		
	cout << *p.left() << endl;
	cout << *p.right() << endl;

	return 0;
}
