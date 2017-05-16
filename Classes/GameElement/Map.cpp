#include "Map.h"
#include "RoundManager.h"
#include "Math.h"
#include "MyPoint.h"
#include "Queue.h"
#include "GameScene.h"
#include "SpriteManager.h"
#include "MySprite.h"
#include "ObjectManager.h"
#include "MathMethod.h"
#include "Runner.h"

#define amend_sum 4


Map::Map(){
	
	row = PD::ROW;
	col = PD::COL;

	
	int i, j;
	for (i = 0; i<row; i++)
	for (j = 0; j<col; j++)
		map_data[i][j] = PD::rm->map[PD::round][i][j];

	pos = PD::rm->pos[PD::round];
	des = PD::rm->des[PD::round];

	//main_path = getPath(pos+1, des+1);
	main_path = NULL;

}


void Map::initMainPath(){
	MathMethod::releasePath(main_path);
	main_path = getPath(pos + 1, des + 1);
	need_refind_path = false;
}


void Map::refindMainPath(){
	if (need_refind_path){
		initMainPath();
	}
}


vector<MyPoint>* Map::getPath(MyPoint pos, MyPoint des){

	int i, j;


	MyPoint before[PD::ROW][PD::COL];
	for (i = 0; i<row; i++)
	for (j = 0; j<col; j++)
		before[i][j] = Point_null;
	before[pos.i][pos.j] = pos;


	Queue queue = Queue();
	int new_i, new_j;

	MyPoint* amend = getAmend(pos, des);
	for (i = 0; i<amend_sum; i++){
		new_i = pos.i + amend[i].i;
		new_j = pos.j + amend[i].j;
		if (checkInMap(new_i, new_j) &&
			map_data[new_i][new_j] == EMPTY){
			before[new_i][new_j] = pos;
			queue.enter(MyPoint(new_i, new_j));
		}
	}

	delete amend;

	while (!queue.isEmpty()){
		MyPoint p = queue.out();

		if (p.i == des.i && p.j == des.j){
			vector<MyPoint>* path = new vector<MyPoint>();
			path->push_back(p.getTruePoint());

			//map[p.i][p.j]=1;

			MyPoint pre = before[p.i][p.j];

			//map[pre.i][pre.j]=1;

			while (pre!=pos){

				path->insert(path->begin(), pre.getTruePoint());
				pre = before[pre.i][pre.j];
				//map[pre.i][pre.j]=1;
			}
			path->insert(path->begin(), pos.getTruePoint());
			
			return path;
		}

		amend = getAmend(p, des);

		for (i = 0; i<amend_sum; i++){
			new_i = p.i + amend[i].i;
			new_j = p.j + amend[i].j;
			if (checkInMap(new_i, new_j)
				&& map_data[new_i][new_j] == EMPTY
				&&before[new_i][new_j] == Point_null){

				queue.enter(MyPoint(new_i, new_j));
				before[new_i][new_j] = p;
			}
		}

		delete amend;
	}

	return NULL;
}

MyPoint* Map::getAmend(MyPoint pos, MyPoint des){
	MyPoint* amend = new MyPoint[amend_sum];

	if (abs(des.i - pos.i) >= abs(des.j - pos.j)){
		if (des.i>pos.i){
			amend[0] = MyPoint(1, 0);
			amend[3] = MyPoint(-1, 0);
		}
		else{
			amend[0] = MyPoint(-1, 0);
			amend[3] = MyPoint(1, 0);
		}

		if (des.j >= pos.j){
			amend[1] = MyPoint(0, 1);
			amend[2] = MyPoint(0, -1);
		}
		else{
			amend[1] = MyPoint(0, -1);
			amend[2] = MyPoint(0, 1);
		}
	}
	else{
		if (des.j>pos.j){
			amend[0] = MyPoint(0, 1);
			amend[3] = MyPoint(0, -1);
		}
		else{
			amend[0] = MyPoint(0, -1);
			amend[3] = MyPoint(0, 1);
		}

		if (des.i >= pos.i){
			amend[1] = MyPoint(1, 0);
			amend[2] = MyPoint(-1, 0);
		}
		else{
			amend[1] = MyPoint(-1, 0);
			amend[2] = MyPoint(1, 0);
		}
	}

	return amend;
}

void Map::showBackground(){
	background = new MySprite(PD::resm->background,//"background.jpg", 
		0, 0, PD::screen_width, PD::screen_height, true);
	
	PD::gs->addChild(background, 0);

	PD::om->sprite->push_back(background);
}



bool Map::checkInMap(int i, int j){
	return (i >= 0 && i<row&&j >= 0 && j<col);
}
void Map::setMine(int i, int j){
	map_data[i][j] = OBSTRACLE;
	map_data[i + 1][j] = OBSTRACLE;
	map_data[i][j + 1] = OBSTRACLE;
	map_data[i + 1][j + 1] = OBSTRACLE;
}

void Map::recoverMine(int i, int j){
	map_data[i][j] = EMPTY;
	map_data[i + 1][j] = EMPTY;
	map_data[i][j + 1] = EMPTY;
	map_data[i + 1][j + 1] = EMPTY;
}
bool Map::checkPointInMine(MyPoint p, int i, int j){
	return (p.i >= i&&
		p.i <= i + 1 &&
		p.j >= j&&
		p.j <= j + 1);
}

