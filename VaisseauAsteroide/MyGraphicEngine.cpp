#include <string>
#include "stdio.h"
#include "stdlib.h"
#include "MyGraphicEngine.h"
#include "Case.h"
#include "Collision.h"
#include "ListVaisseau.h"
#include "AsteroideForme.h"
#include "Player.h"
#include "Play.h"
#include "Bomb.h"
#include "Grille.h"
#include <time.h>
#include "DimensionWindow.h"

#define PI 3.141592653589

using namespace std;
int comp = 0;

Collision *collision;
Play play;
ListVaisseau *listV;
AsteroideForme listA;
Grille grille;
Bomb bomb;
int choice = 0;
int timeOfBomb = 0;
char *priceS = new char[10];
DWORD penalTime = GetTickCount();
std::vector<Vaisseau * > *choixVaisseau ;

void MyGraphicEngine::Draw(){
	
	
	/**
	appele de la fonction update pour mettre à jour le jeux
	*/
	play.update(player, asteroides, vaisseaux,missiles);

	/*si les vagues sont tous lancées, 
	on affiche le message fin de partie*/
	Part::partieFnished();



	choixVaisseau = new std::vector < Vaisseau * >;
	grille.draw(cases);
	
	listA.lunchAst();

	/**
	dessiner les asteroides
	et gerer les collisions entre asteroides et le bord gauche du canvas
	*/
	collision->drawAndverifyBoard(asteroides, player, choice);

	/**
	dessiner les vaisseaux , missiles et gerer les collisions entre asteroides vaisseaux et asteroides missiles
	*/
	collision->drawAndManageCollision(asteroides, vaisseaux,player);
	
	if ((asteroides->size() == 0) && (Part::getNbVague() >= (Part::getLevel()*7))){
			AsteroideForme::isEmpty = true;
	}
	
	listV->fillListVaisseaux(choixVaisseau,player);
	
	for (int i = 0; i < choixVaisseau->size(); i++){
		_itoa_s((*choixVaisseau)[i]->getPrice(), priceS, 10, 10);
		GraphicPrimitives::drawText2D(priceS, (*choixVaisseau)[i]->getPosX2(), (*choixVaisseau)[i]->getPosY2(), 0.0f, 0.0f, 0.0f, 1.0f);
		GraphicPrimitives::drawText2D(" eur", (*choixVaisseau)[i]->getPosX2() + 0.05, (*choixVaisseau)[i]->getPosY2(), 0.0f, 0.0f, 0.0f, 1.0f);
		(*choixVaisseau)[i]->draw();
		/**
		si l'argent restante ne peut pas acheter ce vaisseau , on met un croix sur le vaisseau 
		*/
		if (player->getMoney() < (*choixVaisseau)[i]->getPrice()){
			GraphicPrimitives::drawLine2D((*choixVaisseau)[i]->getPosX2(), (*choixVaisseau)[i]->getPosY2(), (*choixVaisseau)[i]->getPosX2() + 0.16, (*choixVaisseau)[i]->getPosY2()-0.16, 1.0, 0.0, 0.0);
			GraphicPrimitives::drawLine2D((*choixVaisseau)[i]->getPosX2(), (*choixVaisseau)[i]->getPosY2() - 0.16, (*choixVaisseau)[i]->getPosX2() + 0.16, (*choixVaisseau)[i]->getPosY2(), 1.0, 0.0, 0.0);
		}
	}
		
	/**
	appele de la fonction qui redessine la bare de vie
	*/
	player->drawLifeLine();
	player->draw();


	if (!Grille::isAgoodChoice){
		play.drawCaseRed(cases);
	}
	/**checker et dessiner une case rouge si on clique sur une case déjà selectionnée
	*/
	if (Grille::caseSelected.size() == 2){ play.drawCaseSelected(); }

	if (Bomb::launch == true){
		bomb.detonateBomb(asteroides); 
		if (timeOfBomb >= 200){ Bomb::launch = false; timeOfBomb = 0; }
		else{ timeOfBomb++; }
		
	}
	
	
}

void MyGraphicEngine::reshape(int width, int height){
	DimensionWindow::setWidth(width);
	DimensionWindow::setHeight(height);
}

MyGraphicEngine::~MyGraphicEngine(){
	delete missiles;
	delete asteroides;
	delete vaisseaux;
	delete choixVaisseau;
	delete cases;
	delete priceS;

}