#include "levelfive.h"

LevelFive::LevelFive() : Stage()
{
	setLevelW(1100);
	step("[LevelFive] Constructing.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	generateEnemies();
	generateCivilians();
	setFinished(false);
	setGameOver(false);
}

LevelFive::~LevelFive()
{
	setLevelW(1600);
}

void
LevelFive::defineBackground()
{
	step("[LevelFive] Defining Background.");
	background = new Background("res/images/s_level05.png");
	background->addClip(1112,62,46,46);
}

void
LevelFive::generatePlatform()
{
	step("[LevelFive] Generating Platform.");
	platform = new Platform("res/images/s_level05.png");
	platform->addClip(1112,2,46,46);
}

void
LevelFive::generateSecondLayer()
{
	step("[LevelFive] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level05.png");
	secondlayer->addClip(0,0,1100,450);
	secondlayer->generatePosition(0,getPlatformH()-450,1100,450);
}

void
LevelFive::generateEnemies()
{
	enemy = new Curupira(0,990);
	enemies.push_back(enemy);
}

void
LevelFive::generateCivilians(){}

void
LevelFive::drawScenarioRelativeImages()
{
	loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->drawRelative();
}
