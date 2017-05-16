#ifndef __Wall_H__
#define __Wall_H__


#include "PD.h"
#include "MySprite.h"


class Wall
{
public:

	MySprite *sprite;
	MySprite *sprite_shadow;

	Wall(int i, int j, int type);

	int i, j, type;

	void show();
};

#endif