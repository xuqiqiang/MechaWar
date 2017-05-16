#include "Enemy.h"
#include "ObjectManager.h"
#include "MathMethod.h"

double Enemy::advice_speed;

Enemy::Enemy(){
	strcpy(class_name, "Enemy");

	width = PD::lengthW;
	height = PD::lengthH;

	speed_recover_timer = new Timer(speed_recover_time);
	speed_recover_timer->setEnable(false);

	ispress = false;
	visible = true;
}

void Enemy::move(){
	switch (direct){
	case 0:y -= speed; break;
	case 1:x += speed; break;
	case 2:y += speed; break;
	case 3:x -= speed; break;
	}
	
	if (speed_recover_timer->run()){
		speed_recover_timer->setEnable(false);
		speed = speed_max;
	}
}


void Enemy::slowDown(){
	speed = speed_max * 0.5;
	speed_recover_timer->setTime();
	speed_recover_timer->setEnable(true);
	
}

void Enemy::onTouch(CCPoint touch_point, int touch_event){

	if (visible){
		if (touch_event == PD::TOUCH_DOWN){
			if (MathMethod::pointInRect(touch_point, x, y, width, height)){
				ispress = true;
			}
		}
		else if (touch_event == PD::TOUCH_UP){
			if (ispress){
				ispress = false;
				if (MathMethod::pointInRect(touch_point, x, y, width, height)){
					//CCLog(class_name);
					if (MathMethod::stringStartWith(class_name, "Enemy_Runner_Tank") ||
						MathMethod::stringStartWith(class_name, "Enemy_Flyer_Plane")){
						//PD::om->main_target = this;
						PD::om->mainTarget->setTarget(this);

						for (int i = 0; i < PD::om->tower->size(); i++)
							PD::om->tower->at(i)->target = NULL;
					}
				}
			}
		}
	}
}

void Enemy::attacted(double destoy){
	blood -= destoy;
	if (blood <= 0){
		//visible = false;

		if (PD::om->mainTarget->target == this){
			PD::om->mainTarget->setTarget(NULL);
		}

		setVisible(false);
	}
}

void Enemy::setVisible(bool visible){
	this->visible = visible;
	//sprite->setVisible(visible);
}

void Enemy::arrive(){
	if (PD::om->mainTarget->target == this){
		PD::om->mainTarget->setTarget(NULL);
	}
	setVisible(false);

	if (MathMethod::stringStartWith(class_name, "Enemy_Runner_Tank") ||
		MathMethod::stringStartWith(class_name, "Enemy_Flyer_Plane")){
		PD::status->reduceBlood();
	}
}

void Enemy::logic(){
	//CCLog("asd");
}

void Enemy::show(){

}

void Enemy::release(){
	delete this;
}