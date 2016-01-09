#pragma once

class AsteroideForme{	
	
public:

	/*fonction permettant de dessiner un polygone avec differents sommets (exagone,polygone,....)*/
	static void polygone(float x, float y, float r, float g, float b, int n, float rad, bool fill);
	static void losange(float x, float y, float r, float g, float b);
	void lunchAst();
	int boxChoice(float x, float y);
	void lunchVague(float x, float y, float r, float g, float b,float getDown);
	static bool isEmpty;
	
	

};