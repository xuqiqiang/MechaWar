#ifndef __MathMethod_H__
#define __MathMethod_H__

#include "cocos2d.h"
USING_NS_CC;

#include "MyPoint.h"
#include "MyRectangle.h"
#include "MySprite.h"
#include<vector>
using namespace std;

class MathMethod
{
public:

	static bool equal(double a, double b, double speed);
	static int smaller(int a, int b);
	static int bigger(int a, int b);
	static bool isInField(double x1, double y1, double x2, double y2, double radio);
	static double getDistance(double x1, double y1, double x2, double y2);
	static double getBevel(double x, double y);
	static double getRad(double px1, double py1, double px2, double py2);
	static double getAngle(double px1, double py1, double px2, double py2);
	static double getRad(double px1, double py1, double px2, double py2, double bevel);
	static double getAngle(double px1, double py1, double px2, double py2, double bevel);
	static double angle2Rad(double a);
	static double rad2Angle(double a);

	static double getWidth(char* bmp, double height);
	static double getHeight(char* bmp, double width);

	static double getWidth(CCTexture2D* texture, double height);
	static double getHeight(CCTexture2D* texture, double width);

	static double width_div_height(CCTexture2D* texture);
	static double height_div_width(CCTexture2D* texture);

	static bool pointInRect(CCPoint point, double x, double y, double width, double height);

	static vector<MyPoint>* clonePath(vector<MyPoint>* path);

	static void releaseSprite(MySprite* &sprite);

	static void releaseRectangle(MyRectangle* &rectangle);

	static void releasePath(vector<MyPoint>* &path);

	static bool stringStartWith(char *str1, char *str2);

	static double amendTowerAngle(double angle);

	static double amendBulletAngle(double angle);

	static int angle2TowerId(double angle);

	static int angle2SmokeRocketId(double angle);

	static int angle2BulletId(double angle);

	static CCPoint convertTouchPointToTruePoint(CCPoint point);
};

#endif // __HELLOWORLD_SCENE_H__
