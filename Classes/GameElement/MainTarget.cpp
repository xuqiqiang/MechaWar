#include "MainTarget.h"
#include "MathMethod.h"
#include "ObjectManager.h"

double MainTarget::field_min;
double MainTarget::field_max;
double MainTarget::field_speed;
int MainTarget::show_time;

MainTarget::MainTarget(){
	target = NULL;
	visible = false;

	height = PD::lengthH * 0.2;
	width = MathMethod::getWidth(PD::resm->target[3], height);

	for (int i = 0; i < 4; i++){
		sprite[i] = new MySprite(PD::resm->target[i], true);
		sprite[i]->setSize(width, height);

		PD::gs->addChild(sprite[i], 300);
		PD::om->sprite->push_back(sprite[i]);
		sprite[i]->setVisible(visible);
	}

	
}

void MainTarget::logic(){
	if (visible){

		if (field_direct == 0){
			field += field_speed;
			if (field>field_max)
				field_direct = 1;
		}
		else if (field_direct == 1){
			field -= field_speed;
			if (field<field_min)
				field_direct = 0;
		}

		double lengthH = PD::H * 2.5;
		sprite[0]->setXY(target->x + width + field, target->y - field + lengthH);
		sprite[1]->setXY(target->x + width + field, target->y + height + field + lengthH);
		sprite[2]->setXY(target->x - field, target->y + height + field + lengthH);
		sprite[3]->setXY(target->x - field, target->y - field + lengthH);

		if (timer->run()){
			setVisible(false);
		}
	}
}

void MainTarget::setTarget(Enemy *target){
	this->target = target;

	if (target != NULL){

		field_direct = 1;
		field = field_max;

		double lengthH = PD::H * 2.5;
		sprite[0]->setXY(target->x + width + field, target->y - field + lengthH);
		sprite[1]->setXY(target->x + width + field, target->y + height + field + lengthH);
		sprite[2]->setXY(target->x - field, target->y + height + field + lengthH);
		sprite[3]->setXY(target->x - field, target->y - field + lengthH);

		setVisible(true);

		timer = new Timer(show_time);
	}
	else{
		setVisible(false);
	}
}

void MainTarget::setVisible(bool visible){
	this->visible = visible;
	for (int i = 0; i < 4; i++){
		sprite[i]->setVisible(visible);
	}

}