#include "Part.h"
#include "Engine.h"
#include "AsteroideForme.h"


int Part::level = 1;
int Part::pastDt = 5000;
int Part::nbVague = 0;
int Part::go = 0;
bool Part::partIsBegin = false;
bool Part::isUpdate = false;

int Part::getLevel(){
	return level;
}

int Part::getNbVague(){
	return nbVague;
}

void Part::setLevel(int newLevel){
	Part::level = newLevel;
}

int Part::getPastDt(){
	return pastDt;
}

void Part::setPastDt(int newPastDt){
	switch (newPastDt){
	case 1:
	{pastDt = 5000; break; }
	case 2:
	{pastDt = 6000; break; }
	case 3:
	{pastDt = 7000; break; }
	case 4:
	{pastDt = 8000; break; }
	case 5:
	{pastDt = 8000; break; }
	case 6:
	{pastDt = 8000; break; }
	case 7:
	{pastDt = 8000; break; }
	}
}

void Part::setNbVague(int newNbVague){
	nbVague = newNbVague;
}

/*voir le .h*/
void Part::partieFnished(){
	if ( AsteroideForme::isEmpty){
			isUpdate = true;
	}
}
/*voir le .h*/
void Part::choiceToContinue(){
	char * s = new char[100];
	_itoa_s(Part::getLevel()+1, s, 10,10);
	if (Part::getLevel() < 7){
		if (MessageBox(NULL, s, "NIVEAU ", 0)==1)
		{
			Part::setLevel((Part::getLevel() + 1));
			Part::setPastDt(Part::getPastDt() + 1);
			
		}
		else{
			MessageBox(NULL, "AU REVOIR", 0, 0);
			exit(0);
		}
	}
	else{
		MessageBox(NULL, "YOU WIN ", "FINISH", 0);
		exit(0);
	}
	delete s;
}
/*voir le .h*/
void Part::reset(){
	Part::setNbVague(0);
	Part::isUpdate = false;
}
