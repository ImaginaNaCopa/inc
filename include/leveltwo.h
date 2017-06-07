#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "../include/stage.h"

#include "../include/curupira.h"
#include "../include/urubu.h"

class LevelTwo : public Stage
{
public:
	LevelTwo();
	~LevelTwo();

	void generateEnemies();
	void generateCivilians();
	void drawScenarioRelativeImages();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
};

#endif // LEVELTWO_H