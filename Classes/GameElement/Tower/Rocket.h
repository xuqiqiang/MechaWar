#ifndef __Rocket_H__
#define __Rocket_H__

#include "PD.h"
#include "Tower.h"
#include "MySprite.h"
#include "Timer.h"

class Rocket : public Tower
{
private:
	static const int shoot_time = 1000;
	static const int shoot_time_extra = 150;
	Timer *timer;
	Timer *timer_extra;

	
protected:

	MySprite *sprite_top;
	MySprite *sprite_bottom;

	virtual bool checkMainTarget();
	virtual bool findTarget();

public:

	
	Rocket(int i, int j);
	
	Rocket(int i, int j, bool child);

	virtual void shoot();

	virtual void changeAngle();

	virtual void fireBullet();

	virtual void promote();

	virtual void setVisible(bool visible);

	virtual void release();
};

#endif