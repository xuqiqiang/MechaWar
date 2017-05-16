#include "Status.h"
#include "PD.h"
#include "ObjectManager.h"

Status::Status(){
	blood = 30;
	money = 200;
}


void Status::reduceBlood(){
	blood--;
	PD::om->refreshStatus();
	if (blood <= 0){
		PD::situation = PD::SITUATION_LOSE;
	}
}