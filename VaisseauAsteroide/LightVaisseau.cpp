#include "LightVaisseau.h"

float LightVaisseau::getPosX(){
	return posX;
}
float LightVaisseau::getPosY(){
	return posY;
}

float LightVaisseau::getR(){
	return r;
}
float LightVaisseau::getG(){
	return g;
}
float LightVaisseau::getB(){
	return b;
}
int LightVaisseau::getLifeTime(){
	return lifetime;
}

void LightVaisseau::setPosX(float newX){
	posX = newX;
}
void LightVaisseau::setPosY(float newY){
	posY = newY;
}

void LightVaisseau::setR(float newR){
	r = newR;
}
void LightVaisseau::setG(float newG){
	g = newG;
}
void LightVaisseau::setB(float newB){
	b = newB;
}
/*edition de la bare de vie*/
void LightVaisseau::setLifeTime(int newLifeTime){
	lifetime = newLifeTime;
}
void LightVaisseau::draw(){
	Vaisseau::draw();
}