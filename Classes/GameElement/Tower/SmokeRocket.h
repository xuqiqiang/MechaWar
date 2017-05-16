#ifndef __SmokeRocket_H__
#define __SmokeRocket_H__

#include "PD.h"
#include "Rocket.h"

class SmokeRocket : public Rocket
{
private:
protected:

public:


	SmokeRocket(int i, int j);

	virtual void changeAngle();

	virtual void fireBullet();

	virtual void promote();

};

#endif