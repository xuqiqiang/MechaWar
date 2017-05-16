#ifndef __Queue_H__
#define __Queue_H__

#include "MyPoint.h"
#include<vector>
using namespace std;


class Queue
{
public:
	Queue();
	vector<MyPoint> point;// = NULL;

	bool isEmpty();

	void enter(MyPoint p);
	MyPoint out();
};

#endif