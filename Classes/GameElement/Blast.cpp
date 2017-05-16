#include "Blast.h"
#include "MathMethod.h"
#include "ObjectManager.h"



int Blast::frame_sum[Blast::type_sum];

Blast::Blast(double x, double y, double size, int type, int zOrder){
	this->x = x;
	this->y = y;
	this->size = size;
	this->type = type;
	visible = true;
	frame = -1;

	if (type == 0 || type == 1){
		sprite = new MySprite(PD::resm->bomb[type][0], x, y, size, size, true);
	}
	else if (type == 2){
		sprite = new MySprite(PD::resm->explosion2, 0, x, y, size, size, true);
	}
	else if (type == 3){
		sprite = new MySprite(PD::resm->explosion1, 0, x, y, size, size, true);
	}
	
	PD::gs->addChild(sprite, zOrder);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);
}

bool Blast::play(){
	if (visible){
		frame++;
		if (frame>=frame_sum[type]){
			//visible = false;
			//spirit = null;
			setVisible(false);
			return false;
		}

		if (type == 0 || type == 1){
			sprite->setTexture(PD::resm->bomb[type][frame]);
		}
		else if (type == 2 || type == 3){
			sprite->setFrame(frame);
		}

		return true;
	}

	return false;
}

void Blast::setVisible(bool visible){
	this->visible = visible;
	sprite->setVisible(visible);
}


void Blast::release(){

	MathMethod::releaseSprite(sprite);

	

	delete this;
}