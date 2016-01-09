#pragma once
#include "Vaisseau.h"

class LightVaisseau :public Vaisseau{

protected:
	int lifetime;
	float r, g, b, posX, posY;
public:
	LightVaisseau(float posX_ = 0.0, float posY_ = 0.0, float r_ = 0.0, float g_ = 0.0, float b_ = 0.0, int lifetime_ = 0, Missile *missile_ = nullptr) :
		posX(posX_), posY(posY_), r(r_), g(r_), b(r_), lifetime(lifetime_), missile(missile_),
		Vaisseau(posX_, posY_, r_, g_, b_, missile_)

	{}
	Missile *missile;
	virtual float getPosX();
	virtual float getPosY();
	virtual float getR();
	virtual float getG();
	virtual float getB();
	int getLifeTime();

	virtual void setPosX(float newX);
	virtual void setPosY(float newY);
	virtual void setR(float newR);
	virtual void setG(float newG);
	virtual void setB(float newB);
	void setLifeTime(int newLifeTime);
	virtual void draw();
};