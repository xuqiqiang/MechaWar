#ifndef __Map_H__
#define __Map_H__


#include "PD.h"
#include "MyPoint.h"
#include "MySprite.h"

#include<vector>
using namespace std;


class Map
{
public:
	Map();

	MySprite *background;

	int row, col;


	MyPoint pos;
	MyPoint des;

	static const int EMPTY = 0,
		GUN = 1,
		OBSTRACLE = 2;
	vector<MyPoint>* main_path;
	vector<MyPoint>* main_path_tmp;

	bool need_refind_path;

	int map_data[PD::ROW][PD::COL];

	vector<MyPoint>* getPath(MyPoint pos, MyPoint des);
	MyPoint* getAmend(MyPoint pos, MyPoint des);

	void initMainPath();

	void refindMainPath();
	
	void showBackground();

	bool checkInMap(int i, int j);
	void setMine(int i, int j);
	void recoverMine(int i, int j);
	bool checkPointInMine(MyPoint p, int i, int j);
	bool setupMineInMap(int i, int j);
	bool setupTowerInMap(int i, int j);
};

#endif