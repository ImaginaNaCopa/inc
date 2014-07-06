#include "levelone.h"
#include <iostream>

using namespace std;

LevelOne::LevelOne() : Stage()
{
	step("[LevelOne] Constructing.");
	step("[LevelOne] Defining Scenario.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	step("[LevelOne] Defining Enemies.");
	generateEnemies();
	setFinished(false);
	setGameOver(false);
}

LevelOne::~LevelOne() {}

void
LevelOne::defineBackground()
{
	step("[LevelOne] Defining Background.");
	background = new Background("res/images/s_level02.png");
	background->addClip(272,362,46,46);
}

void
LevelOne::generatePlatform()
{
	step("[LevelOne] Generating Platform.");
	platform = new Platform("res/images/s_level02.png");
	platform->addClip(322,362,46,46);
}

void
LevelOne::generateSecondLayer()
{
	step("[LevelOne] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level02.png");
	secondlayer->addClip(0,0,270,210);
	secondlayer->addClip(0,210,270,270);
	secondlayer->addClip(270,0,120,360);	
}

void
LevelOne::generateEnemies()
{
	// Setting initial potion to curupiras
	step("[LevelOne] Generating Enemies.");
	int positionReference = 300;
	for(positionReference = 300; positionReference<=1550 ; positionReference++)
	{
		if(positionReference%300 == 0)
		{
			enemy = new Urubu(1, positionReference);
			enemies.push_back(enemy);
		}
		else if(positionReference%250 == 0)
		{
			enemy = new Curupira(2, positionReference);
			enemies.push_back(enemy);
		}
		else if(positionReference%220 == 0)
		{
			enemy = new Urubu(2, positionReference);
			enemies.push_back(enemy);
		}
		else if(positionReference%200 == 0)
		{
			enemy = new Curupira(1, positionReference);
			enemies.push_back(enemy);
		}
		else if(positionReference%80 == 0)
		{
			enemy = new Urubu(0, positionReference);
			enemies.push_back(enemy);
		}
		else if(positionReference%50 == 0)
		{
			enemy = new Curupira(0, positionReference);
			enemies.push_back(enemy);
		}
	} 
}

void
LevelOne::drawScenarioRelativeImages()
{
	loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->setClipNumber(0);
	secondlayer->generatePosition(40,240,270,210);
	secondlayer->drawRelative();
	secondlayer->setClipNumber(1);
	secondlayer->generatePosition(450,180,270,270);
	secondlayer->drawRelative();
	secondlayer->setClipNumber(2);
	secondlayer->generatePosition(810,90,120,360);
	secondlayer->drawRelative();
	secondlayer->generatePosition(1000,90,120,360);
	secondlayer->drawRelative();
	secondlayer->generatePosition(1200,90,120,360);
	secondlayer->drawRelative();
	secondlayer->generatePosition(1400,90,120,360);
	secondlayer->drawRelative();
}
