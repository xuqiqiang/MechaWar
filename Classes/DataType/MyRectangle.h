#ifndef __MYRECTANGLE_H__
#define __MYRECTANGLE_H__

#include "cocos2d.h"
USING_NS_CC;

class MyRectangle : public CCLayer
{
private:
	double x;
	double y;
	double width;
	double height;
	ccColor4F color;

	double view_x, view_y;
	double view_width;
	double view_height;

	bool inCamera;
	//bool visible;
public:
	MyRectangle(double x, double y, double width, double height, ccColor4F color , bool inCamera);

	void setRectPosition(double x, double y);

	void setRectSize(double width, double height);

	void setRectColor(ccColor4F color);


	virtual void draw();

	void refresh();

};



#endif // __RECTANGLE_H__
