#ifndef __Bullet_H__
#define __Bullet_H__

#include "PD.h"
#include "Enemy.h"
#include "MySprite.h"
#include "Timer.h"

class Bullet
{
private:
	double x, y;
	//double width,height;
	double size;
	int type;
	//Timer *timer;
	Enemy *target;// = null;
	double angle;
	double speed;
	double speed_add;
	double speed_max;
	double destoy;
	MySprite *sprite;
protected:

public:

	bool visible;

	static const int TYPE_RED = 0, TYPE_BLUE = 1;
	static double SPEED;

	static void initData(){
		SPEED = 17 * PD::H / 8.0f;
	}

	Bullet(int i, int j, double angle, double destoy, int type, Enemy *target);

	bool gooff();

	void setVisible(bool visible);

	virtual void release();
	
};

#endif