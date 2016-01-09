#pragma once
#include "Player.h";
#include "Engin.h"
#include "StrongVaisseau.h"

class Play {

	

public:
	
	void drawCaseSelected();

	/**
	mettre à jour le jeux(la partie courante)
	*/
	void update(Player *player, std::vector<Engin *> *asteroides, std::vector<Engin *> *vaisseaux, std::vector<Engin *> *missiles);

	/**
	cette fonction permet de recuperer des informations sur le vaisseau qui a etait selectionné
	*/
	void vaisseauSelected(Player* player, float x, float y,float* r, float* g, float* b,bool* heSelected,int* numberSelect);

	/**
	verifie que la case selectionnée n'était pas selectionnée avant
	*/
	bool notSelected(std::vector<Engin *> *v, float x, float y);

	/**j'effectue le reset sur trois type de vecteur possible (Asteroide , Vaisseau ,Missile)
	pour ca j'utilise le template */
	template<class Type> void reset(Type *param);

	/**cette fonction elle sera appelée que dans les nouveaux difficile et expert.
	Elle permet d'empêcher le joueur de placer plus d'un vaisseau sur la meme colonne ,
	elle est faite pour augmenter le difficulté
	*/
	bool isInTheSameColonne(std::vector<Engin *> *v, float y);

	/**
	faire appraitre une case rouge sur la case selectionnée si elle est dejà occupé
	*/
	void drawCaseRed(std::vector<Case* > *c);
};