#pragma once
#include "Engine.h"
#include "Grille.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Vaisseau.h"
#include "Player.h"

class MyControlEngine :public ControlEngine{
	std::vector<Grille * > *Grilles = new std::vector < Grille * >;;
	std::vector<Engin* > *missiles = nullptr;// new std::vector < Engin* > ;
	std::vector<Engin*> *asteroides = nullptr;// new std::vector < Engin* > ;
	std::vector<Engin*> *listVaisseaux = nullptr;// new  std::vector < Engin* > ;
	Player* player;

public:
	MyControlEngine();
	MyControlEngine(std::vector<Engin*> * missiles_, std::vector<Engin*> *listVaisseaux_, std::vector<Engin*> *asteroides_, Player* player_) :
		missiles(missiles_),
		listVaisseaux(listVaisseaux_),
		asteroides(asteroides_),
		player(player_){}
	~MyControlEngine();
	virtual void MouseCallback(int button, int state, int x, int y);
	void remplirVectVaisseaux(std::vector<Engin*> *v, std::vector<Case *> *c, int nbcase);
};