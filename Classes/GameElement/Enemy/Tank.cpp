#include "Tank.h"
#include "Enemy.h"
#include "MathMethod.h"
#include "ObjectManager.h"
#include "Blast.h"

double Tank::tank_speed[Tank::type_sum];
int Tank::direct_frame[4];
double Tank::destroy_field;

Tank::Tank(double x, double y, int type, int blood) : Runner(x, y, true){
	strcpy(class_name, "Enemy_Runner_Tank");
	this->type = type;
	this->blood = blood;
	blood_max = blood;

	speed = tank_speed[type];
	speed_max = speed;

	if (type < new_tank_id){

		sprite = new MySprite(PD::resm->tank[type][2],
			x - (MathMethod::width_div_height(PD::resm->tank[type][2]) - 1)*PD::lengthW / 2,
			y,
			MathMethod::width_div_height(PD::resm->tank[type][2])*width,
			height, true);
	}
	else if (type < 9){
		frame_sum = (int)(PD::resm->new_tank[type - new_tank_id]->getContentSize().width /
			PD::resm->new_tank[type - new_tank_id]->getContentSize().height) / 4;
		frame = 0;

		sprite = new MySprite(PD::resm->new_tank[type - new_tank_id],
			frame,
			x,
			y,
			width,
			height, true);
	}
	else if (type == 9){
		frame_sum = (int)(PD::resm->new_tank[type - new_tank_id]->getContentSize().width /
			PD::resm->new_tank[type - new_tank_id]->getContentSize().height) / 2;
		frame = 0;

		sprite = new MySprite(PD::resm->new_tank[type - new_tank_id],
			frame,
			(int)(PD::resm->new_tank[type - new_tank_id]->getContentSize().width /
			PD::resm->new_tank[type - new_tank_id]->getContentSize().height) * 2,
			x + PD::lengthW / 2,
			y,// - PD::lengthH,
			width / 2,
			height, true);
	}

	PD::gs->addChild(sprite, 1);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);


	sprite_blood = new MyRectangle(x + PD::lengthW*0.2 + 1, y - PD::lengthH*0.08 + 1,
		(PD::lengthW*0.6 - 2)*blood / blood_max, PD::lengthH*0.16 - 2, ccc4f(0.7, 0, 0, 0.7), true);
	PD::gs->addChild(sprite_blood, 3);
	PD::om->rectangle->push_back(sprite_blood);
	sprite_blood->setVisible(visible);
	
}


void Tank::onChangeDirection(){

	if (type < new_tank_id){
		sprite->setTexture(PD::resm->tank[type][direct]);
	
		double width_div_height = MathMethod::width_div_height(PD::resm->tank[type][direct]);

		if (direct == 0 || direct == 2){
			sprite->setSize(width_div_height*width, height);
		}
		else{
			sprite->setSize(width_div_height*width * 3 / 4, height * 3 / 4);
		}
	}
}

void Tank::arrive(){
	Runner::arrive();
}

void Tank::attacted(double destoy){
	Enemy::attacted(destoy);
	if (blood <= 0){
		if (type != 3)
			PD::om->blast->push_back(new Blast(x - PD::lengthW*0.15, y - PD::lengthH*0.15, PD::lengthX*1.3, 1, 2));
		else{
			PD::om->blast->push_back(new Blast(x - PD::lengthW, y - PD::lengthH, PD::lengthX * 3, 1, 2));

			for (int i = 0; i < PD::om->tower->size(); i++){
				if (PD::om->tower->at(i)->visible&&
					MathMethod::isInField(x, y,
					PD::om->tower->at(i)->j*PD::lengthW,
					PD::om->tower->at(i)->i*PD::lengthH,
					destroy_field)){
					PD::om->tower->at(i)->destroyed();
				}
			}

			for (int i = 0; i < PD::om->mine->size(); i++){
				if (PD::om->mine->at(i)->visible&&
					MathMethod::isInField(x, y,
					PD::om->mine->at(i)->j*PD::lengthW + PD::lengthW / 2,
					PD::om->mine->at(i)->i*PD::lengthH + PD::lengthH / 2,
					destroy_field)){
					PD::om->mine->at(i)->destroyed();
				}
			}
		}
	}

	sprite_blood->setRectSize((PD::lengthW*0.6 - 2)*blood / blood_max, PD::lengthH*0.16 - 2);
}

void Tank::onSpriteMove(){
	

	if (type < new_tank_id){

		double width_div_height = MathMethod::width_div_height(PD::resm->tank[type][direct]);

		if (direct == 0 || direct == 2){
			//sprite->setSize(width_div_height*width, height);
			sprite->setXY(x - (width_div_height - 1)*PD::lengthW / 2, y);
		}
		else{
			//sprite->setSize(width_div_height*width * 3 / 4, height * 3 / 4);
			sprite->setXY(x - (width_div_height - 1)*PD::lengthW / 2 * 3 / 8, y + PD::lengthH * 1 / 8);
		}
	}
	else if (type < 9){
		sprite->setXY(x, y);

		frame = (frame + 1) % frame_sum;
		sprite->setFrame(frame + frame_sum * direct_frame[direct]);
	}
	else if (type == 9){
		sprite->setXY(x + PD::lengthW / 4, y);// -PD::lengthH);

		frame = (frame + 1) % frame_sum;
		sprite->setFrame(frame + frame_sum * direct_frame[direct]);
	}

	sprite_blood->setRectPosition(x + PD::lengthW*0.2 + 1, y - PD::lengthH*0.08 + 1);

}

void Tank::setVisible(bool visible){
	this->visible = visible;
	sprite->setVisible(visible);
	sprite_blood->setVisible(visible);
}


void Tank::release(){
	
	MathMethod::releasePath(path);
	MathMethod::releasePath(path_tmp);
	MathMethod::releaseSprite(sprite);
	MathMethod::releaseRectangle(sprite_blood);

	delete this;
}