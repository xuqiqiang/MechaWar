#ifndef __SpriteManager_H__
#define __SpriteManager_H__

#include "cocos2d.h"
USING_NS_CC;

class SpriteManager
{
public:

	static CCSprite* newSprite(CCTexture2D* texture, double x, double y, double width, double height);

	static CCSprite* newSprite_frame(CCTexture2D* texture, int frame, double x, double y, double width, double height);

	static CCSprite* newSprite_transparent(CCTexture2D* texture, double x, double y, double width, double height, int opacity);

	static CCSprite* newSprite_rotate(CCTexture2D* texture, double x, double y, double width, double height, double angle);
	//////////////////////

	static CCSprite* newSprite(const char* bmp, double x,double y, double width, double height);

	static CCSprite* newSprite_transparent(const char* bmp, double x, double y, double width, double height, int opacity);

	static CCSprite* newSprite_rotate(const char* bmp, double x, double y, double width, double height, double angle);

	static void setSize(CCSprite* pSprite, double width, double height);

	static void setPosition(CCSprite* pSprite, CCPoint point);

	static void setRotation(CCSprite* pSprite, double angle);

	static double width_div_height(CCTexture2D* texture);
	static double height_div_width(CCTexture2D* texture);

	static cocos2d::CCLabelTTF* newLabel(const char* text, double x, double y, double size, const char* font);
	
};

#endif // __HELLOWORLD_SCENE_H__
