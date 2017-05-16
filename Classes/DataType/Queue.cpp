#include "Queue.h"


Queue::Queue(){
	//point = vector<Point>();
}

bool Queue::isEmpty(){
	return (point.size() == 0);
}

void Queue::enter(MyPoint p){
	point.push_back(p);
}

MyPoint Queue::out(){
	if (isEmpty())
		return Point_null;
	MyPoint p = point.at(0);
	point.erase(point.begin());// remove(0);
	return p;
}