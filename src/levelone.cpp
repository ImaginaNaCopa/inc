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
	generateItens();
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

	enemy = new Urubu(500);
	enemies.push_back(enemy);
	
	enemy = new Urubu(600);
	enemies.push_back(enemy);
}

void
LevelOne::generateItens()
{
	step("[LevelOne] Generating Itens.");
	//item = new Potion(200, 200);
	//itens.push_back(item);
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
	
	loop("[LevelOne] Verifying if Caio is imune.");
	if (!caio->isImune())
	{
		for (auto it = enemies.begin(); it != enemies.end(); it++)
		{
			loop("[LevelOne] Verifying Collision Between Caio and Enemies.");
			if (caio->overEnemy((*it)->getPosition()))
			{
				caio->setImune(true);
				caio->setHealth(-1);
				now = SDL_GetTicks();
				last = now;
			}
		}
	}
	else
	{
    	now = SDL_GetTicks();

    	if ((now - last) > 1500)
    	{
    		caio->setImune(false);
    	}
	}

	if (caio->getHealth() == 0)
		caio->release();
	
	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		if (aim->overEnemy((*it)->getPosition()))
		{
    		loop("[LevelOne] if Shooted an Enemy, define Dead to it.");
			dead = it;

   			SDL_Rect position = (*dead)->getPosition();
			item = new Potion(round(position.x + (position.w/2)), position.y);
			item->init();
			itens.push_back(item);
		}
	}

	if (dead != enemies.end())
	{
    	loop("[LevelOne] Delete all Dead Enemies.");
  		delete *dead;
		enemies.erase(dead);
	}
}