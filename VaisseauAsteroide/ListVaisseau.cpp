#include "ListVaisseau.h"
#include "Part.h"
#include "Bomb.h"
std::vector<Vaisseau *> *ListVaisseau::getLisvaisseaux(){
	return listV;
}

void ListVaisseau::setListVaisseaux(std::vector<Vaisseau *> *newListV){
	listV = newListV;
}

/**
cette fonction ajoute les trois vaisseaux au choix et dessine la bombe qui sera utilisée dans les niveaux >=3
*/
void ListVaisseau::fillListVaisseaux(std::vector<Vaisseau *> *listV,Player *player){
	Bomb *b=new Bomb(0.1,0.9);
	GraphicPrimitives::drawFillRect2D(-0.6, 0.8, 0.6, 0.2, 0.5f, 0.0f, 1.0f);
	GraphicPrimitives::drawFillRect2D(0.02, 0.8, 0.18, 0.2, 0.0f, 0.5f, 1.0f);
	if (Part::getLevel() >= 2){
		/*si la bombe peut etre lancer je l'affiche*/
		if (player->getMoney() >= 15){
			b->draw(12, 0.3, true);
		}
		/**elle ne peut pas être selectionné*/
		else{ 
			GraphicPrimitives::drawLine2D(0.0, 0.8, 0.2, 1.0, 1.0, 0.0, 0.0);
			GraphicPrimitives::drawLine2D(0.0, 1.0, 0.2, 0.8, 1.0, 0.0, 0.0); 
			b->draw(12, 0.3, true);
		}
		GraphicPrimitives::drawText2D("bombe 15eur", 0.0, 0.97, 1.0, 0.0, 0.0);
		delete b;

	}
	else{
		GraphicPrimitives::drawText2D("Bomb", 0.05, 0.95, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("next levels", 0.03, 0.87, 1.0, 0.0, 0.0);
	}
	listV->push_back(new Vaisseau(-0.6, 0.8, 1.0f, 0.5f, 0.0f)); (*listV)[0]->setPrice(10);
	listV->push_back(new Vaisseau(-0.4, 0.8, 0.0f, 0.0f, 0.5f)); (*listV)[1]->setPrice(20);
	listV->push_back(new Vaisseau(-0.2, 0.8, 0.5f, 1.0f, 0.5f)); (*listV)[2]->setPrice(30);
	}