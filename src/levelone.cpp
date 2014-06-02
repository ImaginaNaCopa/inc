#include "levelone.h"

LevelOne::LevelOne() : Stage()
{
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	generateEnemies();
}

LevelOne::~LevelOne() {}

void
LevelOne::defineBackground()
{
	background = new Background("res/images/s_02.png");
	background->addClip(0,0,2,2);
}

void
LevelOne::generatePlatform()
{
	platform = new Platform("res/images/s_02.png");

}

void
LevelOne::generateSecondLayer()
{
	secondlayer = new SecondLayer("res/images/s_02.png");
}

void
LevelOne::generateEnemies()
{
	enemy = new Curupira(700);
	enemies.push_back(enemy);

	enemy = new Curupira(330);
	enemies.push_back(enemy);
}

void
LevelOne::controlEntityEvents()
{
	if (enemies.size() < 1)
	{
		enemy = new Curupira((rand() % 200) + 300);
		enemy->init();
		enemies.push_back(enemy);
	}	

	auto dead = enemies.end();

	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		if (aim->overEnemy((*it)->m_position))
		{
			dead = it;
		}
	}

	if (dead != enemies.end())
	{
		delete *dead;
		enemies.erase(dead);
	}
}