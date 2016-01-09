#include "StrongVaisseau.h"

float StrongVaisseau::getPosX(){
	return posX;
}
float StrongVaisseau::getPosY(){
	return posY;
}

float StrongVaisseau::getR(){
	return r;
}
float StrongVaisseau::getG(){
	return g;
}
float StrongVaisseau::getB(){
	return b;
}
int StrongVaisseau::getLifeTime(){
	return lifetime;
}

void StrongVaisseau::setPosX(float newX){
	posX = newX;
}
void StrongVaisseau::setPosY(float newY){
	posY = newY;
}

void StrongVaisseau::setR(float newR){
	r = newR;
}
void StrongVaisseau::setG(float newG){
	g = newG;
}
void StrongVaisseau::setB(float newB){
	b = newB;
}
/*edition de la bare de vie*/
void StrongVaisseau::setLifeTime(int newLifeTime){
	lifetime = newLifeTime;
}
void StrongVaisseau::draw(){
	Vaisseau::draw();
}
/*activer le super pouvoir , accessible dans le niveau 3 et 4,
ce super est une bare qui apparait dans la fenetre detruisant tout les asteroides qui sont déjà lancer*/
bool StrongVaisseau::getSuperPower(){
	return superPower;
}

void StrongVaisseau::setSuperPower(bool superPower_){
	superPower = superPower_;
}
