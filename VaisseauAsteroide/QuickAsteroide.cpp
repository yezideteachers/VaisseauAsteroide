#include "QuickAsteroide.h"
#include "AsteroideForme.h"

bool decomp = false;

float QuickAsteroide::getPosX(){
	return posX;
}
float QuickAsteroide::getPosY(){
	return posY;
}
float QuickAsteroide::getR(){
	return r;
}
float QuickAsteroide::getG(){
	return g;
}
float QuickAsteroide::getB(){
	return b;
}

bool QuickAsteroide::getChild(){
	return child;
}

float QuickAsteroide::getTailAsteroide(){
	return tailAsteroide;
}

void QuickAsteroide::setChild(bool newChild){
	child = newChild;
}
void QuickAsteroide::setTailAsteroide(float newTailAst){
	tailAsteroide = newTailAst;
}

float QuickAsteroide::getLifeAsteroide(){
	return lifeAsteroide;
}
void QuickAsteroide::setLifeAsteroide(float newLife){
	lifeAsteroide = newLife;
}

void QuickAsteroide::draw(){
	
	if (getChild()){
		AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), getB(), 10, 0.3, true);
		AsteroideForme::polygone(getPosX() + 0.1, (getPosY() - 0.09), 1.0, 0.0, 1.0, 10, 0.3, true);
		AsteroideForme::polygone(getPosX() + 0.2, (getPosY() - 0.09), 0.0, 0.0, 1.0, 10, 0.3, true);
		setChild(false);
	}
	else{
		GraphicPrimitives::drawLine2D(getPosX() + 0.1, getPosY(), getPosX() - 0.1, getPosY() - 0.15, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawLine2D(getPosX() - 0.1, getPosY(), getPosX() + 0.1, getPosY() - 0.15, 1.0, 0.0, 0.0);
		AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), 0.0, 10,getTailAsteroide(), true);
		AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), 0.0, 8, getTailAsteroide()-0.1, true);
		if (rand() % 2){
			AsteroideForme::losange(getPosX(), getPosY(), getR(), getG(), getB());
		}
	}

}