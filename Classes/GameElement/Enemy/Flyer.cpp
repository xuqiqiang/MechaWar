#include "Flyer.h"
#include "ObjectManager.h"


Flyer::Flyer(int direct){

	strcpy(class_name, "Enemy_Flyer");

	this->direct = direct;


	if (direct == 1){
		x = -2 * PD::lengthW;
		//y = (2 * i + 2)*PD::lengthH;
		//y=((int)(Math.random()*9)+1)*PD::lengthH;//((int)(PD::lengthH*5)+1)*PD::lengthH;

		for (int i = 0; i < sprite_sum; i++){

			sprite[i] = new MySprite(PD::resm->advice, x, (2 * i + 2)*PD::lengthH, PD::lengthW, PD::lengthH, true);
			PD::gs->addChild(sprite[i], 10);
			PD::om->sprite->push_back(sprite[i]);
			sprite[i]->setVisible(visible);
		}

	}
	else if (direct == 2){
		//x=((int)(PD::lengthW*9)+3)*PD::lengthW;
		//x = ((int)(Math.random() * 9) + 3)*PD::lengthW;
		y = -1.5*PD::lengthH - PD::lengthH * 3;

		for (int i = 0; i < sprite_sum; i++){

			sprite[i] = new MySprite(PD::resm->advice, (2 * i + 5)*PD::lengthW, y, PD::lengthW, PD::lengthH, true);
			sprite[i]->setRotation(90);
			PD::gs->addChild(sprite[i], 10);
			PD::om->sprite->push_back(sprite[i]);
			sprite[i]->setVisible(visible);
		}

	}

	speed = advice_speed;

}


Flyer::Flyer(int direct, bool child){
	strcpy(class_name, "Enemy_Flyer");

	this->direct = direct;
}

void Flyer::logic(){
	if (visible){
		move();

		onMoveSprite();

		if (direct == 1 && (int)(x / PD::lengthW) >= PD::om->map->des.j + 2 ||
			direct == 2 && (int)(y / PD::lengthH) >= PD::om->map->des.i + 2){
			//visible = false;
			arrive();
		}

	}
}

void Flyer::onMoveSprite(){
	if (direct == 1){
		for (int i = 0; i < sprite_sum; i++){
			sprite[i]->setX(x);
		}
	}
	else if (direct == 2){
		for (int i = 0; i < sprite_sum; i++){
			sprite[i]->setY(y);
		}
	}
}

void Flyer::setVisible(bool visible){
	this->visible = visible;
	for (int i = 0; i < sprite_sum; i++)
		sprite[i]->setVisible(visible);
}