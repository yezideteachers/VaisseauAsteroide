#include "Bomb.h"
#include <vector>
#include "GraphicPrimitives.h"

#define PI 3.141592653589

bool Bomb::launch = false;

/**getter*/
float Bomb::getX(){
	return x;
}
float Bomb::getY(){
	return y;
}
float Bomb::getVX(){
	return vx;
}
float Bomb::getVY(){
	return vy;
}
float Bomb::getR(){
	return r;
}
float Bomb::getG(){
	return g;
}
float Bomb::getB(){
	return b;
}


/**setter*/
void Bomb::setX(float newX){
	x = newX;
}
void Bomb::setY(float newY){
	y = newY;
}

void Bomb::setR(float newR){
	r = newR;
}
void Bomb::setG(float newG){
	g = newG;
}
void Bomb::setB(float newB){
	b = newB;
}

/**afichage de la bombe*/
void Bomb::draw(int n, float rad, bool fill){
	float x_ = 0.0;
	float y_ = 0.0;
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;
	float a = atan2(y_ - y, x_ - x);
	int i;
	for (int j = 0; j < 3; j++)
	{
		for (i = 1; i <= n; i++) {
			a = a + PI * 2 / n;
			x_ = x + (rad * cos(a) / 6);
			y_ = y + (rad * sin(a) / 6);
			vx->push_back(x_); vy->push_back(y_);
		}
		if (fill){ GraphicPrimitives::drawFillPolygone2D(*vx, *vy, r, g, b, 1.0f); }
		else{ GraphicPrimitives::drawOutlinedPolygone2D(*vx, *vy, r, g, b, 1.0f); }
		if (rad == 0.1){ break; }
		rad = rad-0.1;
		setR(1.0);
		vx->clear();
		vy->clear();
	}
	delete vx, vy;


}

/*exploser la bombe*/
void Bomb::detonateBomb(std::vector<Engin *> *asteroides){
	float *coords = new float[6];
	coords[0] = -0.8; coords[1] = -0.5; coords[2] = -0.2; coords[3] = 0.1; coords[4] = 0.4; coords[5] = 0.7;
	float rx = coords[(rand() % 6) + 1];
	float ry = coords[(rand() % 6) + 1];
	for (int i = 0; i < 2; i++){
		setX(rx + (((rand() % 3) - 1.0)/10.0));
		setY(ry + (((rand() % 3) - 1.0) / 10.0));
		draw(12, 0.3, true);

		for (int j = 0; j < asteroides->size(); j++)
		{
			if ((abs(abs((*asteroides)[j]->getPosX()) - abs(getX())) <= 0.1)
				&& (abs(abs((*asteroides)[j]->getPosY()) - abs(getY())) <= 0.1)){
				if (asteroides->size()>1){ std::swap((*asteroides)[j], asteroides->back()); asteroides->pop_back(); }
			}
		}
	}
}