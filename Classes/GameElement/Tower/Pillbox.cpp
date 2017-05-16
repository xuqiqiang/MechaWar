#include "Pillbox.h"
#include "MathMethod.h"
#include "ObjectManager.h"

Pillbox::Pillbox(int i, int j) : Tower(i, j){
	destoy = tower_destory[PILLBOX];//d;
	field = tower_field[PILLBOX];//f;
	price = tower_price[PILLBOX];//f;
	update_price = price;

	sf = new ShootFire(i, j);

	sprite = new MySprite(PD::resm->gun1, j*PD::lengthW,
		i*PD::lengthH - (double)((MathMethod::height_div_width(PD::resm->gun1) - 1)*PD::lengthH / 2),
		PD::lengthW,
		MathMethod::height_div_width(PD::resm->gun1)*PD::lengthH, true);
	PD::gs->addChild(sprite, 1);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);
}


void Pillbox::shoot(){
	Tower::shoot();

	if (visible){
		//CCLog("Pillbox::shoot");
		if (target != NULL){
			//CCLog("target != NULL");
			sf->shoot(target, angle, destoy);
		}
		else
			sf->setVisible(false);
	}
}


void Pillbox::promote(){
	Tower::promote();

	sprite->setStatus(j*PD::lengthW - PD::lengthW*0.05*(grade - 1),
		i*PD::lengthH - (double)((MathMethod::height_div_width(PD::resm->gun1) - 1)*PD::lengthH / 2) - MathMethod::height_div_width(PD::resm->gun1)*PD::lengthH*0.05*(grade - 1),
		PD::lengthW*(1 + 0.1*(grade - 1)),
		MathMethod::height_div_width(PD::resm->gun1)*PD::lengthH*(1 + 0.1*(grade - 1)));
}

void Pillbox::setVisible(bool visible){
	Tower::setVisible(visible);
	sprite->setVisible(visible);
	sf->setVisible(visible);
}

void Pillbox::release(){
	Tower::release();
	MathMethod::releaseSprite(sprite);
	sf->release();
	delete this;
}