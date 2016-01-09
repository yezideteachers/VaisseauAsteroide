#include "Player.h"
#include "Engine.h"
#include "MyGraphicEngine.h"
#include <sstream>

char * Player::getName(){
	return name;
}
int	 Player::getMoney(){
	return money;
}
int Player::getScore(){
	return score;
}

void Player::setName(char * newName){
	name = newName;
}
void Player::setMoney(int newMoney){
	money = newMoney;
}
void Player::setScore(int newScore){
	score = newScore;
}

void Player::draw(){
	GraphicPrimitives::drawText2D("player :", 0.3, 0.95, 1.0f, 1.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D(name, 0.46, 0.95, 1.0f, 1.0f, 1.0f, 1.0f);
	char *moneyString = new char[10];
	char *scoreString = new char[10];
	char *levelString = new char[10];

	GraphicPrimitives::drawText2D("Money :", 0.3, 0.9, 1.0f, 1.0f, 0.0f, 1.0f);
	_itoa_s(getMoney(), moneyString, 10, 10);
	GraphicPrimitives::drawText2D(moneyString, 0.46, 0.9, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("eur", 0.55, 0.9, 1.0f, 1.0f, 1.0f, 1.0f);
	_itoa_s(getScore(), scoreString, 10, 10);
	GraphicPrimitives::drawText2D("Score", 0.3, 0.85, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(scoreString, 0.46, 0.85, 1.0f, 1.0f, 1.0f, 1.0f);
	_itoa_s(Part::getLevel(), levelString, 10, 10);
	GraphicPrimitives::drawText2D("level :", -1.0, 0.85, 1.0f, 0.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D(levelString, -0.88, 0.85, 1.0f, 0.0f, 0.0f, 1.0f);

	GraphicPrimitives::drawFillRect2D(0.7, 0.8, 0.30, 0.12, 1.0, 0.4, 1.0, 1.0);
	GraphicPrimitives::drawText2D("quit", 0.86, 0.85, 1.0f, 0.0f, 0.0f, 1.0f);

	delete moneyString;
	delete scoreString;
	delete levelString;
}


void Player::drawLifeLine(){
	GraphicPrimitives::drawFillRect2D(x, y, width, height, r, g, b, 1.0);
	GraphicPrimitives::drawText2D("life bar ", -1.0, 0.92, 1.0f, 1.0f, 1.0f, 1.0f);
}

/**
verifie si la bare de vie est vide !
si oui game over
*/
void Player::verifyLife(){
	if (width <= 0){
		if (MessageBox(NULL, "You lost \n", "GAME OVER", 0) == 1)
		{
			exit(0);
		}
	}
	else{
		width -= 0.01;
		r += 0.2;
		b -= 0.2;
	}
}

void Player::reset(){
	width = 0.3;
	r = 0.0;
	b = 1.0;
	switch (Part::getLevel()){
	case 1: {setMoney(100); break; }
	case 2: {setMoney(120); break; }
	case 3: {setMoney(150); break; }
	case 4: {setMoney(170); break; }
	case 5: {setMoney(190); break; }
	case 6: {setMoney(210); break; }
	}

}