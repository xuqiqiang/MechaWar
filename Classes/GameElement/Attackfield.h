#ifndef __Attackfield_H__
#define __Attackfield_H__


#include "PD.h"
#include "MySprite.h"
#include "Tower.h"

class Attackfield
{
private:
	int i, j;
	double x, y;
	double field;
	double angle;
	static const double rotate_speed;
	bool visible;
	MySprite *sprite, *sprite_button;
	CCLabelTTF* label_money;
public:
	Tower *tower;
	Attackfield();
	//Attackfield(double field);
	void setPosition(int i, int j);
	void setField(double field);

	void setVisible(bool visible);

	void setTower(Tower *tower);

	bool getVisible();
	//void show();

	void logic();
};

#endif