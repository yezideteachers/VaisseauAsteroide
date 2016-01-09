#include <string>
#include "stdio.h"
#include "stdlib.h"
#include "Collision.h"
#include "Part.h"
#include <string>

/**
cette fonction permet de verifier si le deux engins sont sur la meme ligne,
j'utilise pour ca le template
*/
template<typename type1, typename type2> bool Collision::isinTheSameLigne(type1 *ast, type2 *vaisseauORMissile){
	std::string s = (typeid(vaisseauORMissile).name());
	if (ast && vaisseauORMissile){
		if (s.compare("class Vaisseau *") == 0){
			if ((dynamic_cast<Vaisseau *> (vaisseauORMissile)->getPosY2() < ast->getPosY()) && (dynamic_cast<Vaisseau *> (vaisseauORMissile)->getPosY2() >= (ast->getPosY() - 0.10))){
				return true;
			}
		}
		else{
			if ((vaisseauORMissile->getPosY() < ast->getPosY()) && (vaisseauORMissile->getPosY() >= (ast->getPosY() - 0.18))){
				return true;
			}
		}
	}

	return false;
}

/**
cette fonction permet de gerer ma collision entre asteroide et missile ou asteroide et vaisseau.
on utilise le template pour les deux type possibles (Vaissau , Missile)
*/
template<class Type>bool Collision::isCollided(Asteroide *ast, Type * vaisseauORMissile){
	//je recupère le nom de la classe (l'objet)
	std::string s = (typeid(vaisseauORMissile).name());
	if (ast && vaisseauORMissile){
		if (s.compare("class Vaisseau *") == 0){ //je verifie si l'objet est de type vaisseau*/
			if ((abs(dynamic_cast<Vaisseau *> (vaisseauORMissile)->getPosX3() - ast->getPosX()) <= 0.12)){
				return true;
			}
		}
		else{
			//sinon l'objet est de type missile
			if ((abs(vaisseauORMissile->getPosX() - ast->getPosX()) <= 0.12)){ return true; }
		}
	}
	return false;
}

/**
cette fonction permet de dessiner les vaisseaux missile et
gere les collisions entre asteroides vaisseaux et asteroides missiles
*/
void Collision::drawAndManageCollision(std::vector<Engin *> *asteroides, std::vector<Engin *> *vaisseaux, Player* player){
	/*Vaisseau *vais= nullptr;
	Asteroide *ast= nullptr;*/
	bool superPowerUses = false;
	bool isEmpty = false;
	if (vaisseaux){
		for (int i = 0; i < vaisseaux->size(); i++){
			Vaisseau *vais = dynamic_cast<Vaisseau *> ((*vaisseaux)[i]);
			vais->draw();
			if (asteroides){
				for (int k = 0; k < asteroides->size(); k++){
					Asteroide *ast = dynamic_cast<Asteroide *> ((*asteroides)[k]);
					if (isinTheSameLigne(ast, vais) && isCollided(ast, vais)){
						deleteEngin(asteroides, k);
						deleteEngin(vaisseaux, i);
				
					}


					else{
						if (vais->missilesV){
							for (int j = 1; j < vais->missilesV->size(); j++){
								if ((*vais->missilesV)[j]->getPosX() >= 0.8){
									deleteEngin(vais->missilesV, j);
								}

								/**si le super pouvoir est déjà utilisé je pop le vaisseau*/
								if (vais->getSuperPower() && isCollided(ast, (*vais->missilesV)[j])){
									superPowerUses = true;

								}
								if (isinTheSameLigne(ast, (*vais->missilesV)[j])){

									if (isCollided(ast, (*vais->missilesV)[j])){
										deleteEngin(vais->missilesV, j);
										ast->setG(0.0f);
										decreasesLife(ast, (*vais->missilesV)[j]->getWidth(), true);
										decreasesLife(ast, (*vais->missilesV)[j]->getWidth(), false);

										if ((ast->getTailAsteroide() <= 0) && (ast->getR() >= 1) && (ast->getB() <= 0)){

											if (Part::getLevel() >= 3){
												if (ast->getChild()){
													deleteEngin(asteroides, k);
												}
												else{
													ast->setR(0.5);
													ast->setG(0.0);
													ast->setB(0.1);
													ast->setPosX(0.5);
													ast->setChild(true);

												}
											}
											else{
												deleteEngin(asteroides, k);
											}
											player->setMoney(player->getMoney() + 1);
											player->setScore(player->getScore() + 1);
										}
									}

								}
								(*vais->missilesV)[j]->drawMissile();
							}
						}
					}
					if (superPowerUses){
						vais->missilesV->clear();
						asteroides->clear();
						deleteEngin(vaisseaux, i);
						superPowerUses = false;
					}
				}

			}
	
		}
	}
	

}


/**
cette fonction permet de dessiner les asteroides
et gère les collisions entre asteroides et le bord gauche du canvas,
si la collision est effectué on pop l'asteroide et on decrémente la vie
*/
void Collision::drawAndverifyBoard(std::vector<Engin *> *asteroides, Player *player, int choice){
	Asteroide *ast;
	for (int i = 0; i < asteroides->size(); i++){
		ast = dynamic_cast<Asteroide *> ((*asteroides)[i]);
		ast->draw();
		if (ast->heFreed()){
			player->verifyLife();
			deleteEngin(asteroides, i);

		}
	}
}

/**cette fonction gere la decrementation de la bare de vie
en fonction de missile(force de missile)
*/
void Collision::decreasesLife(Asteroide * ast, double widthMissile, bool forR){
	if (forR){ ast->setR(ast->getR() + ((widthMissile * 10) / Part::getLevel())); }
	else{ ast->setB(ast->getB() - ((widthMissile * 10) / Part::getLevel())); }
	if (ast->getTailAsteroide() >= 0){
		ast->setTailAsteroide(ast->getTailAsteroide() - (0.1 / Part::getLevel()));
	}
	if (ast->getLifeAsteroide() >= 0){ ast->setLifeAsteroide(ast->getLifeAsteroide() - 0.1); }

}



/**
supprimer Engin qui peut etre missile, Asteroide ou vaisseau
*/
template<class Type> void Collision::deleteEngin(Type *missiles, int index){

	if (missiles->size() <= 1){ missiles->pop_back(); }
	else{ std::swap((*missiles)[index], missiles->back()); missiles->pop_back(); }
}