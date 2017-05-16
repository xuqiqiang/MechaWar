#include "ProgressMananger.h"
#include "PD.h"
#include "MyLabel.h"
#include "MathMethod.h"
#include "ObjectManager.h"
#include "RoundManager.h"
#include "Runner.h"
#include "Flyer.h"
#include "Tank.h"
#include "plane.h"

ProgressMananger::ProgressMananger(int round){
	this->round = round;
	wave = 0;


	sprite_wave = new MySprite(PD::resm->wave,
		PD::W * 50 - MathMethod::getWidth(PD::resm->wave, PD::lengthH),
		3 * PD::lengthH,
		MathMethod::getWidth(PD::resm->wave, 2 * PD::lengthH),
		2 * PD::lengthH,
		false);
	PD::gs->addChild(sprite_wave, 1000);
	sprite_wave->setVisible(false);


	label_wave = MyLabel::getLabel(PD::H * 7, "Arial");
	PD::gs->addChild(label_wave, 1001);
	label_wave->setVisible(false);

	setProgress(SHOW_WAVE);
}

void ProgressMananger::setProgress(int progress){
	this->progress = progress;

	switch (progress){
	case SHOW_WAVE:

		PD::situation = PD::SITUATION_WAITREADY;
		
		timer = new Timer(SHOW_WAVE_TIME);
		sprite_wave->setVisible(true);
		MyLabel::setNumber(label_wave, wave + 1);

		if (wave + 1 < 10)
			MyLabel::setXY(label_wave, PD::W * 48.7, PD::H * 37.7);
		else
			MyLabel::setXY(label_wave, PD::W * 46.9, PD::H * 37.7);
		label_wave->setVisible(true);
		break;
	case SHOW_ADVICE:

		sprite_wave->setVisible(false);
		label_wave->setVisible(false);

		PD::om->map->refindMainPath();

		if (PD::rm->tank_sum[round][wave] > 0){
			PD::om->enemy->push_back(new Runner(0, -PD::lengthH));
		}

		if (PD::rm->plane_sum[round][wave] > 0){
			PD::om->enemy->push_back(new Flyer(1));
			PD::om->enemy->push_back(new Flyer(2));
		}

		break;
	case STARTING:

		PD::situation = PD::SITUATION_STARTING;

		for (int i = 0; i < PD::rm->tank_sum[round][wave]; i++){
			PD::om->enemy->push_back(
				new Tank(0,
				-PD::lengthH * (i*1.5 + 1),
				PD::rm->tank_type[round][wave],
				PD::rm->tank_blood[round][wave]));
		}


		for (int i = 0; i < PD::rm->plane_sum[round][wave]; i++){
			PD::om->enemy->push_back(
				new Plane((int)(CCRANDOM_0_1() * 2) + 1,
				PD::rm->plane_type[round][wave],
				PD::rm->plane_blood[round][wave]));
		}

		break;
	}
}

void ProgressMananger::logic(){

	bool enemy_exist;

	switch (progress){
	case SHOW_WAVE:
		if (timer->run()){
			setProgress(SHOW_ADVICE);
		}
		break;
	case SHOW_ADVICE:

		enemy_exist = false;
		for (int i = 0; i < PD::om->enemy->size(); i++){
			if (PD::om->enemy->at(i)->visible)
				enemy_exist = true;
		}
		if (!enemy_exist){

			PD::situation = PD::SITUATION_CLEAN;
			for (int i = PD::om->enemy->size() - 1; i >= 0; i--){
				PD::om->enemy->at(i)->release();
				PD::om->enemy->at(i) = NULL;
				PD::om->enemy->erase(PD::om->enemy->begin() + i);
			}

			setProgress(STARTING);
		}

		break;
	case STARTING:

		enemy_exist = false;
		for (int i = 0; i < PD::om->enemy->size(); i++){
			if (PD::om->enemy->at(i)->visible)
				enemy_exist = true;
		}

		if (PD::om->bullet->size()>0)
			enemy_exist = true;

		if (PD::om->blast->size()>0)
			enemy_exist = true;

		if (!enemy_exist){

			if (PD::situation == PD::SITUATION_STARTING)
				PD::situation = PD::SITUATION_CLEAN;

			for (int i = PD::om->enemy->size() - 1; i >= 0; i--){
				PD::om->enemy->at(i)->release();
				PD::om->enemy->at(i) = NULL;
				PD::om->enemy->erase(PD::om->enemy->begin() + i);
			}

			if (wave < PD::rm->wave_sum[round] - 1){
				wave++;
				setProgress(SHOW_WAVE);
			}
			else{
				PD::situation = PD::SITUATION_WIN;
			}
		}

		break;
	}
}