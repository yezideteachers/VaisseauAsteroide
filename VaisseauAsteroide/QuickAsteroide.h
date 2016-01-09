#pragma once
#include "Asteroide.h"

class QuickAsteroide :public Asteroide{

private:
	float r, g, b;
	float child, tailAsteroide;
public:
	QuickAsteroide(float x_ = 0.0, float y_ = 0.0, float r_ = 0.0, float g_ = 0.0, float b_ = 1.0,bool child_=false,float tailAsteroide_=0.7) :
		Asteroide(x_, y_),
		r(r_), g(g_), b(b_), child(child_), tailAsteroide(tailAsteroide_)
	{}

	virtual float getPosX();
	virtual float getPosY();
	virtual float getR();
	virtual float getG();
	virtual float getB();
	virtual bool getChild();
	virtual float getTailAsteroide();
	virtual void setChild(bool newChild);
	virtual float getLifeAsteroide();
	virtual void setLifeAsteroide(float newLife);
	virtual void setTailAsteroide(float newTailAst);
	virtual void draw();
};