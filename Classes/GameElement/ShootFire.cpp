#include "ShootFire.h"
#include "MathMethod.h"
#include "Math.h"
#include "ObjectManager.h"

ShootFire::ShootFire(int i, int j){
	this->i = i;
	this->j = j;
	visible = false;
	timer = new Timer(shoot_time);
	size = PD::lengthX*0.3;


	//sprite = new MySprite(PD::resm->fire);

	//spirit = new Texture(RM.fire_id);
	double sint, cost;
	cost = cos(MathMethod::angle2Rad(angle));
	sint = sin(MathMethod::angle2Rad(angle));

	sprite = new MySprite(PD::resm->fire, j*PD::lengthW + PD::lengthW / 2 + PD::lengthW*cost / 2 - size*0.6,
		i*PD::lengthH + PD::lengthH / 2 + PD::lengthH*sint / 3 - PD::lengthH*0.2 - size*0.5,
		size*1.2,
		size, true);
	sprite->setRotation(angle + 45);
	PD::gs->addChild(sprite, 2);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);
}

void ShootFire::shoot(Enemy *target, double angle, double destoy){
	//visible = timer->runLoop();
	setVisible(timer->runLoop());
	if (visible){
		if (this->angle != angle){
			this->angle = angle;

			double sint, cost;
			cost = cos(MathMethod::angle2Rad(angle));
			sint = sin(MathMethod::angle2Rad(angle));
			/*spirit.setVertices_rotate(j*PD.lengthW + PD.lengthW / 2 + PD.lengthW*cost / 2 - size*0.6,
				i*PD.lengthH + PD.lengthH / 2 + PD.lengthH*sint / 3 - PD.lengthH*0.2 - size*0.5,
				size*1.2,
				size,
				angle + 45,
				true);*/

			sprite->setXY(j*PD::lengthW + PD::lengthW / 2 + PD::lengthW*cost / 2 - size*0.6,
				i*PD::lengthH + PD::lengthH / 2 + PD::lengthH*sint / 3 - PD::lengthH*0.2 - size*0.5);
			sprite->setRotation(angle + 45);
		}
		target->attacted(destoy);
	}
}

void ShootFire::setVisible(bool visible){
	this->visible = visible;
	sprite->setVisible(visible);
}

void ShootFire::release(){
	MathMethod::releaseSprite(sprite);
	delete timer;
	delete this;
}