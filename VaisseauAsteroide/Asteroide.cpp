#include "Asteroide.h"
#include "AverageAsteroide.h"
#include "QuickAsteroide.h"
#include "SlowAsteroide.h"
#include "VeryQuickAsteroide.h"
#include "Part.h"
using namespace std;

Asteroide::~Asteroide(){
	
}

float Asteroide::getPosX(){
	return posX;
}
float Asteroide::getPosY(){
	return posY;
}
float Asteroide::getVposX(){
	return vposX;
}
float Asteroide::getVposY(){
	return vposY;
}
float Asteroide::getR(){
	return r;
}
float Asteroide::getG(){
	return g;
}
float Asteroide::getB(){
	return b;
}

bool Asteroide::getChild(){
	return child;
}

float Asteroide::getTailAsteroide(){
	return tailAsteroide;
}

void  Asteroide::setPosX(float newPosX){
	posX = newPosX;
}
void  Asteroide::setPosY(float newPosY){
	posY = newPosY;
}
void Asteroide::setVposX(float newVposX){
	vposX = newVposX;
}
void Asteroide::setVposY(float newVposY){
	vposY = newVposY;
}
void Asteroide::setR(float newR){
	r = newR;
}
void Asteroide::setG(float newG){
	g = newG;
}
void Asteroide::setB(float newB){
	b = newB;
}

void Asteroide::setChild(bool newchild){
	child = newchild;
}

void Asteroide::setTailAsteroide(float newTailAst){
	tailAsteroide = newTailAst;
}

void Asteroide::draw(){
	//listA.lunchVague(getPosX(),getPosY(),getR(),getG(), getB(),getchild());
	Asteroide *ast=nullptr;
	if (Part::getLevel() == 1){
		ast = new SlowAsteroide(getPosX(), getPosY(), getR(), getG(), getB(),getTailAsteroide());
		choseAsteride(ast);
	}
	else if (Part::getLevel() == 2){
		ast = new AverageAsteroide(getPosX(), getPosY(), getR(), getG(), getB(),getTailAsteroide());
		choseAsteride(ast);
	}
	else if (Part::getLevel() == 3){
		ast = new QuickAsteroide(getPosX(), getPosY(), getR(), getG(), getB(),getChild(), getTailAsteroide());
		ast->setChild(getChild());
		choseAsteride(ast);
		
	}
	else if (Part::getLevel() == 4){
		ast = new VeryQuickAsteroide(getPosX(), getPosY(), getR(), getG(), getB(), getChild(), getTailAsteroide());
		ast->setChild(getChild());
		choseAsteride(ast);
	}
	else if (Part::getLevel() == 5){
		ast = new VeryQuickAsteroide(getPosX(), getPosY(), getR(), getG(), getB(), getChild(), getTailAsteroide());
		ast->setChild(getChild());
		choseAsteride(ast);
	}
	else if (Part::getLevel() == 6){
		ast = new VeryQuickAsteroide(getPosX(), getPosY(), getR(), getG(), getB(), getChild(), getTailAsteroide());
		ast->setChild(getChild());
		choseAsteride(ast);
	}
	else if (Part::getLevel() == 7){
		ast = new VeryQuickAsteroide(getPosX(), getPosY(), getR(), getG(), getB(), getChild(), getTailAsteroide());
		ast->setChild(getChild());
		choseAsteride(ast);
	}
	else{
		cout << "problem rencontrer ! " << endl << "veuillez relancer le jeux" << endl;
	}
	delete ast;
}
/*si l'ateroide s'est échapé*/
bool Asteroide::heFreed(){
	if (getPosX() <= -0.9){
		return true;
	}
	return false;
}

void Asteroide::tick(){
	switch (Part::getLevel()){
	case 1:
	{posX -= (getVposX() + 0.0003); break; }
	case 2:
	{posX -= (getVposX()+0.0006); break; }
	case 3:
	{posX -= (getVposX()+0.001); break; }
	case 4:
	{posX -= (getVposX()+0.0015); break; }
	case 5:
	{posX -= (getVposX() + 0.0001); break; }
	case 6:
	{posX -= (getVposX() + 0.00012); break; }
	case 7:
	{posX -= (getVposX() + 0.00014); break; }
	}

}

float Asteroide::getLifeAsteroide(){
	return lifeAsteroide;
}
void Asteroide::setLifeAsteroide(float newLife){
	lifeAsteroide = newLife;
}

template<class Type> void Asteroide::choseAsteride(Type *asteroides){
	asteroides->draw();
}