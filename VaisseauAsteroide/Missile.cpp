#include "Missile.h"
#include "Asteroide.h"

int Missile::dimensionMissile = 0.01;

void Missile::drawMissile(){
	
	GraphicPrimitives::drawFillRect2D(posX, posY, getWidth(), getHeight(), 1.0f, 0.0f, 0.0f);
}
Missile::~Missile(){}

float Missile::getPosX(){
	return posX;
}
float Missile::getPosY(){
	return posY;
}
float Missile::getVposX(){
	return VposX;
}
float Missile::getVposY(){
	return VposY;
}
float Missile::getR(){
	return r;
}
float Missile::getG(){
	return g;
}
float Missile::getB(){
	return b;
}

float Missile::getWidth(){
	return width;
}
float Missile::getHeight(){
	return height;
}
float Missile::getDimensionMissile(){
	return dimensionMissile;
}

void  Missile::setPosX(float newPosX){
	posX = newPosX;
}
void  Missile::setPosY(float newPosY){
	posY = newPosY;
}
void Missile::setVposX(float newVposX){
	VposX = newVposX;
}
void Missile::setVposY(float newVposY){
	VposY = newVposY;
}

void Missile::setR(float newR){
	r = newR;
}
void Missile::setG(float newG){
	g = newG;
}
void Missile::setB(float newB){
	b = newB;
}

void  Missile::setWidth(float newWidth){
	width = newWidth;
}
void  Missile::setHeight(float newHeight){
	height = newHeight;
}

void Missile::setDimensionMissile(int newDimension){
	dimensionMissile = newDimension;
}

void Missile::tick(){

	setPosX(getPosX() + getVposX());
}

void Missile::draw(){

}