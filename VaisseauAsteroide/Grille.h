#pragma once
#include "GraphicPrimitives.h"
#include "Case.h"

class Grille {

	
public:
	static std::vector<Case *> vectProhibitedChoices;
	static std::vector<float> caseSelected;
	static bool isAgoodChoice;

	~Grille();

	void draw(std::vector<Case * > *cases);
	void listCases(std::vector<Case *> *c);
};