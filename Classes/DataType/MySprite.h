#ifndef __MySprite_H__
#define __MySprite_H__

#include "cocos2d.h"
USING_NS_CC;

class MySprite : public CCSprite
{
private:
	double x, y;
	double width;
	double height;

	CCTexture2D* texture;

	double view_x, view_y;
	double view_width;
	double view_height;

	bool inCamera;
	int frame_sum;
public:
	MySprite(CCTexture2D* texture, bool inCamera);
	MySprite(CCTexture2D* texture, int frame, int frame_sum, bool inCamera);
	MySprite(CCTexture2D* texture, double x, double y, double width, double height, bool inCamera);
	MySprite(CCTexture2D* texture, int frame, double x, double y, double width, double height, bool inCamera);
	MySprite(CCTexture2D* texture, int frame, int frame_sum, double x, double y, double width, double height, bool inCamera);

	void setX(double x);
	void setY(double y);
	void setXY(double x, double y);
	void setSize(double width, double height);

	void setStatus(double x, double y, double width, double height);

	void setFrame(int frame);

	void refresh();
};



#endif // __RECTANGLE_H__
