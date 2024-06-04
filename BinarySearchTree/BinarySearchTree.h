//BinarySearchTree.h
#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__


#include "BinaryTree.h"
using namespace std;

class KeyException{
};


/** Node element. The tree will be templated to this element. */
template <typename K, typename V> // Key and Value types
class Entry {
public:							// Just to keep everything standard
  typedef K Key;
  typedef V Value;
public:
  /** Default constructor */
  Entry (const K& k = K(), const V& v = V())
	: _key(k), _value(v) {}
  const K& key() { return _key; } /**< Key getter @returns K(key) */
  const V& value() { return _value; } /**< Value getter @returns V(value) */
  void key(const K& k) { _key = k; } /**< Key setter \param[in] K(key) */
  void value(const V& v) { _value = v; } /**< Value setter \param[in] V(value)*/
private:
  K _key;
  V _value;
};


template <typename E>
class BinarySearchTree {
public: // Avoiding tons of template params, just use the ones declared in Entry
  typedef typename E::Key K;
  typedef typename E::Value V;
  class Iterator;
public:
  BinarySearchTree();			// Constructor
  int size() const { return T.size(); };   // Size much?
  bool empty() const;			// Have much???
  Iterator find (const K& k);	// Find by key
  Iterator insert(const K& k, const V& v); // Insert a key-value pair
  void erase (const K& k) throw (KeyException); // Remove by key
  void erase (const Iterator& p);					  // Remove by position
  Iterator begin();									  // First entry
  Iterator end();	
  void printnodes();								  // Last entry
protected:
  typedef typename BinaryTree<E>::Position TPos; // position in the tree
  TPos root() const;						  // get !virtual! root utility
  TPos finder(const K& k, const TPos& tp);	  // find utility
  TPos inserter (const K& k, const V& v);	  // inserter utility
  TPos eraser (TPos& v);					  // erase utility
  TPos restructure(const TPos& tp)			  // restructure the tree
	throw (KeyException);
private:
  BinaryTree<E> T;					// The tree of values
  int n; 						// numbe rof elements
public:
  /** Iterator class */
  class Iterator {
  private:
	TPos tp;					// which entry?
  public:
	Iterator(const TPos& tpp) : tp(tpp) {}
	//const E& operator*() const { return *tp; } // Dereference (read only)
	E& operator*() { return *tp; }			  // Dereference (read/write)
	bool operator==(const Iterator& p) const  // Comparison
	{ return tp == p.tp; }
	Iterator& operator++();		// inorder successor
	friend class BinarySearchTree; // need access
  };
};



template <typename E>
typename BinarySearchTree<E>::Iterator& BinarySearchTree<E>::Iterator::operator++() {
  TPos w = tp.right();
  if (w.isInternal()) {
	do { tp = w; w = w.left(); }
	while (w.isInternal());
  } else {
	w = tp.parent();
	while (tp == w.right()) { tp = w; w = w.parent(); }
	tp = w;
  }
  return *this;	
}


template <typename E>
BinarySearchTree<E>::BinarySearchTree() : T(), n(0) {
  T.addRoot();
  T.expandExternal(T.root());
}


template <typename E>
typename BinarySearchTree<E>::TPos BinarySearchTree<E>::root() const {
  return T.root().left();
}


template <typename E>
typename BinarySearchTree<E>::Iterator BinarySearchTree<E>::begin() {
  TPos v = root();				// Start at virtual root
  while (v.isInternal()) v = v.left(); // Find leftmost node
  return Iterator(v.parent());
}


template <typename E>
typename BinarySearchTree<E>::Iterator BinarySearchTree<E>::end() { return Iterator(T.root()); }


template <typename E>
typename BinarySearchTree<E>::TPos BinarySearchTree<E>::finder(const K& k, const TPos& v) {
  //cout << (*v).key() <<"!!!"<< endl;
  if (v.isExternal()) return v;	// key not found
  if(k < (*v).key()) return finder(k, v.left()); // search the left subtree
  else if ((*v).key() < k) return finder(k, v.right()); // search the right tree
  else return v;				// Found it buddy!
}


template <typename E>
typename BinarySearchTree<E>::Iterator BinarySearchTree<E>::find(const K& k) {
  TPos v = finder(k, root());	// search from virtual root
  if (v.isInternal()) return Iterator(v); // found it
  else return end();					  // woops, there is nothing
}


template <typename E>
typename BinarySearchTree<E>::TPos BinarySearchTree<E>::inserter (const K& k, const V& x) {
  TPos v = finder(k, root());	// search from virtual root
  while (v.isInternal())		// key already there?
	v = finder (k, v.right());
  T.expandExternal(v);			// add new internal node
  (*v).key(k); 
  (*v).value(x);			// set entry
  n++;							// there are more entries now
  return v;						// return the position
}


template <typename E>
typename BinarySearchTree<E>::Iterator BinarySearchTree<E>::insert(const K& k, const V& x) {
  TPos v = inserter(k, x);
  return Iterator(v);
}


template <typename E>
typename BinarySearchTree<E>::TPos BinarySearchTree<E>::eraser(TPos& v) {
  TPos w;
  if (v.left().isExternal()) w = v.left(); // remove from left
  else if (v.right().isExternal()) w = v.right(); // remove from right
  else {										  // both internal?
	w = v.right();								  // go to the right tree
	do { w = w.left(); } while (w.isInternal());  // get leftmost node
	TPos u = w.parent();
	(*v).key((*u).key()); 
        (*v).value((*u).value()); // copy w's parent to v
  }
  n--;							// one less entry
  return T.removeAboveExternal(w); // remove w and parent
}


template <typename E>
void BinarySearchTree<E>::erase(const K& k) throw (KeyException) {
  TPos v = finder(k, root());	// search from virtual root
  if (v.isExternal())			// not found?
	throw KeyException();
  eraser(v);					// remove it
}


template <typename E>
void BinarySearchTree<E>::erase(const Iterator& p) { eraser(p.v); } // erase at p


template <typename E>
void BinarySearchTree<E>::printnodes() { 
	typename BinaryTree<E>::PositionList pl = T.positions();
	for(typename BinaryTree<E>::PositionList::iterator i = pl.begin(); i != pl.end(); i++){
		TPos tt = *i;
		if ((*tt).key() != 0 && (*tt).value() != 0) 
			cout << (*tt).key() << " " << (*tt).value() << endl;
	}	

} 

#endif
