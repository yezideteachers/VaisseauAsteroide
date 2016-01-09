#pragma once
#include "Vaisseau.h"
#include "Player.h"

class ListVaisseau{
	std::vector<Vaisseau *> *listV;
public:
	ListVaisseau(std::vector<Vaisseau *> *listV_ = nullptr):
		listV(listV_)
	{}
	std::vector<Vaisseau *> *getLisvaisseaux();
	void setListVaisseaux(std::vector<Vaisseau *> *newListV);
	/**
	cette fonction ajoute les trois vaisseaux au choix
	*/
	 void fillListVaisseaux(std::vector<Vaisseau *> *listV, Player *player);

};