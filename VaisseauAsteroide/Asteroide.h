#pragma once
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "Vaisseau.h"
#include "Engin.h"
#include "AsteroideForme.h"

class Asteroide :public Engin{

protected:
	float r, g, b;
	float posX,posY,vposX,vposY,child,tailAsteroide,lifeAsteroide;
	

public:

	Asteroide(float posX_ = 0.0f, float posY_ = 0.0f, float vposX_ = 0.001, float vposY_ = 0.0, bool child_ = false, float tailAsteroide_ = 0.7,float lifeAsteroide_=1.0) :
		Engin(posX_, posY_, 0.003, 0.02),
		posX(posX_), posY(posY_), vposX(vposX_), vposY(vposY_),
		r(.0f), g(0.0f), b(0.0f), child(child_), tailAsteroide(tailAsteroide_), lifeAsteroide(lifeAsteroide_)
	{}

	~Asteroide();


	virtual float getPosX();
	virtual float getPosY();
	virtual float getVposX();
	virtual float getVposY();
	virtual float getR();
	virtual float getG();
	virtual float getB();
	/*renvoie le child (petits asteroide) ,
	 cette fonction est appelée dans les niveux 3 et 4*/
	virtual bool getChild();
	/*chaque asteroide a une taille differente, et sa taille diminue au moment de collision*/
	virtual float getTailAsteroide();
	virtual void  setPosX(float newPosX);
	virtual void  setPosY(float newPosY);
	virtual void setVposX(float newVposX);
	virtual void setVposY(float newVposY);
	virtual void draw();
	virtual void tick();
	virtual void setChild(bool newchild);
	virtual void setTailAsteroide(float newTailAst);
	virtual void setR(float newR);
	virtual void setG(float newG);
	virtual void setB(float newB);
	virtual float getLifeAsteroide();
	virtual void setLifeAsteroide(float newLife);
	void drawAsteroide();
	/*si l'ateroide s'est échapé*/
	bool heFreed();
	AsteroideForme listA;
	template<class Type> void choseAsteride(Type *asteroides);

};