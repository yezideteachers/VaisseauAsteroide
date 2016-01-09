#include "SlowAsteroide.h"
#include "AsteroideForme.h"

float SlowAsteroide::getPosX(){
	return posX;
}
float SlowAsteroide::getPosY(){
	return posY;
}
float SlowAsteroide::getR(){
	return r;
}
float SlowAsteroide::getG(){
	return g;
}
float SlowAsteroide::getB(){
	return b;
}


float SlowAsteroide::getTailAsteroide(){
	return tailAsteroide;
}

void SlowAsteroide::setTailAsteroide(float newTailAst){
	tailAsteroide = newTailAst;
}

float SlowAsteroide::getLifeAsteroide(){
	return lifeAsteroide;
}
void SlowAsteroide::setLifeAsteroide(float newLife){
	lifeAsteroide = newLife;
}

void SlowAsteroide::draw(){
	AsteroideForme::polygone(getPosX(), (getPosY() - 0.09), getR(), getG(), getB(), 8, getTailAsteroide(), true);
	if (rand() % 2){
		AsteroideForme::losange(getPosX(), getPosY(), getR(), getG(), getB());
	}
}