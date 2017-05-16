#ifndef __Pillbox_H__
#define __Pillbox_H__

#include "PD.h"
#include "Tower.h"
#include "ShootFire.h"
#include "MySprite.h"
class Pillbox : public Tower
{
private:
	//bool isTargetFar();

	ShootFire *sf;

	MySprite *sprite;
protected:


	//bool findTarget();
public:

	virtual void shoot();

	virtual void promote();
	
	Pillbox(int i, int j);

	virtual void setVisible(bool visible);

	virtual void release();
};

#endif