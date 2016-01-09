#pragma once
class Player{
private:
	char *name;
	int money;
	int score;
	float x, y, width, height, r, g, b;
	
public:
	Player(char *name_,int money_=70, int score_=0, float x_ = -1.0, float y_ = 0.97, float width_ = 0.3, float height_ = 0.05, float r_ = 0.0f, float g_ = 0.0f, float b_ = 1.0f) :
		x(x_), y(y_), width(width_), height(height_), r(r_), g(g_), b(b_),name(name_),money(money_), score(score_){}

	char * getName();
	int	 getMoney();
	int getScore();
	void setName(char * newName);
	void setMoney(int newMoney);
	void setScore(int newScore);
	
	void drawLifeLine();
	/**
	verifie si la bare de vie est vide !
	si oui game over
	*/
	void verifyLife();
	void reset();
	virtual void draw();
};