#include "levelfive.h"

LevelFive::LevelFive() : Stage()
{
	setLevelW(1100);
	//step("[LevelFive] Constructing.");
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
	//step("[LevelFive] Destroying.");
	setLevelW(1600);
}

void
LevelFive::defineBackground()
{
	//step("[LevelFive] Defining Background.");
	background = new Background("res/images/s_level05.png");
	background->addClip(1112,62,46,46);
}

void
LevelFive::generatePlatform()
{
	//step("[LevelFive] Generating Platform.");
	platform = new Platform("res/images/s_level05.png");
	platform->addClip(1112,2,46,46);
}

void
LevelFive::generateSecondLayer()
{
	//step("[LevelFive] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level05.png");
	secondlayer->addClip(0,0,1100,450);
	secondlayer->generatePosition(0,getPlatformH()-450,1100,450);
}

void
LevelFive::generateEnemies()
{
	int positionReference = 700;
	while(positionReference < 1100)
	{
		enemy = new Curupira(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 10;
	}
	enemy = new Curupira(0,420);
	enemies.push_back(enemy);
	positionReference = 900;
	while(positionReference < 1200)
	{
		enemy = new Curupira(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 10;
	}
	enemy = new Curupira(0,990);
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
		positionReference += 30;
	}
	enemy = new Urubu(1,570);
	enemies.push_back(enemy);
	positionReference = 600;
	while(positionReference < 1000)
	{
		enemy = new Urubu(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 40;
	}
	enemy = new Urubu(1,925);
	enemies.push_back(enemy);
	positionReference = 800;
	while(positionReference < 1100)
	{
		enemy = new Urubu(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 20;
	}
	enemy = new Urubu(0,1020);
	enemies.push_back(enemy);
	for (int i = 0; i < 20; i++)
	{
		enemy = new Politico (0, false, 300+50*i);
		enemies.push_back(enemy);
	}
}

void
LevelFive::generateCivilians(){}

void
LevelFive::drawScenarioRelativeImages()
{
	//loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->drawRelative();
}
