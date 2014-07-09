#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "curupira.h"
#include "politico.h"
#include "urubu.h"
#include "stage.h"

class LevelFive : public Stage
{
public:
	LevelFive();
	~LevelFive();

	void generateEnemies();
	void generateCivilians();
	void drawScenarioRelativeImages();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
};

#endif // LEVELFIVE_H