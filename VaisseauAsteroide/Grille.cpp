#include "Grille.h"
#include "GraphicPrimitives.h"
#include "Case.h"
using namespace std;

std::vector<Case *> Grille::vectProhibitedChoices;
std::vector<float> Grille::caseSelected;
bool Grille::isAgoodChoice = true;

Grille::~Grille(){}
bool wedrawed = false;

void Grille::draw(std::vector<Case * > *cases){
	/*pour eviter de redessiner a chaque fois*/
	
	if (wedrawed == false){
		float tempX = -1.0;
		float tempY = -1.0;
		float r = 0.5;
		float g = 0.5;
		float b = 0.5;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				//colorer les cases 
				cases->push_back(new Case(tempX, tempY, r, g, b));
				if (r == 0.0){ r = 0.5; g = 0.5; b = 0.5; }
				else { r = 0.0;}
				tempX += 0.18;
			}
			tempX = -1.0;
			tempY += 0.18;
			if (r == 0.0){ r = 0.5; g = 0.5; b = 0.5; }
			else { r = 0.0;}
		}
		wedrawed = true;
	}
	
	GraphicPrimitives::drawFillRect2D(0.8, -1.0, 0.2, 1.8, 1.0, 0.0, 0.0);
	for (int i = 0; i< cases->size();i++){
		(*cases)[i]->draw();

	}
	
}


void Grille::listCases(std::vector<Case *> *c){
	if (c->size()>0){ c->clear(); }
	float tempX = -1.0;
	float tempY = -1.0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			c->push_back(new Case(tempX, tempY, 0.0, 0.0, 0.0));

			tempX += 0.18;
		}
		tempX = -1.0;
		tempY += 0.18;

	}

}