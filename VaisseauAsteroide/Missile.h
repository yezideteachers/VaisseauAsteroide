#pragma once
#include "GraphicPrimitives.h"
#include "Engin.h"

 class Missile :public Engin{
 private:
	 float width, height,r,g,b;
	 static int dimensionMissile;
public:
	
	Missile(float posX_ = 0.0f, float posY_ = 0.0f,float width_=0.02,float height_=0.01,float VposX_=0.002) :
		Engin(posX_,posY_,VposX_),
		width(width_),
		height(height_), r(0.0), g(0.0), b(0.0)
	{}

	~Missile();

	virtual float getPosX();
	virtual float getPosY();
	virtual float getVposX();
	virtual float getVposY();
	float getR();
	float getG();
	virtual float getB();
	float getWidth();
	float getHeight();
	/*cette fonction renvoie la dimension du missile,
		or chaque vaisseau a des missiles de taille différentes  */
	static float getDimensionMissile();
	/*cette fonction modifie la dimension du missile,
	or chaque vaisseau a des missiles de taille différentes  */
	static void setDimensionMissile(int newDimension);
	virtual void  setPosX(float newPosX);
	virtual void  setPosY(float newPosY);
	virtual void setVposX(float newVposX);
	virtual void setVposY(float newVposY);
	virtual void setR(float newR);
	virtual void setG(float newG);
	virtual void setB(float newB);
	void  setWidth(float newWidth);
	void setHeight(float newHeight);
	void drawMissile();
	virtual void tick();
	virtual void draw();
};