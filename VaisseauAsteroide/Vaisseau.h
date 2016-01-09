#pragma once
#include "GraphicPrimitives.h"
#include "Case.h"
#include "Missile.h"
#include "Engin.h"

class Vaisseau :public Engin{

protected:
	float posX2, posY2, posX3, posY3;
	float r, g, b;
	float speedMissile;
	float prix;
	bool superPower;
	int lifetime;


public:
	int dimens;
	Vaisseau();
	~Vaisseau();
	std::vector<Missile *> *missilesV = new std::vector <Missile * >;
	Vaisseau(float posX1_, float posY1_, float r_, float g_, float b_, Missile *missile_ = nullptr) :
		Engin(posX1_,posY1_), posX2(posX), posY2(posY + 0.16), posX3(posX + 0.16), posY3(posY + 0.08), r(r_), g(g_), b(b_),
		mis(missile_), speedMissile(0.0), superPower(false), lifetime(1)
	{
		missilesV->push_back(mis);
	}
	
	Missile *mis;
	virtual void draw();
	//Getter
	virtual float getPosX();
	virtual float getPosY();
	float getPosX2();
	float getPosY2();
	float getPosX3();
	float getPosY3();
	virtual float getVposX();
	virtual float getVposY();
	virtual float getR();
	virtual float getG();
	virtual float getB();
	float getSpeedMissile();
	int getPrice();
	virtual bool getSuperPower();
	virtual int getLifeTime();

	//Setter
	virtual void setPosX(float newX);
	virtual void setPosY(float newY);
	void setPosX2(float newX);
	void setPosY2(float newY);
	void setPosX3(float newX);
	void setPosY3(float newY);
	virtual void setR(float newR);
	virtual void setG(float newG);
	virtual void setB(float newB);
	virtual void setVposX(float vPos);
	virtual void setVposY(float vPos);
	void setSuperPower(bool superPower_);
	void setLifeTime(int newLifeTime);
	void setSpeedMissile(int newSpeed);
	void setPrice(int newPrice);
	virtual void tick();
};