#pragma once
#include "GraphicPrimitives.h"


class Case{

private :
	float posX, posY, posX2, width, height;
	float r, g, b;

public:
	

	Case(float posX_ = -1.0f, float posY_ = -1.0f, float r_ = 0.0f, float g_ = 0.0f, float b_ = 0.0f) :
		posX(posX_), posY(posY_),width(0.18f),height(0.18f),r(r_), g(g_), b(b_){}
	
	~Case();
	
	
	void draw();
	//Getter
	float getPosX();
	float getPosY();
	float getWidth();
	float getHeight();
	float getR();
	float getG();
	float getB();
	//Setter
	void setposX(float newX);
	void setposY(float newY);
	void setWidth(float newW);
	void setHeight(float newH);
	void setR(float newR);
	void setG(float newG);
	void setB(float newB);

};