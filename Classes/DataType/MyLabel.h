#ifndef __MyLabel_H__
#define __MyLabel_H__

#include "cocos2d.h"
USING_NS_CC;
class MyLabel
{
private:
protected:
public:

	static CCLabelTTF* getLabel(double size, const char* font);
	static CCLabelTTF* getLabel(const char* text, double x, double y, double size, const char* font);
	static CCLabelTTF* getLabel(int number, double x, double y, double size, const char* font);

	static void setXY(CCLabelTTF* label, double x, double y);

	static void setNumber(CCLabelTTF* label, int number);

};

#endif