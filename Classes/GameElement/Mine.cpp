#include "Mine.h"

#include "ObjectManager.h"

Mine::Mine(int i, int j){
	this->i = i;
	this->j = j;

	visible = true;

	show();

	smoke1 = new Smoke();
	smoke2 = new Smoke();

	timer = new Timer(run_delay);
}

void Mine::show(){
	spirit = new MySprite(PD::resm->mine,
		j*PD::lengthW, i*PD::lengthH, PD::lengthW * 2, PD::lengthW * 2, true);

	PD::gs->addChild(spirit, 1);

	PD::om->sprite->push_back(spirit);
}

void Mine::run(){
	if (!visible)
		return;
	
	if (PD::situation == PD::SITUATION_STARTING){
		//time = (time + 1) % 50;
		//if((timer-time)%m_delay<delay)
		
		if (timer->runLoop()){
			//smoke1=new Smoke(j*length+length*0.8,i*length-length*0.1,length*0.2,length*0.2);
			//smoke2=new Smoke(j*length+length*0.4,i*length+length*0.3,length*0.2,length*0.2);
			delete smoke1;
			delete smoke2;
			smoke1 = new Smoke(PD::lengthW*(j + 0.8), PD::lengthH*(i - 0.1), PD::lengthW*0.2, PD::lengthH*0.2);
			smoke2 = new Smoke(PD::lengthW*(j + 0.4), PD::lengthH*(i + 0.3), PD::lengthW*0.2, PD::lengthH*0.2);
			double number = CCRANDOM_0_1();// Math.random();
			if (number <= 0.1)
				moneyplus = 3;
			else if (number <= 0.2)
				moneyplus = 2;
			else
				moneyplus = 1;
			PD::status->money += moneyplus;

			PD::om->refreshStatus();
		}

		smoke1->run();
		smoke2->run();
	}
}


void Mine::destroyed(){
	PD::om->blast->push_back(new Blast(j*PD::lengthW - PD::lengthW*0.15, i*PD::lengthH - PD::lengthH*0.15, PD::lengthX*2.3, 1, 2));
	setVisible(false);
	PD::om->map->recoverMine(i + 1, j + 1);

	PD::om->map->need_refind_path = true;
}

void Mine::setVisible(bool visible){
	this->visible = visible;
	spirit->setVisible(visible);
	smoke1->setVisible(visible);
	smoke2->setVisible(visible);
}

void Mine::release(){
	MathMethod::releaseSprite(spirit);
	smoke1->release();
	smoke2->release();
	delete this;
}