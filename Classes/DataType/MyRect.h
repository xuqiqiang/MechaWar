#ifndef __MyRect_H__
#define __MyRect_H__
#include "cocos2d.h"
USING_NS_CC;
class MyRect : public CCRect
{
public:
	MyRect();
	MyRect(double x, double y, double width, double height);
	double x, y, width, height;
	
};

#endif