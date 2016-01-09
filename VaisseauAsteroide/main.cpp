#include <iostream>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Engin.h"
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <stdio.h>




int main(int argc, char * argv[])
{

	
	Engine e(argc, argv);
	std::vector<Engin *> asteroides;
	std::vector<Engin *> missiles;
	std::vector<Engin *> vaisseaux;
	Player* player = new Player("player1");
	GraphicEngine * dge = new MyGraphicEngine(&asteroides, &missiles, &vaisseaux, player);
	GameEngine * dgme = new MyGameEngine(&asteroides, &missiles, &vaisseaux, player);
	ControlEngine * dce = new MyControlEngine(&missiles, &vaisseaux, &asteroides, player);

	e.setGraphicEngine(dge);
	e.setGameEngine(dgme);
	e.setControlEngine(dce);
	try{
	e.start();
	}
	catch (exception e){
	cout << "relancez le jeux "  << endl;
	}
	

	system("pause");
	return 0;
}
