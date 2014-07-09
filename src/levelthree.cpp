#include "levelthree.h"

LevelThree::LevelThree() : Stage()
{
	setLevelW(1300);
	setLimitW(1050);
	step("[LevelThree] Constructing.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	generateEnemies();
	setFinished(false);
	setGameOver(false);
}

LevelThree::~LevelThree()
{
	step("[LevelThree] Destroying.");
	setLevelW(1600);
	setLimitW(1600);
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
	secondlayer->addClip(0,0,880,345);
	secondlayer->addClip(0,350,249,142);
}

void
LevelThree::drawScenarioRelativeImages()
{
	loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->setOnlyClipNumber(0);
	secondlayer->generatePosition(110,getPlatformH()-345,880,345);
	secondlayer->drawRelative();

	secondlayer->setOnlyClipNumber(1);
	secondlayer->generatePosition(1050,getPlatformH()-80,249,142);
	secondlayer->drawRelative();
}

void 
LevelThree::generateEnemies()
{
	for (int i = 0; i < 10; i++)
	{
		enemy = new Politico (0, false, 100*i);
		enemies.push_back(enemy);
	}
}
