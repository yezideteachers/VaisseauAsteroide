#pragma once
#include "Missile.h"
#include "Asteroide.h"
#include "Vaisseau.h"
#include "Player.h"

class Collision{

public:
	/**
	cette fonction permet de verifier si le deux engins sont sur la meme ligne,
	j'utilise pour ca le template
	*/
	template<typename type1, typename type2> bool isinTheSameLigne(type1 *ast, type2 *miss);
	
	/**
	cette fonction permet de gerer ma collision entre asteroide et missile ou asteroide et vaisseau.
	en utilisant le template pour les deux type possibles (Vaissau , Missile)
	*/
	template<class Type>bool isCollided(Asteroide *ast, Type * vaisseauORMissile);

	/**
	cette fonction permet de dessiner les vaisseaux les missiles et 
	gere les collisions entre asteroides vaisseaux et asteroides missiles
	*/
	void drawAndManageCollision(std::vector<Engin *> *ast, std::vector<Engin *> *vais, Player* player);

	/**
	cette fonction permet de dessiner les asteroides 
	et gère les collisions entre asteroides le bord gauche du canvas
	*/
	void drawAndverifyBoard(std::vector<Engin *> *ast, Player* player, int choice);

	/**cette fonction gere la decrementation de la bare de vie
	en fonction de missile(force de missile)
	*/
	void decreasesLife(Asteroide* ast, double widthMissile, bool forR);

	/**
	supprimer Engin qui peut etre missile, Asteroide ou vaisseau,
	j'utilise pour ca le template
	*/
	template<class Type> void deleteEngin(Type *missiles, int index);

};