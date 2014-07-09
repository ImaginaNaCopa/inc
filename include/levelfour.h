#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "curupira.h"
#include "urubu.h"
#include "politico.h"
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

	void drawExceptionalRelativeImages();
	void drawShadow();
};

#endif // LEVELFOUR_H