#include "MathMethod.h"
#include "Math.h"
#include "ObjectManager.h"
#include "PD.h"
#include <algorithm>


bool MathMethod::equal(double a, double b, double speed){
	return (fabs(a - b) <= speed / 2);
}

int MathMethod::smaller(int a, int b){
	if (a<b)
		return a;
	else
		return b;
}

int MathMethod::bigger(int a, int b){
	if (a>b)
		return a;
	else
		return b;
}

bool MathMethod::isInField(double x1, double y1, double x2, double y2, double radio){
	return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= radio*radio);
}

double MathMethod::getDistance(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}


double MathMethod::getBevel(double x, double y) {
	return sqrt(x*x + y*y);
}

/**
* 得到两点之间的弧度
* @param px1    第一个点的X坐标
* @param py1    第一个点的Y坐标
* @param px2    第二个点的X坐标
* @param py2    第二个点的Y坐标
* @return
*/

double MathMethod::getRad(double px1, double py1, double px2, double py2) {
	//得到两点X的距离  
	double x = px2 - px1;
	//得到两点Y的距离  
	double y = py2 - py1;
	//算出斜边长  
	double Hypotenuse = (double)sqrt(pow(x, 2) + pow(y, 2));
	//得到这个角度的余弦值（通过三角函数中的定理 ：邻边/斜边=角度余弦值）  
	double cosAngle = x / Hypotenuse;
	//通过反余弦定理获取到其角度的弧度  
	double rad = (double)acos(cosAngle);
	//当触屏的位置Y坐标<摇杆的Y坐标我们要取反值-0~-180  
	if (py2 < py1) {
		rad = -rad;
	}
	return rad;
	/*double angle=90-pitoarc(rad);
	if(angle>180)
	angle-=360;
	return angle;*/
}

double MathMethod::getAngle(double px1, double py1, double px2, double py2) {

	return rad2Angle(getRad(px1, py1, px2, py2));
}


double MathMethod::getRad(double px1, double py1, double px2, double py2, double bevel) {
	//得到两点X的距离  
	double x = px2 - px1;
	//得到两点Y的距离  
	double y = py2 - py1;
	//算出斜边长  
	//double Hypotenuse = (double) Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
	//得到这个角度的余弦值（通过三角函数中的定理 ：邻边/斜边=角度余弦值）  
	double cosAngle = x / bevel;
	//通过反余弦定理获取到其角度的弧度  
	double rad = (double)acos(cosAngle);
	//当触屏的位置Y坐标<摇杆的Y坐标我们要取反值-0~-180  
	if (py2 < py1) {
		rad = -rad;
	}
	return rad;
}

double MathMethod::getAngle(double px1, double py1, double px2, double py2, double bevel) {

	return rad2Angle(getRad(px1, py1, px2, py2, bevel));
}


double MathMethod::angle2Rad(double a){
	return a / 180 * M_PI;
}

double MathMethod::rad2Angle(double a){
	return a / M_PI * 180;
}

double MathMethod::getWidth(char* bmp, double height){
	CCSprite* sprite = CCSprite::create(bmp);
	double bmp_width = sprite->getTextureRect().getMaxX();
	double bmp_height = sprite->getTextureRect().getMaxY();
	return bmp_width / bmp_height*height;
}

double MathMethod::getHeight(char* bmp, double width){
	CCSprite* sprite = CCSprite::create(bmp);
	double bmp_width = sprite->getTextureRect().getMaxX();
	double bmp_height = sprite->getTextureRect().getMaxY();
	return bmp_height / bmp_width *width;
}


double MathMethod::getWidth(CCTexture2D* texture, double height){
	return texture->getContentSize().width / texture->getContentSize().height * height;
}
double MathMethod::getHeight(CCTexture2D* texture, double width){
	return texture->getContentSize().height / texture->getContentSize().width * width;
}

double MathMethod::width_div_height(CCTexture2D* texture){
	return texture->getContentSize().width / texture->getContentSize().height;
}
double MathMethod::height_div_width(CCTexture2D* texture){
	return texture->getContentSize().height / texture->getContentSize().width;
}

bool MathMethod::pointInRect(CCPoint point, double x, double y, double width, double height){
	return (point.x >= x&&point.x <= x + width&&
		point.y >= y&&point.y <= y + height);
}

vector<MyPoint>* MathMethod::clonePath(vector<MyPoint>* path){
	if (path == NULL)
		return NULL;

	vector<MyPoint>* new_path = new vector<MyPoint>();

	for (int i = 0; i < path->size(); i++){
		new_path->push_back(path->at(i));
	}

	return new_path;
}

void MathMethod::releaseSprite(MySprite* &sprite){
	if (sprite != NULL){
		PD::gs->removeChild(sprite);

		PD::om->sprite->erase(remove(PD::om->sprite->begin(), PD::om->sprite->end(), sprite), PD::om->sprite->end());

		delete sprite;
		sprite = NULL;
	}
}

void MathMethod::releaseRectangle(MyRectangle* &rectangle){
	if (rectangle != NULL){
		PD::gs->removeChild(rectangle);
		PD::om->rectangle->erase(remove(PD::om->rectangle->begin(), PD::om->rectangle->end(), rectangle), PD::om->rectangle->end());
		delete rectangle;
		rectangle = NULL;
	}
}

void MathMethod::releasePath(vector<MyPoint>* &path){
	if (path != NULL){
		path->clear();
		delete path;
		path = NULL;
	}
}

bool MathMethod::stringStartWith(char *str1, char *str2){
	for (int i = 0; str2[i] != '\0'; i++){
		if (str1[i] == '\0' || str1[i] != str2[i])
			return false;
	}
	return true;
}


double MathMethod::amendTowerAngle(double angle){
	double new_angle = 90 - angle;
	if (new_angle>180)
		new_angle -= 360;
	return new_angle;
}

double MathMethod::amendBulletAngle(double angle){
	double new_angle = 90 + angle;
	if (new_angle<0)
		new_angle += 360;
	return new_angle;
}

int MathMethod::angle2TowerId(double angle){
	double new_angle = angle + 90 + 11.25 / 2;
	if (new_angle<0)
		new_angle += 360;

	return (int)(new_angle / 11.25) + 1;
}

int MathMethod::angle2SmokeRocketId(double angle){
	double new_angle = 90 - angle + 11.25 / 2;
	if (new_angle<0)
		new_angle += 360;
	return (int)(new_angle / 11.25);
}

int MathMethod::angle2BulletId(double angle){
	double new_angle = 90 + angle;
	if (new_angle<0)
		new_angle += 360;

	return (int)(new_angle / 11.25);
}


CCPoint MathMethod::convertTouchPointToTruePoint(CCPoint point){
	if (PD::cm->rate == 1)
		return ccp(point.x, point.y);
	else
		return ccp(point.x / PD::cm->rate + PD::cm->scrx
			, point.y / PD::cm->rate + PD::cm->scry);
}