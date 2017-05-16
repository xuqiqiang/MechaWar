#include "MyRectangle.h"
#include "PD.h"

MyRectangle::MyRectangle(double x, double y, double width, double height, ccColor4F color, bool inCamera){

	this->inCamera = inCamera;



	this->color = color;


	setRectSize(width, height);
	
	setRectPosition(x, y);
	//visible = true;
}
void MyRectangle::draw()
{
	// 绘制多边形线框。
	/*ccDrawColor4B(255, 255, 0, 255);
	glLineWidth(10);
	CCPoint vertices[] = { ccp(150, 150), ccp(100, 150), ccp(100, 100), ccp(150, 100) };
	//这里绘制多边形线框函数，使用上面的顶点数组做为多边形线框的顶点位置，第二个参数为顶点数量，第三个参数指定是否首尾自动连接形成封闭线框。
	//注：其实这个函数拆成两个函数比较好,一个是去掉最后一个参数的ccDrawPoly，用于绘制默认封闭的多边形线框。另一个ccDrawLineList用于绘制线段列。
	ccDrawPoly(vertices, 4, true);
	//继续检错
	CHECK_GL_ERROR_DEBUG();*/
	//ccDrawColor4B(0, 255, 0, 50);
	//绘制实体多边形
	glLineWidth(1);

	//CCPoint filledVertices1[] = { ccp(x, y), ccp(x + 2*width, y), ccp(x + 2*width, y + 2*height), ccp(x, y + 2*height) };
	///这里绘制内部填充指定色彩的多边形
	//ccDrawSolidPoly(filledVertices1, 4, ccc4f(0, 0, 1, 1));

	double show_x, show_y;
	show_x = PD::OX + view_x;
	show_y = PD::OY + PD::screen_height - view_y - view_height;

	CCPoint filledVertices[] = { ccp(show_x, show_y), ccp(show_x + view_width, show_y),
		ccp(show_x + view_width, show_y + view_height), ccp(show_x, show_y + view_height) };
	//这里绘制内部填充指定色彩的多边形
	ccDrawSolidPoly(filledVertices, 4, color);// ccc4f(0.5f, 0.5f, 1, 1));


	CHECK_GL_ERROR_DEBUG();

}


void MyRectangle::setRectPosition(double x, double y){
	this->x = x;// PD::OX + x;
	this->y = y;// PD::OY + PD::screen_height - y - height;

	if (inCamera && PD::cm->rate != 1){

		view_x = (x - PD::cm->scrx) / PD::cm->scrw * (PD::screen_width);
		view_y = (y - PD::cm->scry) / PD::cm->scrh * (PD::screen_height);
	}
	else{
		view_x = x;
		view_y = y;
	}
}

void MyRectangle::setRectSize(double width, double height){
	this->width = width;
	this->height = height;

	if (inCamera && PD::cm->rate != 1){
		view_width = width * PD::cm->rate;
		view_height = height * PD::cm->rate;
	}
	else{
		view_width = width;
		view_height = height;
	}
}

void MyRectangle::setRectColor(ccColor4F color){
	this->color = color;
}

void MyRectangle::refresh(){
	setRectSize(width, height);
	setRectPosition(x, y);
}