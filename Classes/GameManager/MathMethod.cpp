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
* �õ�����֮��Ļ���
* @param px1    ��һ�����X����
* @param py1    ��һ�����Y����
* @param px2    �ڶ������X����
* @param py2    �ڶ������Y����
* @return
*/

double MathMethod::getRad(double px1, double py1, double px2, double py2) {
	//�õ�����X�ľ���  
	double x = px2 - px1;
	//�õ�����Y�ľ���  
	double y = py2 - py1;
	//���б�߳�  
	double Hypotenuse = (double)sqrt(pow(x, 2) + pow(y, 2));
	//�õ�����Ƕȵ�����ֵ��ͨ�����Ǻ����еĶ��� ���ڱ�/б��=�Ƕ�����ֵ��  
	double cosAngle = x / Hypotenuse;
	//ͨ�������Ҷ����ȡ����ǶȵĻ���  
	double rad = (double)acos(cosAngle);
	//��������λ��Y����<ҡ�˵�Y��������Ҫȡ��ֵ-0~-180  
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
	//�õ�����X�ľ���  
	double x = px2 - px1;
	//�õ�����Y�ľ���  
	double y = py2 - py1;
	//���б�߳�  
	//double Hypotenuse = (double) Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
	//�õ�����Ƕȵ�����ֵ��ͨ�����Ǻ����еĶ��� ���ڱ�/б��=�Ƕ�����ֵ��  
	double cosAngle = x / bevel;
	//ͨ�������Ҷ����ȡ����ǶȵĻ���  
	double rad = (double)acos(cosAngle);
	//��������λ��Y����<ҡ�˵�Y��������Ҫȡ��ֵ-0~-180  
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