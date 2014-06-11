#ifndef LEVELONE_H
#define LEVELONE_H

#include "stage.h"
#include "curupira.h"
#include "urubu.h"
#include "potion.h"
#include "alteredpotion.h"

class LevelOne : public Stage
{
public:
	LevelOne();
	~LevelOne();

	void generateEnemies();
	void generateItens();
	void drawScenarioRelativeImages();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();

	void controlEntityEvents();
	void damagingCaio();
	void lootItem();
	void killingEnemy();
private:
	Uint32 now;
	Uint32 last;
};

#endif // LEVELONE_H