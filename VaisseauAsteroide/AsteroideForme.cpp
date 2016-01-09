#include "AsteroideForme.h"
#include "MyGraphicEngine.h"
#include "SlowAsteroide.h"
#include "AverageAsteroide.h"
#include "QuickAsteroide.h"
#include "Asteroide.h"
#include "veryQuickAsteroide.h"



#define PI 3.141592653589

bool AsteroideForme::isEmpty = false;
Asteroide *asteroide;


/*fonction permettant de dessiner un losange*/
void AsteroideForme::losange(float posX, float posY,float r, float g, float b){
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;
	
	vx->push_back(posX); vy->push_back(posY); vx->push_back(posX - 0.03); vy->push_back(posY - 0.03);
	
	vx->push_back(posX - 0.06); vy->push_back(posY - 0.03); vx->push_back(posX - 0.06); vy->push_back(posY - 0.06);
	
	vx->push_back(posX - 0.09); vy->push_back(posY - 0.09); vx->push_back(posX - 0.06); vy->push_back(posY - 0.12);
	
	vx->push_back(posX - 0.06); vy->push_back(posY - 0.15); vx->push_back(posX - 0.03); vy->push_back(posY - 0.15);
	
	vx->push_back(posX); vy->push_back(posY - 0.18); vx->push_back(posX + 0.03); vy->push_back(posY - 0.15);
	
	vx->push_back(posX + 0.06); vy->push_back(posY - 0.15); vx->push_back(posX + 0.06); vy->push_back(posY - 0.12);
	
	vx->push_back(posX + 0.09); vy->push_back(posY - 0.09); vx->push_back(posX + 0.06); vy->push_back(posY - 0.06);
	
	vx->push_back(posX + 0.06); vy->push_back(posY - 0.03); vx->push_back(posX + 0.03); vy->push_back(posY - 0.03);
	vx->push_back(posX); vy->push_back(posY);
	
	
	GraphicPrimitives::drawOutlinedPolygone2D(*vx, *vy, r, g, b, 1.0f);

	delete vx, vy;
}

/*fonction permettant de dessiner un polygone avec differents sommets (exagone,polygone,....)*/
void AsteroideForme::polygone(float xc, float yc, float r, float g, float b, int n, float rad, bool fill){
	float x = 0.0;
	float y = 0.0;
	std::vector<float> *vx = new std::vector<float>;
	std::vector<float> *vy = new std::vector<float>;
	float a = atan2(y - yc, x - xc);
	int i;

	for (i = 1; i <= n; i++) {
		a = a + PI * 2 / n;
		x = xc + (rad * cos(a) / 6);
		y = yc + (rad * sin(a) / 6);
		vx->push_back(x); vy->push_back(y);
	}
	if (fill){ GraphicPrimitives::drawFillPolygone2D(*vx, *vy, r, g, b, 1.0f); }
	else{ GraphicPrimitives::drawOutlinedPolygone2D(*vx, *vy, r, g, b, 1.0f); }
	delete vx, vy;
}

/*pour lancer la vague d'asteroide*/
void AsteroideForme::lunchAst(){
	char *nbVague = new char[10];
	_itoa_s(Part::getNbVague(), nbVague, 10, 10);
	GraphicPrimitives::drawFillRect2D(0.7, 0.92, 0.3, 0.08, 1.0, 1.0, 1.0);
	if (!Part::partIsBegin){ if (rand() % 2){ GraphicPrimitives::drawText2D("launch the wave", 0.7, 0.95, 1.0f, 0.0f, 0.0f, 1.0f); } }
	else{ GraphicPrimitives::drawText2D("launch the wave", 0.7, 0.95, 1.0f, 0.0f, 0.0f, 1.0f); }
	
	if ((Part::getNbVague() == (Part::getLevel() * 6) - 1)){ GraphicPrimitives::drawText2D("DERNIERE VAGUE", 0.0, 0.0, 1.0f, 0.0f, 0.0f, 1.0f); }
}

void AsteroideForme::lunchVague(float x, float y, float r, float g, float b, float getDown){
	
	if (Part::getLevel() == 1){
		asteroide = new SlowAsteroide(x, y, r, g, b);
		asteroide->draw();
		delete asteroide;
	}

	if (Part::getLevel() == 2){
		asteroide = new AverageAsteroide(x,y,r,g,b);
		asteroide->draw();
		delete asteroide;
	}
	
	else if (Part::getLevel() == 3){
		asteroide = new QuickAsteroide(x, y, r, g, b);
		
		asteroide->draw();
		delete asteroide;
	}
	else if (Part::getLevel() == 4){
		asteroide = new VeryQuickAsteroide(x, y, r, g, b);
		asteroide->draw();
		delete asteroide;
	}
	else if (Part::getLevel() == 5){
		asteroide = new VeryQuickAsteroide(x, y, r, g, b);
		asteroide->draw();
		delete asteroide;
	}
	else if (Part::getLevel() == 6){
		asteroide = new VeryQuickAsteroide(x, y, r, g, b);
		asteroide->draw();
		delete asteroide;
	}
	else if (Part::getLevel() == 7){
		asteroide = new VeryQuickAsteroide(x, y, r, g, b);
		asteroide->draw();
		delete asteroide;
	}
	
}

