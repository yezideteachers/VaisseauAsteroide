#include "MyControlEngine.h"
#include "Case.h"
#include "Play.h"
#include "Part.h"
#include "DimensionWindow.h"
#include "Bomb.h"
#include "LightVaisseau.h"
#include "HeavyVaisseau.h"


float r1, g1, b1 = 1.0f;
bool heSelected = false;
int numberSelection = 0;

std::vector<Case *> *listC = new std::vector < Case * > ;
Play pl;
Grille gr;
void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		/*gestion de la dimension de la fenetre*/
		float x1 = (x - (DimensionWindow::getWidth() / 2)) / (DimensionWindow::getWidth() / 2.f);
		float y1 = (y - (DimensionWindow::getHeight() / 2)) / (-DimensionWindow::getHeight() / 2.f);
		int caseChoisie;
		/**
		si le clique est effectué dans la zone de jeux alors je récuppère le numéro de la case
		*/
		if ((x1 < 0.8) && (y1 < 0.8)){
			caseChoisie = ((int)((x1 + 1) / 0.18) + (10 * (int)((y1 + 1) / 0.18)));
		}
		/**pour rendre le jeux plus interessant 
		pour le niveau 3 et plus j'interdis d'aligner plus que 4 vaisseaux sur la meme colonne
		*/
		if (Part::getLevel() > 0){
			Grille::vectProhibitedChoices.clear();
			Grille::isAgoodChoice = true;
			if ((x1 < 0.8) && (y1 < 0.8)){
				for (int i = 0; i < listC->size(); i++){
					for (int j = 0; j < listVaisseaux->size(); j++){
						if (((*listC)[i]->getPosX() == (*listVaisseaux)[j]->getPosX()) && ((*listC)[i]->getPosY() != (*listVaisseaux)[j]->getPosY())
							&& (Part::getLevel() > 2)){
							Grille::vectProhibitedChoices.push_back((*listC)[caseChoisie]);
							break;
						}
						break;
					}
				}
			}
		}
		pl.vaisseauSelected(player, x1, y1, &r1, &g1, &b1, &heSelected, &numberSelection);
		gr.listCases(listC);
		remplirVectVaisseaux(listVaisseaux, listC, caseChoisie);

		/**button pour quitter*/
		if ((x1>0.85 && x1 <= 1.0) && (y1 >= 0.85) && (y1 < 0.92)){ exit(0); }
		/**button pour lancer la vague*/
		if ((x1 >= 0.7) && (y1 >= 0.95)){ Part::partIsBegin = true; }
		
		/**si on a cliqué sur la bombe*/
		if ((x1 >= 0.0) && (y1 >= 0.8) && (x1 <= 0.2) && (y1 <= 1.0)){
			if ((Part::getLevel()>=2) && (player->getMoney() >= 15)){
				player->setMoney(player->getMoney() - 15);
				Bomb::launch = true;
			}
		}

	}
	
}

MyControlEngine::~MyControlEngine(){
	delete asteroides;
	delete listVaisseaux;
	delete listC;
	delete missiles;
	delete Grilles;
}



void MyControlEngine::remplirVectVaisseaux(std::vector<Engin *> *v, std::vector<Case *> *c, int nbCase){
	if ((c->size() >= nbCase) && (nbCase < 100)){
		/**si on a choisie un type de vaisseaux */
		if (heSelected){
			/*voir la fonction notSelected*/
			if (pl.notSelected(v, ((*c)[nbCase]->getPosX()), ((*c)[nbCase]->getPosY()))){
				if (player->getMoney() >= (10 * numberSelection)){
					if (!pl.isInTheSameColonne(v, ((*c)[nbCase]->getPosX()))){
						Missile miss((*c)[nbCase]->getPosX() + 0.08, (*c)[nbCase]->getPosY() + 0.07);
						if (numberSelection == 3){
							v->push_back(new StrongVaisseau((*c)[nbCase]->getPosX(), (*c)[nbCase]->getPosY(), r1, g1, b1, 10, &miss));
						}
						else if (numberSelection == 2){
							v->push_back(new HeavyVaisseau((*c)[nbCase]->getPosX(), (*c)[nbCase]->getPosY(), r1, g1, b1, 10, &miss));
						}
						else if (numberSelection == 1){
							v->push_back(new LightVaisseau((*c)[nbCase]->getPosX(), (*c)[nbCase]->getPosY(), r1, g1, b1, 10, &miss));
						}
						//else{ v->push_back(new Vaisseau((*c)[nbCase]->getPosX(), (*c)[nbCase]->getPosY(), r1, g1, b1, &miss)); }
						player->setMoney(player->getMoney() - (numberSelection * 10));
						dynamic_cast<Vaisseau *> ((*v)[v->size() - 1])->dimens = numberSelection;
						dynamic_cast<Vaisseau *> ((*v)[v->size() - 1])->setSpeedMissile(numberSelection);
					}
					
				}

			/*	else{
					MessageBox(NULL, "Votre solde est insufisant pour acheter ce type de vaisseau", "Solde", 0);
				}*/
			}
			
		}
		else{
			MessageBox(NULL, "veuillez choisir un vaisseau", "Choix Vaisseau", 0);
		}
	
	}

}



