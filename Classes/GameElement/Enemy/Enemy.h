#ifndef __Enemy_H__
#define __Enemy_H__

#include "PD.h"
#include "Timer.h"

class Enemy
{
private:
	static const int speed_recover_time = 1000;
	Timer *speed_recover_timer;
protected:
	int direct;
	double speed;
	double speed_max;
	double blood, blood_max;
	bool ispress;
	
	virtual void move();
	virtual void arrive();
	
public:
	char class_name[30];

	bool visible;

	double x, y, width, height;

	static double advice_speed;

	

	static void initData(){
		advice_speed = 12 * PD::H / 4.0f;
	}

	//static bool have;
	Enemy();

	virtual void show();

	virtual void logic();

	void slowDown();

	virtual void onTouch(CCPoint touch_point, int touch_event);

	virtual void attacted(double destoy);

	virtual void setVisible(bool visible);

	virtual void release();
	
};

#endif