bool Map::setupMineInMap(int i, int j){
	setMine(i, j);

	main_path_tmp = getPath(pos + 1, des + 1);
	if (main_path_tmp == NULL){
		recoverMine(i, j);
		return false;
	}


	for (int index = 0; index < PD::om->enemy->size(); index++){
		if (MathMethod::stringStartWith(PD::om->enemy->at(index)->class_name, "Enemy_Runner")){
			Runner *r = (Runner *)PD::om->enemy->at(index);
			if (r->visible&&
				checkPointInMine(r->path->at(Runner::POS_ID)+1, i, j) &&
				checkPointInMine(r->path->at(Runner::DES_ID)+1, i, j)){
				recoverMine(i, j);
				return false;
			}
		}
	}

	int id;
	bool find;

	for (int index = 0; index < PD::om->enemy->size(); index++){
		if (MathMethod::stringStartWith(PD::om->enemy->at(index)->class_name, "Enemy_Runner")){
			Runner *r = (Runner *)PD::om->enemy->at(index);
			if (r->visible){
				find = false;
				for (id = Runner::DES_ID; id<r->path->size(); id++){
					if (checkPointInMine(r->path->at(id) + 1, i, j)){
						find = true;
						break;
					}
				}
				if (find){


					MathMethod::releasePath(r->path_tmp);

					//r->path_tmp = getPath(r->path->at(Runner::POS_ID) + 1,
					//	des + 1);

					if (map_data[r->path->at(Runner::DES_ID).i + 1][r->path->at(Runner::DES_ID).j + 1] == EMPTY){
						r->path_tmp = getPath(r->path->at(Runner::DES_ID) + 1, des + 1);
					}
					else{
						r->path_tmp = getPath(r->path->at(Runner::POS_ID) + 1, des + 1);
					}

					if (r->path_tmp == NULL){
						recoverMine(i, j);
						return false;
					}
				}

			}
		}
	}

	for (int index = 0; index < PD::om->enemy->size(); index++){
		if (MathMethod::stringStartWith(PD::om->enemy->at(index)->class_name, "Enemy_Runner")){
			Runner *r = (Runner *)PD::om->enemy->at(index);
			if (r->visible&&r->path_tmp != NULL){
				/*Point p = r->path->at(Runner::DES_ID);
				if (p!=r->path_tmp->at(Runner::DES_ID)){
					r->path_tmp->insert(r->path_tmp->begin() + Runner::POS_ID, p.clone());
				}*/

				MyPoint p;
				if (r->path_tmp->at(Runner::POS_ID) == r->path->at(Runner::POS_ID)){
					p = r->path->at(Runner::DES_ID);
				}
				else{
					p = r->path->at(Runner::POS_ID);
				}

				if (p != r->path_tmp->at(Runner::DES_ID)){
					r->path_tmp->insert(r->path_tmp->begin() + Runner::POS_ID, p.clone());
				}

				MathMethod::releasePath(r->path);

				r->path = MathMethod::clonePath(r->path_tmp);

				MathMethod::releasePath(r->path_tmp);

				r->setNewDes();
				r->onChangeDirection();
			}
		}
	}


	MathMethod::releasePath(main_path);
	main_path = MathMethod::clonePath(main_path_tmp);
	MathMethod::releasePath(main_path_tmp);


	return true;
}

bool Map::setupTowerInMap(int i, int j){
	map_data[i][j] = OBSTRACLE;

	main_path_tmp = getPath(pos + 1, des + 1);
	if (main_path_tmp == NULL){
		map_data[i][j] = EMPTY;
		return false;
	}



	int id;
	bool find;

	for (int index = 0; index < PD::om->enemy->size(); index++){
		if (MathMethod::stringStartWith(PD::om->enemy->at(index)->class_name, "Enemy_Runner")){
			Runner *r = (Runner *)PD::om->enemy->at(index);
			if (r->visible){
				find = false;
				for (id = Runner::DES_ID; id<r->path->size(); id++){
					if (r->path->at(id).i + 1 == i &&
						r->path->at(id).j + 1 == j){
						find = true;
						break;
					}
				}
				if (find){

					MathMethod::releasePath(r->path_tmp);

					if (map_data[r->path->at(Runner::DES_ID).i + 1][r->path->at(Runner::DES_ID).j + 1] == EMPTY){
						r->path_tmp = getPath(r->path->at(Runner::DES_ID) + 1,
							des + 1);
					}
					else{
						r->path_tmp = getPath(r->path->at(Runner::POS_ID) + 1,
							des + 1);
					}

					
					if (r->path_tmp == NULL){
						map_data[i][j] = EMPTY;
						return false;
					}
				}

			}
		}
	}

	for (int index = 0; index < PD::om->enemy->size(); index++){
		if (MathMethod::stringStartWith(PD::om->enemy->at(index)->class_name, "Enemy_Runner")){
			Runner *r = (Runner *)PD::om->enemy->at(index);
			if (r->visible&&r->path_tmp != NULL){
				/*Point p = r->path->at(Runner::DES_ID);
				if (p != r->path_tmp->at(Runner::DES_ID)){
					r->path_tmp->insert(r->path_tmp->begin() + Runner::POS_ID, p.clone());
				}*/

				MyPoint p;
				if (r->path_tmp->at(Runner::POS_ID) == r->path->at(Runner::POS_ID)){
					p = r->path->at(Runner::DES_ID);
				}
				else{
					p = r->path->at(Runner::POS_ID);
				}

				if (p != r->path_tmp->at(Runner::DES_ID)){
					r->path_tmp->insert(r->path_tmp->begin() + Runner::POS_ID, p.clone());
				}
				
				MathMethod::releasePath(r->path);

				r->path = MathMethod::clonePath(r->path_tmp);

				MathMethod::releasePath(r->path_tmp);


				r->setNewDes();
				r->onChangeDirection();
			}
		}
	}


	MathMethod::releasePath(main_path);
	main_path = MathMethod::clonePath(main_path_tmp);
	MathMethod::releasePath(main_path_tmp);

	return true;
}