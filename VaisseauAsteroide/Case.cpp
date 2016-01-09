#include "Case.h"

Case::~Case(){

}

//function draw 
void Case::draw(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);
}
//Getter
float Case::getPosX(){
	return posX;
}
float Case::getPosY(){
	return posY;
}
float Case::getWidth(){
	return width;
}
float Case::getHeight(){
	return height;
}
float Case::getR(){
	return r;
}
float Case::getG(){
	return g;
}
float Case::getB(){
	return b;
}

//Setter
void Case::setposX(float newX){
	posX = newX;
}
void Case::setposY(float newY){
	posX = newY;
}
void Case::setWidth(float newW){
	width = newW;
}
void Case::setHeight(float newH){
	height = newH;
}
void Case::setR(float newR){
	r = newR;
}
void Case::setG(float newG){
	g = newG;
}
void Case::setB(float newB){
	b = newB;
}