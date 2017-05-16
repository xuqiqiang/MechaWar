#include "MyPoint.h"
//using namespace MyNameSpace;

//namespace MyNameSpace{

MyPoint::MyPoint(){
	}

MyPoint::MyPoint(int i, int j){
		this->i = i;
		this->j = j;
	}


MyPoint MyPoint::getTruePoint(){
	return MyPoint(i - 1, j - 1);
	}

MyPoint MyPoint::getMapPoint(){
	return MyPoint(i + 1, j + 1);
	}


MyPoint MyPoint::clone(){
	return MyPoint(i, j);
	}

//}