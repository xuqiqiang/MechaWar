#include "Wall.h"
#include "SpriteManager.h"
#include "MySprite.h"
#include "ObjectManager.h"

Wall::Wall(int i, int j, int type){
	this->i = i;
	this->j = j;
	this->type = type;
}

void Wall::show(){
	/*char* house_bmp = "house1.png";
	switch (type){
	case 0:house_bmp = "house1.png"; break;
	case 1:house_bmp = "house2.png"; break;
	case 2:house_bmp = "house3.png"; break;
	case 3:house_bmp = "house4.png"; break;
	}

	char* house_shadow_bmp = "houseshadow1.png";
	switch (type){
	case 0:house_shadow_bmp = "houseshadow1.png"; break;
	case 1:house_shadow_bmp = "houseshadow2.png"; break;
	case 2:house_shadow_bmp = "houseshadow3.png"; break;
	case 3:house_shadow_bmp = "houseshadow4.png"; break;
	}*/

	int house_size[4] = {1, 3, 2, 2};

	sprite = new MySprite(PD::resm->house[type], j*PD::lengthW, i*PD::lengthH, 0, PD::lengthH*house_size[type], true);
	sprite_shadow = new MySprite(PD::resm->house_shadow[type], j*PD::lengthW, i*PD::lengthH, 0, PD::lengthH*house_size[type], true);
	sprite_shadow->setOpacity(150);
	PD::gs->addChild(sprite, 2);
	PD::gs->addChild(sprite_shadow, 2);

	PD::om->sprite->push_back(sprite);
	PD::om->sprite->push_back(sprite_shadow);
}