#pragma once
#include "Player.h";
#include "Engin.h"
#include "StrongVaisseau.h"

class Play {

	

public:
	
	void drawCaseSelected();

	/**
	mettre � jour le jeux(la partie courante)
	*/
	void update(Player *player, std::vector<Engin *> *asteroides, std::vector<Engin *> *vaisseaux, std::vector<Engin *> *missiles);

	/**
	cette fonction permet de recuperer des informations sur le vaisseau qui a etait selectionn�
	*/
	void vaisseauSelected(Player* player, float x, float y,float* r, float* g, float* b,bool* heSelected,int* numberSelect);

	/**
	verifie que la case selectionn�e n'�tait pas selectionn�e avant
	*/
	bool notSelected(std::vector<Engin *> *v, float x, float y);

	/**j'effectue le reset sur trois type de vecteur possible (Asteroide , Vaisseau ,Missile)
	pour ca j'utilise le template */
	template<class Type> void reset(Type *param);

	/**cette fonction elle sera appel�e que dans les nouveaux difficile et expert.
	Elle permet d'emp�cher le joueur de placer plus d'un vaisseau sur la meme colonne ,
	elle est faite pour augmenter le difficult�
	*/
	bool isInTheSameColonne(std::vector<Engin *> *v, float y);

	/**
	faire appraitre une case rouge sur la case selectionn�e si elle est dej� occup�
	*/
	void drawCaseRed(std::vector<Case* > *c);
};