#ifndef __Blast_H__
#define __Blast_H__

#include "PD.h"
#include "MySprite.h"
class Blast
{
private:

	double x, y, size;
	int frame;
	
	int type;

	MySprite *sprite;

	static const int type_sum = 4;

	static int frame_sum[type_sum];

protected:
public:

	bool visible;

	static void initData(){
		int frame_sum_tmp[type_sum] = { 16, 10, 20, 20 };
		for (int i = 0; i < type_sum; i++){
			frame_sum[i] = frame_sum_tmp[i];
		}
	}

	Blast(double x, double y, double size, int type, int zOrder);

	bool play();

	virtual void setVisible(bool visible);

	virtual void release();

};

#endif