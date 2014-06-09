#ifndef LEVELONE_H
#define LEVELONE_H

#include "stage.h"
#include "curupira.h"
#include "urubu.h"

class LevelOne : public Stage
{
public:
	LevelOne();
	~LevelOne();

	void generateEnemies();
	void drawScenarioRelativeImages();
	void controlEntityEvents();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();
private:
	Uint32 now;
	Uint32 last;
};

#endif // LEVELONE_H