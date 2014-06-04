#include "levelone.h"

LevelOne::LevelOne() : Stage()
{
    step("[LevelOne] Constructing.");
    step("[LevelOne] Defining Scenario.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
    step("[LevelOne] Defining Enemies.");
	generateEnemies();
}

LevelOne::~LevelOne() {}

void
LevelOne::defineBackground()
{
    step("[LevelOne] Defining Background.");
	background = new Background("res/images/s_02.png");
	background->addClip(0,0,2,2);
}

void
LevelOne::generatePlatform()
{
    step("[LevelOne] Generating Platform.");
	platform = new Platform("res/images/s_02.png");

}

void
LevelOne::generateSecondLayer()
{
    step("[LevelOne] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_02.png");
	secondlayer->addClip(4,0,270,210);
	secondlayer->addClip(4,210,270,270);
	secondlayer->addClip(274,0,120,360);	
}

void
LevelOne::generateEnemies()
{
    step("[LevelOne] Generating Enemies.");
	enemy = new Curupira(700);
	enemies.push_back(enemy);

	enemy = new Curupira(330);
	enemies.push_back(enemy);
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

void
LevelOne::controlEntityEvents()
{
    loop("[LevelOne] Handling Specific Entity Conditions.");
	if (enemies.size() < 1)
	{
    	step("[LevelOne] Spawn a New Curupira.");
		enemy = new Curupira((rand() % 200) + 300);
		enemy->init();
		enemies.push_back(enemy);
	}	

	auto dead = enemies.end();

	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
    	loop("[LevelOne] Verifying Collision Between Caio and Enemies.");
		caio->overEnemy((*it)->getPosition());
		if (aim->overEnemy((*it)->getPosition()))
		{
    		loop("[LevelOne] if Shooted an Enemy, define Dead to it.");
			dead = it;
		}
	}

	if (dead != enemies.end())
	{
    	loop("[LevelOne] Delete all Dead Enemies.");
		delete *dead;
		enemies.erase(dead);
	}
}