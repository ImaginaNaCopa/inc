#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "curupira.h"
#include "stage.h"

class LevelThree : public Stage
{
public:
	LevelThree();
	~LevelThree();

	void generateEnemies();
	void generateCivilians();
	void drawScenarioRelativeImages();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
};

#endif // LEVELTHREE_H