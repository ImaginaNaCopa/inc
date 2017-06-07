#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "../include/curupira.h"
#include "../include/urubu.h"
#include "../include/politico.h"
#include "../include/stage.h"

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