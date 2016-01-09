#pragma once
#include "Engin.h"

class Bomb{
protected:
	float x, y, vx, vy,r,g,b;
public:
	Bomb(float x_ = 0.0, float y_ = 0.0, float vx_ = 0.3, float vy_ = 0.3, float r_ = 0.0, float g_ = 0.0, float b_ = 0.0) :
		x(x_), y(y_), vx(vx_), vy(vy_), r(r_), g(g_), b(b_)
	{}
	static bool launch;
	/**getter*/
	float getX();
	float getY();
	float getVX();
	float getVY();
	float getR();
	float getG();
	float getB();
	/**setter*/
	void setX(float newX);
	void setY(float newY);
	void setR(float newR);
	void setG(float newG);
	void setB(float newB);

	/**afichage de la bombe*/
	void draw(int n, float rad, bool fill);

	/*exploser la bomb*/
	void detonateBomb(std::vector<Engin *> *asteroides);
};