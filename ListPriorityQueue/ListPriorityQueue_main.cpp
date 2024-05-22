//ListPriorityQueue_main.cpp
#include <iostream>
#include <list>
#include "ListPriorityQueue.h"

using namespace std;

int main() {

    ListPriorityQueue<Point2D, LeftRight> points;
    points.insert(Point2D(1.1, 2.2));
    points.insert(Point2D(6.1, 4.3));
    points.insert(Point2D(1.1, 5.1));
    cout << points.size() << endl;
    while (!points.isEmpty())
    {
        Point2D p = points.min();
        cout << "X = " << p.getX() << ", Y = " << p.getY() << endl;
        points.removeMin();
    }
	return 0;
}
