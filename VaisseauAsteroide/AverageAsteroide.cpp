#include "AverageAsteroide.h"
#include "AsteroideForme.h"


float AverageAsteroide::getPosX(){
	return posX;
}
float AverageAsteroide::getPosY(){
	return posY;
}
float AverageAsteroide::getR(){
	return r;
}
float AverageAsteroide::getG(){
	return g;
}
float AverageAsteroide::getB(){
	return b;
}

float AverageAsteroide::getTailAsteroide(){
	return tailAsteroide;
}

void AverageAsteroide::setTailAsteroide(float newTailAst){
	tailAsteroide = newTailAst;
}

float AverageAsteroide::getLifeAsteroide(){
	return lifeAsteroide;
}
void AverageAsteroide::setLifeAsteroide(float newLife){
	lifeAsteroide = newLife;
}

void AverageAsteroide::draw(){
	GraphicPrimitives::drawLine2D(getPosX() + 0.1, getPosY(), getPosX() - 0.1, getPosY() - 0.15, 1.0, 0.0, 0.0);
	GraphicPrimitives::drawLine2D(getPosX() - 0.1, getPosY(), getPosX() + 0.1, getPosY() - 0.15, 1.0, 0.0, 0.0);
	AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), 0.0, 12, getTailAsteroide(), true);
	if (rand() % 2){
		AsteroideForme::losange(getPosX(), getPosY(), getR(), getG(), getB());
	}
}