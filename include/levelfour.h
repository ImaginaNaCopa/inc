#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "curupira.h"
#include "stage.h"

class LevelFour : public Stage
{
public:
	LevelFour();
	~LevelFour();

	void generateEnemies();
	void generateCivilians();
	void drawScenarioRelativeImages();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
};

#endif // LEVELFOUR_H