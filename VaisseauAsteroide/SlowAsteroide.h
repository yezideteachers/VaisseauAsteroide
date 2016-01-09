#pragma once
#include "Asteroide.h"

class SlowAsteroide :public Asteroide{

private:
	float r, g, b, tailAsteroide;
public:
	SlowAsteroide(float x_ = 0.0, float y_ = 0.0, float r_ = 0.0, float g_ = 0.0, float b_ = 0.0, float tailAsteroide_ = 0.7) :
		Asteroide(x_, y_),
		r(r_), g(g_), b(b_), tailAsteroide(tailAsteroide_)
	{}
	
	virtual float getPosX();
	virtual float getPosY();
	virtual float getR();
	virtual float getG();
	virtual float getB();
	virtual float getTailAsteroide();
	virtual void setTailAsteroide(float newTailAst);
	virtual float getLifeAsteroide();
	virtual void setLifeAsteroide(float newLife);
	virtual void draw();
};