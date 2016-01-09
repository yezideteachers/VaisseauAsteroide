#include "MyControlEngine.h"
#include "Play.h"
#include "Part.h"
#include "Asteroide.h"
#include "Player.h"
#include "Engine.h"
#include "AsteroideForme.h"



void Play::drawCaseSelected(){
		GraphicPrimitives::drawFillRect2D(Grille::caseSelected[0],
			Grille::caseSelected[1], 0.18, 0.18, 1.0, 0.0, 0.0);
		Grille::caseSelected.clear();
	
}
/**
mettre à jour le jeux(passer à la partie suivant)
*/
void Play::update(Player *player, std::vector<Engin *> *asteroides, std::vector<Engin *> *vaisseaux, std::vector<Engin *> *missiles){
	if (Part::isUpdate){
		reset(asteroides);
		reset(vaisseaux);
		reset(missiles);
		player->reset();
		Part::reset();
		Part::choiceToContinue();
		AsteroideForme::isEmpty = false;

	}
}


/**
cette fonction permet de recuperer des informations sur le vaisseau qui a etait selectionné
*/
void Play::vaisseauSelected(Player* player, float x, float y, float* r, float* g, float* b, bool* heSelected, int* numberSelection){
	
	if (y >= 0.8){
		if ((x >= -0.6) && (x <= -0.4) && player->getMoney() >= 5){
			*r = 1.f;
			*g = 0.5f;
			*b = 0.0f;
			*heSelected = true;
			*numberSelection = 1;
		}
		else if ((x >= -0.4) && (x <= -0.2) && player->getMoney() >= 10){
			*r = 0.0f;
			*g = 0.0f;
			*b = 0.5f;
			*heSelected = true;
			*numberSelection = 2;

		}
		else if ((x >= -0.2) && (x <= 0.0) && player->getMoney() >= 15){
			*r = 0.5f;
			*g = 1.0f;
			*b = 0.5f;
			
			*heSelected = true;
			*numberSelection = 3;


		}
		/*else{
			if (x <= 0.0 && x >= -0.6){
				MessageBox(NULL, "Solde", "Votre solde est insufisant pour acheter ce type de vaisseau", 0);
			}
		}*/
	}
}


/**
verifie que la case selectionnée n'était pas déjà selectionnée 
@return bool
*/

bool Play::notSelected(std::vector<Engin *> *v, float x, float y){
	Vaisseau * vais;
	for (int i = 0; i < v->size(); i++){
		vais = dynamic_cast<Vaisseau *> ((*v)[i]);
		/**si on clique une deuxième fois sur le StrongVaisseau 
			et qu'il nous reste de l'argent on fait appele pour lancer le super Power
			*/
		if ((x == vais->getPosX()) && (y == vais->getPosY())){
			if (vais->dimens == 3 && Part::getLevel()>=3){
				vais->setSuperPower(true); 
				vais->setB(1.0);
				return false;
			}
			else{
				Grille::caseSelected.push_back(x);
				Grille::caseSelected.push_back(y);
				return false;
			}
		}
	}
	return true;
}


/**cette fonction elle sera appelée que dans les nouveaux trois (3) et plus.
Elle permet d'empêcher le joueur de placer plus de quatre vaisseaux sur la meme colonne ,
elle est faite pour augmenter la difficulté
*/
bool Play::isInTheSameColonne(std::vector<Engin *> *v, float x){
	Vaisseau * vais;
	int nbchoice = 0;
	for (int i = 0; i < v->size(); i++){
		vais = dynamic_cast<Vaisseau *> ((*v)[i]);

		/*si la collonne contient déjà  quatre vaisseaux 
		et que la partie courante est plus grande que 2 je renvoi false*/
		if (x == vais->getPosX() && Part::getLevel() >= 3){ 
			
			nbchoice += 1;
			if (nbchoice > 4){ Grille::isAgoodChoice = false; return true; }
		}
	}
	return false;
}


/**j'effectue le reset sur les trois types de vecteur possible (Asteroide , Vaisseau ,Missile)
pour ca j'utilise le Template */
template<class Type> void Play::reset(Type *param){
	std::string s = (typeid(param).name()); //je recupère le nom de la classe (l'objet)
	if (s.compare("classe Engin *")){ // si l'objet est de type Engin (Asteroide , Vaisseau ou Missile)
		param->clear(); //je clear
	}
	/*sinon je fait rien*/
}


/*faire appraitre une case rouge pour interdire d'aligner plus que 4 vaisseaux sur la meme colonne
	utilisée dans le niveau 3 et plus */
void Play::drawCaseRed(std::vector<Case* > *cases){
	for (int i = 0; i < Grille::vectProhibitedChoices.size(); i++){
		GraphicPrimitives::drawFillRect2D(Grille::vectProhibitedChoices[i]->getPosX(), 
			Grille::vectProhibitedChoices[i]->getPosY(), 0.18, 0.18, 1.0, 0.0, 0.0);
	}
}