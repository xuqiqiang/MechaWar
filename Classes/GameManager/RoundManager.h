#ifndef __RoundManager_H__
#define __RoundManager_H__

#include "PD.h"
#include "MyPoint.h"
//class PD;

class RoundManager
{
public:
	RoundManager();
	//~RoundManager();

	static const int ROUND_SUM = 5;

	int map[ROUND_SUM][PD::ROW][PD::COL];

	static const int WAVE_SUM_MAX = 10;

	int wave_sum[ROUND_SUM];
	int tank_sum[ROUND_SUM][WAVE_SUM_MAX];
	int plane_sum[ROUND_SUM][WAVE_SUM_MAX];
	int tank_type[ROUND_SUM][WAVE_SUM_MAX];
	int plane_type[ROUND_SUM][WAVE_SUM_MAX];
	int tank_blood[ROUND_SUM][WAVE_SUM_MAX];
	int plane_blood[ROUND_SUM][WAVE_SUM_MAX];

	int roundallow;		//已解锁的关卡

	MyPoint pos[ROUND_SUM], des[ROUND_SUM];
};

#endif