#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Case.h"
#include "Vaisseau.h"
#include "Player.h"
#include "Part.h"


using namespace std;

class MyGraphicEngine :public GraphicEngine {

public:
	std::vector<Case * > *cases = new std::vector < Case * > ;
	std::vector < Engin* > *missiles = nullptr;// new std::vector < Engin* > ;
	std::vector < Engin* > *asteroides = nullptr;// new std::vector < Engin* > ;
	std::vector < Engin* > *vaisseaux = nullptr;// new  std::vector < Engin* > ;
	Player* player;

	int n = 0;
	MyGraphicEngine();

	MyGraphicEngine(std::vector<Engin* > * asteroides_, std::vector<Engin*> * missiles_, std::vector<Engin*> * vaisseaux_, Player* player_) :
		
		asteroides(asteroides_),
		missiles(missiles_),
		vaisseaux(vaisseaux_),
		player(player_)
	{
		
		
		MessageBox(NULL, "Le jeux va commencer . veuillez choisir vos vaisseaux \n et lancer les vagues d'asteroides", "DEFENDER", 0);
	}
	~MyGraphicEngine();

	virtual void Draw();
	void traceRedLine();
	virtual void reshape(int width, int height);



};


