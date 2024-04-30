// LinkedBinaryTree.cpp
#include "LinkedBinaryTree.h"
#include <iostream>

using namespace std;

typedef int Elem;

LinkedBinaryTree::LinkedBinaryTree()			// constructor
: _root(NULL), n(0) { }

int LinkedBinaryTree::size() const			// number of nodes
{ return n; }

bool LinkedBinaryTree::empty() const			// is tree empty?
{ return size() == 0; }

LinkedBinaryTree::Position LinkedBinaryTree::root() const // get the root
{ return Position(_root); }

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
        PositionList pl;
        preorder(_root, pl);
        return pl;
}

void LinkedBinaryTree::addRoot(Elem e)			// add root to empty tree
{ _root = new Node(e); n = 1; }

void LinkedBinaryTree::expandExternal(const Position &p, Elem left_e, Elem right_e) { // expand external node
	Node* v = p.v;
	v->left = new Node(left_e);
	v->left->par = v;
	v->right = new Node(right_e);
	v->right->par = v;
	n += 2;
}

LinkedBinaryTree::Position 
LinkedBinaryTree::removeAboveExternal(const Position& p) { // remove p and parent
	Node* w = p.v;Node* v = w->par;			// get p's node and parent
	Node* sib = (w == v->left ?v->right : v->left);
	if (v == _root) {					// child of root?
		_root = sib;					// ...make sibling root
		sib->par = NULL;
	}
	else {
		Node* gpar = v->par;				// w's grandparent
		if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
		else gpar->right = sib;
		sib->par = gpar;
	}
	delete w; delete v;					// delete removed nodes
	n -= 2;						// two fewer nodes
	return Position(sib);
}


void LinkedBinaryTree::preorder(LinkedBinaryTree::Node *v, LinkedBinaryTree::PositionList &pl) const {
	pl.push_back(Position(v));
	if (v->left != NULL)
		preorder(v->left, pl);
	if (v->right != NULL)
		preorder(v->right, pl);
}

