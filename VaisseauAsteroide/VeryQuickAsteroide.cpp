#include "VeryQuickAsteroide.h"
#include "AsteroideForme.h"

float VeryQuickAsteroide::getPosX(){
	return posX;
}
float VeryQuickAsteroide::getPosY(){
	return posY;
}
float VeryQuickAsteroide::getR(){
	return r;
}
float VeryQuickAsteroide::getG(){
	return g;
}
float VeryQuickAsteroide::getB(){
	return b;
}

bool VeryQuickAsteroide::getChild(){
	return child;
}

float VeryQuickAsteroide::getTailAsteroide(){
	return tailAsteroide;
}

void VeryQuickAsteroide::setChild(bool newChild){
	child = newChild;
}
void VeryQuickAsteroide::setTailAsteroide(float newTailAst){
	tailAsteroide = newTailAst;
}

float VeryQuickAsteroide::getLifeAsteroide(){
	return lifeAsteroide;
}
void VeryQuickAsteroide::setLifeAsteroide(float newLife){
	lifeAsteroide = newLife;
}

void VeryQuickAsteroide::draw(){
	if (getChild()){
		AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), getB(), 10, 0.3, true);
		AsteroideForme::polygone(getPosX() + 0.05, (getPosY() - 0.09), getR(), getG(), getB(), 10, 0.3, true);
		AsteroideForme::polygone(getPosX() + 0.1, (getPosY() - 0.09), getR(), getG(), getB(), 10, 0.3, true);
		setChild(true);
	}
	GraphicPrimitives::drawLine2D(getPosX() + 0.1, getPosY(), getPosX() - 0.1, getPosY() - 0.15, 1.0, 0.0, 0.0);
	GraphicPrimitives::drawLine2D(getPosX() - 0.1, getPosY(), getPosX() + 0.1, getPosY() - 0.15, 1.0, 0.0, 0.0);
	AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), 0.0, 12, getTailAsteroide(), true);
	if (rand() % 2){
		AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), 0.0, 6, getTailAsteroide(), true);
		AsteroideForme::losange(getPosX(), getPosY(), getR(), getG(), getB());
	}
	
}