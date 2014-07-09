#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "urubu.h"
#include "gigante.h"
#include "politico.h"
#include "stage.h"

class LevelThree : public Stage
{
public:
	LevelThree();
	~LevelThree();

	void drawScenarioRelativeImages();
	void generateEnemies();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
};

#endif // LEVELTHREE_H