#include "MyRect.h"

MyRect::MyRect(){

}

MyRect::MyRect(double x, double y, double width, double height) : CCRect(x, y, width, height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}