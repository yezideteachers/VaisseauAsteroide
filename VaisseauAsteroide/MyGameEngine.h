#pragma once

#include "Engine.h"
#include "Missile.h"
#include "Grille.h"
#include "Asteroide.h"
#include "Vaisseau.h"
#include "Player.h"


class MyGameEngine :public GameEngine {
public:
	std::vector<Grille * > *Grilles = new std::vector < Grille * >;;
	std::vector<Engin* > *missiles = nullptr;// new std::vector < Engin* > ;
	std::vector<Engin*> *asteroides = nullptr;// new std::vector < Engin* > ;
	std::vector<Engin*> *vaisseaux = nullptr;// new  std::vector < Engin* > ;
	Player *player = nullptr;
	float coordAst[10];
	
	MyGameEngine();

	MyGameEngine(std::vector<Engin* > * asteroides_, std::vector<Engin*> * missilies_, std::vector<Engin*> *vaisseaux_,Player *player_) :
		
		asteroides(asteroides_),
		missiles(missilies_),
		vaisseaux(vaisseaux_),
		player(player_)

	{
		/**stocker les ccordonnées d'une ligne de la grille pour le lancement des vagues*/
		float n = -0.82;
		for (int i = 0; i < 10; i++){
			coordAst[i] = n;
			n += 0.18;
		}
	}
	~MyGameEngine();
	virtual void idle();
	/**cette fonction gere la frequence d'envoie des missiles
	*/
	int fire(int freq);

	/**cette fonctions nous permet de savoir si il ya plus d'asteroides, 
	dans ce cas on arrête les missiles pour economiser de missile
	*/
	bool stopFire(int sizeVectAst);

	/*static std::vector<Asteroide *>* convertToAsteroide(std::vector<Engin *> *engin);
	static std::vector<Missile *>* convertToMissile(std::vector<Engin *> *engin);
	static std::vector<Vaisseau *>* convertToVaisseau(std::vector<Engin *> *engin);*/
};
