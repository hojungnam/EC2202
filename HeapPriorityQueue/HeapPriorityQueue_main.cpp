// HeapPriorityQueue_main.cpp
#include <vector>
#include <iostream>
#include "HeapPriorityQueue.h"

using namespace std;

int main() {

	HeapPriorityQueue<int, Comp> hpq;
	cout << hpq.size() << endl;

	hpq.insert(10);
	hpq.insert(9);
	hpq.insert(8);
	hpq.insert(7);
	hpq.insert(6);

	cout << hpq.min() << endl;
	return 0;
}
