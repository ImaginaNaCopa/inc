#include "levelthree.h"

LevelThree::LevelThree() : Stage()
{
	setLevelW(1100);
	step("[LevelThree] Constructing.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	generateEnemies();
	generateCivilians();
	setFinished(false);
	setGameOver(false);
}

LevelThree::~LevelThree()
{
	step("[LevelThree] Destroying.");
	setLevelW(1600);
}

void
LevelThree::defineBackground()
{
	step("[LevelThree] Defining Background.");
	background = new Background("res/images/s_level03.png");
	background->addClip(902,2,46,46);
}

void
LevelThree::generatePlatform()
{
	step("[LevelThree] Generating Platform.");
	platform = new Platform("res/images/s_level03.png");
	platform->addClip(902,72,46,46);
}

void
LevelThree::generateSecondLayer()
{
	step("[LevelThree] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level03.png");
	secondlayer->addClip(0,0,880,400);
	secondlayer->generatePosition(110,getPlatformH()-400,880,400);
}

void
LevelThree::generateEnemies()
{
	enemy = new Curupira(0,990);
	enemies.push_back(enemy);
}

void
LevelThree::generateCivilians(){}

void
LevelThree::drawScenarioRelativeImages()
{
	loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->drawRelative();
}
