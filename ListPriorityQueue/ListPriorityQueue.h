//ListPriorityQueue.h
#ifndef __LISTPRIORITYQUEUE_h__
#define __LISTPRIORITYQUEUE_h__

#include <iostream>
#include <list>
using namespace std;

struct Point2D{
    double X;
    double Y;
    Point2D(double a, double b): X(a), Y(b) {}
    double getX() const {return X;}
    double getY() const {return Y;}
};

class LeftRight{
public:
    bool operator()(const Point2D& p, const Point2D& q)
    {
        return (p.getX() < q.getX());
    }
};

template <typename E, typename C>  // E is element type and C is comparator type
class ListPriorityQueue{
public:
    int size() const;   // returns no of elements in Priority Queue
    bool isEmpty() const;  // returns true if queue is empty
    void insert(const E& e);   // insert e into queue while keeping it sorted
    const E& min() const;  // return a reference to the
                                             // element with the smallest key
    void removeMin();   // remove the element returned by min
private:
    list<E> L;   
    C isLess;    // comparator object which defines a total order relation and
};

template <typename E, typename C>
int ListPriorityQueue<E,C>::size() const {
    return L.size();
}

template <typename E, typename C>
bool ListPriorityQueue<E,C>::isEmpty() const {
    return L.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E,C>::insert(const E& e) {
    typename list<E>::iterator p;
    p = L.begin();
    while (p != L.end() && !isLess(e, *p))
        p++;
    L.insert(p, e);
}

template <typename E, typename C>
const E& ListPriorityQueue<E,C>::min() const {
    return L.front();
}

template <typename E, typename C>
void ListPriorityQueue<E,C>::removeMin() {
    L.pop_front();
}
#endif
