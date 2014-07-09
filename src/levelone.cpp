#include "levelone.h"

LevelOne::LevelOne() : Stage()
{
	step("[LevelOne] Constructing.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	generateEnemies();
	generateCivilians();
	setFinished(false);
	setGameOver(false);
}

LevelOne::~LevelOne() {}

void
LevelOne::defineBackground()
{
	step("[LevelOne] Defining Background.");
	background = new Background("res/images/s_level01.png");
	background->addClip(282,0,46,46);
}

void
LevelOne::generatePlatform()
{
	step("[LevelOne] Generating Platform.");
	platform = new Platform("res/images/s_level01.png");
	platform->addClip(282,72,46,46);
}

void
LevelOne::generateSecondLayer()
{
	step("[LevelOne] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level01.png");
	secondlayer->addClip(0,0,270,360);
}

void
LevelOne::generateEnemies()
{
	step("[LevelOne] Generating Enemies.");
	int positionReference = 400;
	while(positionReference < 700)
	{
		enemy = new Curupira(7,positionReference);
		enemies.push_back(enemy);
		positionReference += 60;
	}
	enemy = new Curupira(8,420);
	enemies.push_back(enemy);
	positionReference = 900;
	while(positionReference < 1200)
	{
		enemy = new Curupira(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 60;
	}
	enemy = new Curupira(3,990);
	enemies.push_back(enemy);
	enemy = new Curupira(4,1470);
	enemies.push_back(enemy);
	enemy = new Curupira(5,1500);
	enemies.push_back(enemy);
	enemy = new Curupira(6,1530);
	enemies.push_back(enemy);
}

void
LevelOne::generateCivilians()
{
	step("[LevelOne] Generating Civilians.");
	civil = new Civil(0,0,350);
	civis.push_back(civil);
	civil = new Civil(0,1,900);
	civis.push_back(civil);
	civil = new Civil(0,2,1350);
	civis.push_back(civil);
}

void
LevelOne::drawScenarioRelativeImages()
{
	loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->generatePosition(50,getPlatformH()-360,270,360);
	secondlayer->drawRelative();
	secondlayer->generatePosition(480,getPlatformH()-360,270,360);
	secondlayer->drawRelative();
	secondlayer->generatePosition(850,getPlatformH()-360,270,360);
	secondlayer->drawRelative();
	secondlayer->generatePosition(1280,getPlatformH()-360,270,360);
	secondlayer->drawRelative();
}
