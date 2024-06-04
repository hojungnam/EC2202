#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
  //BinarySearchTree< Entry<int,int> > t;
  BinarySearchTree< Entry<int,int> > t = BinarySearchTree< Entry<int,int> >();
  t.printnodes();
  cout << t.size() << endl;
  t.insert(5, 10);
  cout << t.size() << endl;
  t.insert(4, 10);
  cout << t.size() << endl;
  t.insert(6, 10);
  cout << t.size() << endl;
  t.insert(3, 10);
  cout << t.size() << endl;
  t.insert(7, 10);
  cout << t.size() << endl;
  
  cout<<"---"<<endl;
  t.printnodes();
  t.erase(5);
  cout << t.size() << endl;

  cout<<"---"<<endl;
  t.printnodes();
  
}
