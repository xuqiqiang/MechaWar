#include "RoundManager.h"


RoundManager::RoundManager()
{

	roundallow = 4;

	int map_tmp[ROUND_SUM][PD::ROW][PD::COL] = {
		{
		{ 2, 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2 } },

		{
			{ 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 3, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2 } },
			{
				{ 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
				{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 2, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
				{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2 } },
				{
					{ 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
					{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
					{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2 } },
					{
						{ 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
						{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2 } } };

	for (int i = 0; i < ROUND_SUM;i++)
	for (int j = 0; j < PD::ROW;j++)
	for (int k = 0; k < PD::COL; k++){
		map[i][j][k] = map_tmp[i][j][k];
	}



	///////////////////////////////////////////////////////////////////////////////////////////////////////

	int wave_sum_tmp[ROUND_SUM] = { 10, 10, 10, 10, 10 };

	int tank_sum_tmp[ROUND_SUM][WAVE_SUM_MAX] = {
		{ 6, 3, 4, 3, 3, 4, 6, 3, 0, 8 },
		{ 3, 3, 4, 1, 0, 0, 6, 3, 0, 8 },
		{ 3, 3, 4, 1, 0, 0, 6, 3, 0, 8 },
		{ 3, 3, 4, 1, 0, 0, 6, 3, 0, 8 },
		{ 3, 3, 4, 1, 0, 0, 6, 3, 0, 8 }
	};
	int plane_sum_tmp[ROUND_SUM][WAVE_SUM_MAX] = {
		{ 3, 4, 5, 6, 3, 4, 5, 5, 5, 5 },
		{ 0, 0, 0, 0, 3, 4, 0, 0, 5, 5 },
		{ 0, 0, 0, 0, 3, 4, 0, 0, 5, 5 },
		{ 0, 0, 0, 0, 3, 4, 0, 0, 5, 5 },
		{ 0, 0, 0, 0, 3, 4, 0, 0, 5, 5 }
	};
	int tank_type_tmp[ROUND_SUM][WAVE_SUM_MAX] = {
		{ 0, 1, 2, 3, 4, 5, 2, 3, 0, 2 },
		{ 0, 1, 2, 3, 0, 0, 2, 3, 0, 2 },
		{ 0, 1, 2, 3, 0, 0, 2, 3, 0, 2 },
		{ 0, 1, 2, 3, 0, 0, 2, 3, 0, 2 },
		{ 0, 1, 2, 3, 0, 0, 2, 3, 0, 2 }
	};
	int plane_type_tmp[ROUND_SUM][WAVE_SUM_MAX] = {
		{ 0, 1, 2, 3, 4, 5, 3, 4, 2, 1 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 }
	};
	int tank_blood_tmp[ROUND_SUM][WAVE_SUM_MAX] = {
		{ 100, 70, 200, 100, 0, 0, 500, 200, 0, 800 },
		{ 100, 70, 200, 100, 0, 0, 500, 200, 0, 800 },
		{ 100, 70, 200, 100, 0, 0, 500, 200, 0, 800 },
		{ 100, 70, 200, 100, 0, 0, 500, 200, 0, 800 },
		{ 100, 70, 200, 100, 0, 0, 500, 200, 0, 800 },
	};
	int plane_blood_tmp[ROUND_SUM][WAVE_SUM_MAX] = {
		{ 20, 20, 20, 20, 200, 100, 0, 0, 500, 200 },
		{ 0, 0, 0, 0, 200, 100, 0, 0, 500, 200 },
		{ 0, 0, 0, 0, 200, 100, 0, 0, 500, 200 },
		{ 0, 0, 0, 0, 200, 100, 0, 0, 500, 200 },
		{ 0, 0, 0, 0, 200, 100, 0, 0, 500, 200 }
	};


	for (int i = 0; i < ROUND_SUM; i++)
	for (int j = 0; j <WAVE_SUM_MAX; j++){
		wave_sum[i] = wave_sum_tmp[i];
		tank_sum[i][j] = tank_sum_tmp[i][j];
		plane_sum[i][j] = plane_sum_tmp[i][j];
		tank_type[i][j] = tank_type_tmp[i][j];
		plane_type[i][j] = plane_type_tmp[i][j];
		tank_blood[i][j] = tank_blood_tmp[i][j];
		plane_blood[i][j] = plane_blood_tmp[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	MyPoint pos_tmp[ROUND_SUM] = {
		MyPoint(-1, 0),
		MyPoint(-1, 0),
		MyPoint(-1, 0),
		MyPoint(-1, 0),
		MyPoint(-1, 0),
	};

	MyPoint des_tmp[ROUND_SUM] = {
		MyPoint(10, 15),
		MyPoint(10, 15),
		MyPoint(10, 15),
		MyPoint(10, 15),
		MyPoint(10, 15),
	};

	for (int i = 0; i < ROUND_SUM; i++){
		pos[i] = pos_tmp[i];
		des[i] = des_tmp[i];
	}
}
