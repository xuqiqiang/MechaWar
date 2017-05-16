#include "SmokeRocket.h"
#include "MathMethod.h"
#include "ObjectManager.h"


SmokeRocket::SmokeRocket(int i, int j) : Rocket(i, j, true){
	destoy = tower_destory[SMOKEROCKET];//d;
	field = tower_field[SMOKEROCKET];//f;
	price = tower_price[SMOKEROCKET];//f;

	update_price = price;


	sprite_bottom = new MySprite(PD::resm->gun31,
		j*PD::lengthW + PD::lengthW / 2 - MathMethod::getWidth(PD::resm->gun31, PD::lengthW / 4),
		i*PD::lengthH + PD::lengthH / 2,
		MathMethod::getWidth(PD::resm->gun31, PD::lengthH / 2),
		PD::lengthH / 2,
		true);
	PD::gs->addChild(sprite_bottom, 1);
	PD::om->sprite->push_back(sprite_bottom);
	sprite_bottom->setVisible(visible);


	angle = -60;
	CCTexture2D* gun_top = PD::resm->gun_tower_pro[MathMethod::angle2SmokeRocketId(angle)];// PD::resm->gun_tower_pro[(int)((int)(angle + 366) % 360 / 12)];
	sprite_top = new MySprite(gun_top,
		j*PD::lengthW + PD::lengthW / 2 - MathMethod::getWidth(gun_top, PD::lengthH / 4),
		i*PD::lengthH,
		MathMethod::getWidth(gun_top, PD::lengthH / 2),
		PD::lengthH / 2,
		true);
	PD::gs->addChild(sprite_top, 1);
	PD::om->sprite->push_back(sprite_top);
	sprite_top->setVisible(visible);
}

void SmokeRocket::changeAngle(){
	sprite_top->setTexture(PD::resm->gun_tower_pro[MathMethod::angle2SmokeRocketId(angle)]);
}

void SmokeRocket::fireBullet(){
	PD::om->bullet->push_back(new Bullet(i, j, angle, destoy, Bullet::TYPE_BLUE, target));
}

void SmokeRocket::promote(){
	Tower::promote();


	sprite_bottom->setStatus(j*PD::lengthW + PD::lengthW / 2 - MathMethod::getWidth(PD::resm->gun31, PD::lengthW / 4) - MathMethod::getWidth(PD::resm->gun31, PD::lengthW / 2) * 0.05*grade,
		i*PD::lengthH + PD::lengthH / 2,
		MathMethod::getWidth(PD::resm->gun31, PD::lengthW / 2) * (1 + 0.1*grade),
		PD::lengthH / 2 * (1 + 0.1*grade));

	CCTexture2D* gun_top = PD::resm->gun_tower_pro[MathMethod::angle2SmokeRocketId(angle)];
	sprite_top->setStatus(j*PD::lengthW + PD::lengthW / 2 - MathMethod::getWidth(gun_top, PD::lengthH / 4) - MathMethod::getWidth(gun_top, PD::lengthH / 2) * 0.05*grade,
		i*PD::lengthH - PD::lengthH / 2 * 0.1*grade,
		MathMethod::getWidth(gun_top, PD::lengthH / 2) * (1 + 0.1*grade),
		PD::lengthH / 2 * (1 + 0.1*grade));

}