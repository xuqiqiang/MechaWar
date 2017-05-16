#ifndef __ShootFire_H__
#define __ShootFire_H__

#include "PD.h"
#include "Timer.h"
#include "MySprite.h"
#include "Enemy.h"

class ShootFire
{
private:
	int i, j;
	double size;
	bool visible;
	Timer *timer;
	static const int shoot_time = 60;
	double angle;
	MySprite *sprite;
public:
	ShootFire(int i, int j);

	void shoot(Enemy *target, double angle, double destoy);
	
	void setVisible(bool visible);

	virtual void release();
};



#endif
