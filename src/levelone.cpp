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
	// Setting initial potion to curupiras
	step("[LevelOne] Generating Enemies.");
	enemy = new Curupira(0, 300);
	enemies.push_back(enemy);
	enemy = new Curupira(1, 760);
	enemies.push_back(enemy);
	enemy = new Curupira(0, 800);
	enemies.push_back(enemy);
	enemy = new Curupira(0, 900);
	enemies.push_back(enemy);
	enemy = new Curupira(0, 950);
	enemies.push_back(enemy);
	enemy = new Curupira(1, 1000);
	enemies.push_back(enemy);
	enemy = new Curupira(0, 1250);
	enemies.push_back(enemy);
	enemy = new Curupira(0, 1300);
	enemies.push_back(enemy);
	enemy = new Curupira(2, 1400);
	enemies.push_back(enemy);
	enemy = new Curupira(0, 1450);
	enemies.push_back(enemy);


	// Setting initial potion to urubus
	enemy = new Urubu(0, 300);
	enemies.push_back(enemy);
	enemy = new Urubu(0, 500);
	enemies.push_back(enemy);
	enemy = new Urubu(2, 600);
	enemies.push_back(enemy);
	enemy = new Urubu(0, 900);
	enemies.push_back(enemy);
	enemy = new Urubu(0, 1000);
	enemies.push_back(enemy);
	enemy = new Urubu(1, 1050);
	enemies.push_back(enemy);
	enemy = new Urubu(0, 1150);
	enemies.push_back(enemy);
	enemy = new Urubu(1, 1200);
	enemies.push_back(enemy);
	enemy = new Urubu(0, 1400);
	enemies.push_back(enemy);
}

void
LevelOne::generateItens()
{
	step("[LevelOne] Generating Itens.");
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
/*	if (enemies.size() < 1)
	{
    	step("[LevelOne] Spawn a New Curupira.");
		enemy = new Curupira(0, (rand() % 200) + 300);
		enemy->init();
		enemies.push_back(enemy);
	}	
*/
	damagingCaio();
	lootItem();
	killingEnemy();	
}

void 
LevelOne::damagingCaio()
{
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
				hp->setHp(caio->getHealth());
				cout << "hp: " << hp->getHp() << endl;
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
}

void
LevelOne::lootItem()
{
	auto loot = itens.end();

	for (auto it = itens.begin(); it != itens.end(); it++)
	{
		loop("[LevelOne] Verifying Collision Between Caio and Itens.");
		if (caio->overItem((*it)->getPosition()))
		{
			loot = it;
		}
	}

	if (loot != itens.end())
	{
    	loop("[LevelOne] Delete all Dead Enemies.");
  		delete *loot;
		itens.erase(loot);
	}
}

void
LevelOne::killingEnemy()
{
	auto dead = enemies.end();

	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		if (aim->overEnemy((*it)->getPosition()))
		{
    		loop("[LevelOne] if Shooted an Enemy, define Dead to it.");
			dead = it;
   			SDL_Rect position = (*dead)->getPosition();

			switch ((*dead)->getItem())
			{
				case 0:
					// Nothing to drop
				break;
				case 1: // Normal Potion Drop
					item = new Potion(round(position.x + (position.w/2)), position.y);
					item->init();
					itens.push_back(item);
				break;
				case 2: // Altered Potion Drop
					item = new AlteredPotion(round(position.x + (position.w/2)), position.y);
					item->init();
					itens.push_back(item);
				break;
				case 3:
				break;
				case 4:
				break;
				case 5:
				break;
				case 6:
				break;
				default:
				break;
			}
		}
	}

	if (dead != enemies.end())
	{
    	loop("[LevelOne] Delete all Dead Enemies.");
  		delete *dead;
		enemies.erase(dead);
	}
}
