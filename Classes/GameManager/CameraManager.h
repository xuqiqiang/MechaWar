#ifndef __CameraManager_H__
#define __CameraManager_H__


#include "cocos2d.h"
USING_NS_CC;

class CameraManager
{
private:
	bool isfirst, ismove;
	double x3, y3, x4, y4;
protected:
public:

	double scrx, scry, scrw, scrh, oldscrx,
		oldscry, oldX, oldY, rate, oldrate, oldline, newline;

	CameraManager();

	void onTouch(CCSet *pTouches, int touch_event);
};

#endif