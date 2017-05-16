#include "Bullet.h"
#include "MathMethod.h"
#include "Math.h"
#include "ObjectManager.h"
#include "Blast.h"


double Bullet::SPEED;


Bullet::Bullet(int i, int j, double angle, double destoy, int type, Enemy *target){
	this->angle = angle;
	this->destoy = destoy;
	this->target = target;
	this->type = type;
	//x = j*PD::lengthW + (PD::lengthW - PD::lengthW*0.2) / 2;
	//y = i*PD::lengthH + (PD::lengthH - PD::lengthH*0.2) / 2;
	size = PD::lengthX*0.5;

	x = j*PD::lengthW + PD::W*1.2 + PD::W * 3.5 * cos(MathMethod::angle2Rad(angle));// (PD::lengthW - PD::lengthW*0.2) / 2;
	y = i*PD::lengthH + PD::H*0.3 + PD::H * 3 * sin(MathMethod::angle2Rad(angle));

	speed = SPEED;
	visible = true;


	CCTexture2D* missile = PD::resm->missile1;
	if (type==TYPE_BLUE)
		missile = PD::resm->missile2;
	sprite = new MySprite(missile,
		MathMethod::angle2BulletId(angle),
		//(int)(MathMethod::amendBulletAngle(angle) / 11.25),
		x, y, size, size, true);
	PD::gs->addChild(sprite, 4);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);


}

bool Bullet::gooff(){
	if (visible) {

		/*if (target == NULL || !target->visible){
			setVisible(false);

			PD::om->blast->push_back(new Blast(x - PD::lengthW*0.1, y - PD::lengthH*0.1, PD::lengthX*0.8, 1, 2));
			return true;
		}*/

		if (MathMethod::isInField(x + size / 2, y + size / 2,
			target->x + target->width / 2, target->y + target->height / 2, speed/2)){
			//visible = false;
			setVisible(false);
			//PD::om.add(new Blast(x - PD::lengthW*0.4, y - PD::lengthH*0.4, PD::lengthX*0.8, 1));
			int zOrder = 2;
			if (MathMethod::stringStartWith(target->class_name, "Enemy_Flyer"))
				zOrder = 11;

			int blast_type = type + 2;
			PD::om->blast->push_back(new Blast(x - PD::lengthW*0.1, y - PD::lengthH*0.1, PD::lengthX*0.8, blast_type, zOrder));
			
			if (target->visible){
				if (type == TYPE_BLUE){
					target->slowDown();
				}

				target->attacted(destoy);
			}
			return false;
		}
		else {
			if (speed < speed_max)
				speed += speed_add;

			double rad = MathMethod::getRad(x + size / 2, y + size / 2,
				target->x + target->width / 2,
				target->y + target->height / 2);

			double new_angle = MathMethod::rad2Angle(rad);
			if (MathMethod::angle2BulletId(new_angle) != MathMethod::angle2BulletId(angle)) {
				sprite->setFrame(MathMethod::angle2BulletId(new_angle));
			}
			angle = new_angle;
			
			x += speed * cos(rad);
			y += speed * sin(rad);

			sprite->setXY(x, y);
		}
		return true;
	}

	return false;
}


void Bullet::setVisible(bool visible){
	this->visible = visible;
	sprite->setVisible(visible);
}


void Bullet::release(){

	MathMethod::releaseSprite(sprite);
	//delete timer;
	delete this;
}