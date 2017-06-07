#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "../include/urubu.h"
#include "../include/gigante.h"
#include "../include/politico.h"
#include "../include/stage.h"

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