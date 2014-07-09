#include "leveltwo.h"

LevelTwo::LevelTwo() : Stage()
{
	step("[LevelTwo] Constructing.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	generateEnemies();
	generateCivilians();
	setFinished(false);
	setGameOver(false);
}

LevelTwo::~LevelTwo()
{
	step("[LevelTwo] Destroying.");
}

void
LevelTwo::defineBackground()
{
	step("[LevelTwo] Defining Background.");
	background = new Background("res/images/s_level02.png");
	background->addClip(562,252,46,46);
}

void
LevelTwo::generatePlatform()
{
	step("[LevelTwo] Generating Platform.");
	platform = new Platform("res/images/s_level02.png");
	platform->addClip(562,332,46,46);
}

void
LevelTwo::generateSecondLayer()
{
	step("[LevelTwo] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level02.png");
	secondlayer->addClip(0,0,1040,200);
	secondlayer->addClip(0,210,472,257);
}

void
LevelTwo::generateEnemies()
{
	step("[LevelTwo] Generating Enemies.");
	int positionReference = 400;
	while(positionReference < 700)
	{
		enemy = new Curupira(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 13;
	}
	enemy = new Curupira(1,420);
	enemies.push_back(enemy);
	positionReference = 900;
	while(positionReference < 1200)
	{
		enemy = new Curupira(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 13;
	}
	enemy = new Curupira(2,990);
	enemies.push_back(enemy);
	enemy = new Curupira(0,1500);
	enemies.push_back(enemy);
	enemy = new Curupira(0,1530);
	enemies.push_back(enemy);
	positionReference = 250;
	while(positionReference < 700)
	{
		enemy = new Urubu(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 90;
	}
	enemy = new Urubu(2,570);
	enemies.push_back(enemy);
	positionReference = 1250;
	while(positionReference < 1600)
	{
		enemy = new Urubu(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 70;
	}
	enemy = new Urubu(1,925);
	enemies.push_back(enemy);
	positionReference = 1200;
	while(positionReference < 1550)
	{
		enemy = new Urubu(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 50;
	}
	enemy = new Urubu(1,1420);
	enemies.push_back(enemy);
}

void
LevelTwo::generateCivilians()
{
	step("[LevelTwo] Generating Civilians.");
	civil = new Civil(6,5,200);
	civis.push_back(civil);
	civil = new Civil(0,4,350);
	civis.push_back(civil);
	civil = new Civil(0,3,800);
	civis.push_back(civil);
}

void
LevelTwo::drawScenarioRelativeImages()
{
	loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->setOnlyClipNumber(0);
	secondlayer->generatePosition(40,getPlatformH()-200,1040,200);
	secondlayer->drawRelative();
	secondlayer->setOnlyClipNumber(1);
	secondlayer->generatePosition(1100,getPlatformH()-253,472,257);
	secondlayer->drawRelative();
}
