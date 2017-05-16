#ifndef __MainTarget_H__
#define __MainTarget_H__


#include "PD.h"
#include "MySprite.h"
#include "Enemy.h"
#include "Timer.h"

class MainTarget
{
private:
	//double x, y;
	double width, height;

	bool visible;

	int field_direct;
	double field;
	static double field_min;
	static double field_max;
	static double field_speed;

	MySprite *sprite[4];

	static int show_time;
	Timer *timer;
public:

	static void initData(){
		field_min = PD::lengthX*0.05;
		field_max = PD::lengthX*0.15;
		field_speed = PD::H / 8.0f;
		show_time = 2000;
	}

	Enemy *target;

	MainTarget();

	void logic();

	void setTarget(Enemy *target);

	void setVisible(bool visible);
	
};

#endif