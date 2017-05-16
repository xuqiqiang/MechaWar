#ifndef __Flyer_H__
#define __Flyer_H__

#include "PD.h"
#include "Enemy.h"
#include "MySprite.h"
class Flyer : public Enemy
{
private:
	static const int sprite_sum = 5;
	MySprite *sprite[sprite_sum];
protected:
	virtual void onMoveSprite();
public:

	Flyer(int direct);
	Flyer(int direct, bool child);

	virtual void logic();

	virtual void setVisible(bool visible);

};

#endif