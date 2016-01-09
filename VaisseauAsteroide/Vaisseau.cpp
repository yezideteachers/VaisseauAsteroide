#include "Vaisseau.h"

#define PI 3.141592653589

void Vaisseau::draw(){

	GraphicPrimitives::drawFillTriangle2D(posX, posY, posX2, posY2, posX3, posY3, r, g, b);
}

Vaisseau::~Vaisseau(){
	delete missilesV;
}

//Getter
float Vaisseau::getPosX(){
	return posX;
}
float Vaisseau::getPosY(){
	return posY;
}
float Vaisseau::getPosX2(){
	return posX2;
}
float Vaisseau::getPosY2(){
	return posY2;
}
float Vaisseau::getPosX3(){
	return posX3;
}
float Vaisseau::getPosY3(){
	return posY3;
}
float Vaisseau::getR(){
	return r;
}
float Vaisseau::getG(){
	return g;
}
float Vaisseau::getB(){
	return b;
}

int Vaisseau::getLifeTime(){
	return lifetime;
}

float Vaisseau::getVposX(){
	return VposX;
}
float Vaisseau::getVposY(){
	return VposY;
}

float Vaisseau::getSpeedMissile(){
	return speedMissile;
}
int Vaisseau::getPrice(){
	return prix;
}

bool Vaisseau::getSuperPower(){
	return superPower;
}


//Setter
void Vaisseau::setPosX(float newX){
	posX = newX;
}
void Vaisseau::setPosY(float newY){
	posY = newY;
}
void Vaisseau::setPosX2(float newX){
	posX2 = newX;
}
void Vaisseau::setPosY2(float newY){
	posY2 = newY;
}
void Vaisseau::setPosX3(float newX){
	posX3 = newX;
}
void Vaisseau::setPosY3(float newY){
	posY3 = newY;
}
void Vaisseau::setR(float newR){
	r = newR;
}
void Vaisseau::setG(float newG){
	g = newG;
}
void Vaisseau::setB(float newB){
	b = newB;
}
void Vaisseau::setVposX(float vx){
	VposX = vx;
}
void Vaisseau::setVposY(float vy){
	VposY = vy;
}
void Vaisseau::setSpeedMissile(int newSpeed){
	speedMissile = newSpeed;
}
void Vaisseau::setPrice(int newPrice){
	prix = newPrice;
}
void Vaisseau::setSuperPower(bool superPower_){
	superPower = superPower_;
}


void Vaisseau::setLifeTime(int newLifeTime){
	lifetime = newLifeTime;
}

void Vaisseau::tick(){
	for (int i = 0; i < missilesV->size(); i++){
		(*missilesV)[i]->Missile::setPosX((*missilesV)[i]->Missile::getPosX() + 0.03);
	}
}


