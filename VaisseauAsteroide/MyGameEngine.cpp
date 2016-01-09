#include "MyGameEngine.h"
#include "Part.h"
#include <time.h>

using namespace std;
DWORD startTime = GetTickCount();
DWORD currentTime = GetTickCount();
DWORD previousTime = currentTime;

int coef = 0;

MyGameEngine::~MyGameEngine(){
	delete Grilles;
	delete missiles;
	delete asteroides;
	delete vaisseaux;
}

void MyGameEngine::idle(){

	
	currentTime = GetTickCount();
	if ((currentTime - previousTime) >= (1/2.0)){
		double beforePosY = coordAst[(rand() % 10)];
		double pastPosY = beforePosY;
		/*le temps mis entre chaque vague
			(frequence de vague)
			*/
		if ((GetTickCount() > (startTime + Part::getPastDt()))
			&& (vaisseaux->size()>0) && (Part::getNbVague()<(Part::getLevel()*7) && Part::partIsBegin)){
			
			int repetition = (4 + (Part::getLevel()/4));
			for (int i = 0; i < repetition; i++){
				asteroides->push_back(new Asteroide(1, beforePosY));
				/*pour eviter d'avoir toute une vague sur la meme ligne*/
				while (true){
					if (abs((abs(pastPosY) - abs(beforePosY))) <= 0.2){
						pastPosY = coordAst[(rand() % 10)];
					}
					else{
						break;
					}
				}
				beforePosY = pastPosY;
			}
			Part::setNbVague(Part::getNbVague() + 1);
			startTime = GetTickCount();

		}

		for (int i = 0; i < vaisseaux->size(); i++) {
			Vaisseau *v = dynamic_cast<Vaisseau *> ((*vaisseaux)[i]);
			int k = v->getSpeedMissile();
			if ((coef % fire(k)) == 0){
				/**
				Arreter de tirer si il y'a plus d'asteroides qui apparaissent sinon on charge les missiles
				*/
				if (!stopFire(asteroides->size())){
					(v->missilesV)->push_back(new Missile(v->getPosX3(), v->getPosY3()));
					for (int k = 0; k < v->missilesV->size(); k++){
						if (v->dimens == 2){
							(*v->missilesV)[k]->Missile::setHeight(0.03);
							(*v->missilesV)[k]->Missile::setWidth(0.05);
						}
						else if (v->dimens == 3){
							
							(*v->missilesV)[k]->Missile::setHeight(0.03);
							(*v->missilesV)[k]->Missile::setWidth(0.1);
							if (v->getSuperPower()){
								
								(*v->missilesV)[k]->Missile::setPosY(-1.0);
								(*v->missilesV)[k]->Missile::setHeight(1.8);
								
								
							}
						}
						else{
							(*v->missilesV)[k]->Missile::setHeight(0.01);
						}

					}
				}
			}

		v->tick();

			
		}
		coef += 1;


		for (int i = 0; i < asteroides->size(); i++) {

			(*asteroides)[i]->tick();
		}
		previousTime = currentTime;
	}
	
}

/**cette fonction gere la frequence d'envoie des missiles (frequence de tire)
*/
int MyGameEngine::fire(int power){
	if (power == 1){ return 20; }
	else if (power == 2){ return 25; }
	else if (power == 3){ return 30; }
	return -1;
}


/**cette fonctions nous permet de savoir si il ya plus d'asteroides,
dans ce cas on arrête les missiles pour economiser de missile;
elle prend en parametre la taille du vecteur de missile.
@retrurn boolean
*/
bool MyGameEngine::stopFire(int sizeVectAst){
	if (sizeVectAst == 0){ return true; }
	return false;
}
