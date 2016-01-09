#include "HeavyVaisseau.h"

float HeavyVaisseau::getPosX(){
	return posX;
}
float HeavyVaisseau::getPosY(){
	return posY;
}

float HeavyVaisseau::getR(){
	return r;
}
float HeavyVaisseau::getG(){
	return g;
}
float HeavyVaisseau::getB(){
	return b;
}
int HeavyVaisseau::getLifeTime(){
	return lifetime;
}

void HeavyVaisseau::setPosX(float newX){
	posX = newX;
}
void HeavyVaisseau::setPosY(float newY){
	posY = newY;
}

void HeavyVaisseau::setR(float newR){
	r = newR;
}
void HeavyVaisseau::setG(float newG){
	g = newG;
}
void HeavyVaisseau::setB(float newB){
	b = newB;
}
/*edition de la bare de vie*/
void HeavyVaisseau::setLifeTime(int newLifeTime){
	lifetime = newLifeTime;
}
void HeavyVaisseau::draw(){
	Vaisseau::draw();
}