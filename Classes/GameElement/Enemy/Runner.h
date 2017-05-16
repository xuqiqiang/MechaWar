#ifndef __Runner_H__
#define __Runner_H__

#include "PD.h"
#include "Enemy.h"
#include "MyPoint.h"
#include "MySprite.h"
#include <vector>
using namespace std;

class Runner : public Enemy
{
private:

protected:

	virtual void onSpriteMove();

	//virtual void show();
	
public:

	double des_x;
	double des_y;

	static const int POS_ID = 0, DES_ID = 1;

	vector<MyPoint>* path;
	vector<MyPoint>* path_tmp;

	MySprite *sprite;
	
	Runner(double pos_x, double pos_y);

	Runner(double pos_x, double pos_y, bool child);

	void setNewDes();

	virtual void onChangeDirection();

	void moveToPath();

	bool checkArrive(double des_x, double des_y);

	virtual void logic();

	//virtual void arrive();

	virtual void setVisible(bool visible);
	
	virtual void release();
	
};

#endif