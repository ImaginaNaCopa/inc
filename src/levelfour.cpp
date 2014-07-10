#include "levelfour.h"

LevelFour::LevelFour() : Stage()
{
	//step("[LevelFour] Constructing.");
	defineBackground();
	generatePlatform();
	generateSecondLayer();
	generateEnemies();
	generateCivilians();
	setFinished(false);
	setGameOver(false);
}

LevelFour::~LevelFour()
{
	//step("[LevelFour] Destroying.");
}

void
LevelFour::defineBackground()
{
	//step("[LevelFour] Defining Background.");
	background = new Background("res/images/s_level04.png");
	background->addClip(262,62,46,46);
}

void
LevelFour::generatePlatform()
{
	//step("[LevelFour] Generating Platform.");
	platform = new Platform("res/images/s_level04.png");
	platform->addClip(322,62,46,46);
}

void
LevelFour::generateSecondLayer()
{
	//step("[LevelFour] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level04.png");
	secondlayer->addClip(0,0,249,142);
	secondlayer->addClip(0,150,100,220);
	secondlayer->addClip(100,150,98,250);
	secondlayer->addClip(198,150,343,220);
	secondlayer->addClip(541,150,391,300);
	secondlayer->addClip(262,2,46,46);
	secondlayer->newIdleTime();
}

void
LevelFour::generateEnemies()
{
	int positionReference = 700;
	while(positionReference < 1100)
	{
		enemy = new Curupira(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 13;
	}
	enemy = new Curupira(0,420);
	enemies.push_back(enemy);
	positionReference = 900;
	while(positionReference < 1200)
	{
		enemy = new Curupira(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 13;
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
		positionReference += 90;
	}
	enemy = new Urubu(4,570);
	enemies.push_back(enemy);
	positionReference = 1250;
	while(positionReference < 1600)
	{
		enemy = new Urubu(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 70;
	}
	enemy = new Urubu(4,925);
	enemies.push_back(enemy);
	positionReference = 1200;
	while(positionReference < 1550)
	{
		enemy = new Urubu(0,positionReference);
		enemies.push_back(enemy);
		positionReference += 50;
	}
	enemy = new Urubu(0,1420);
	enemies.push_back(enemy);
	for (int i = 0; i < 10; i++)
	{
		enemy = new Politico (0, false, 500+100*i);
		enemies.push_back(enemy);
	}
}

void
LevelFour::generateCivilians(){}

void
LevelFour::drawScenarioRelativeImages()
{
	//loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->setOnlyClipNumber(0);
	secondlayer->generatePosition(0,getPlatformH()-80,249,142);
	secondlayer->drawRelative();

	secondlayer->setOnlyClipNumber(3);
	secondlayer->generatePosition(310,getPlatformH()-220,343,220);
	secondlayer->drawRelative();

	secondlayer->generatePosition(1230,getPlatformH()-220,343,220);
	secondlayer->drawRelative();

	secondlayer->setOnlyClipNumber(4);
	secondlayer->generatePosition(820,getPlatformH()-300,391,300);
	secondlayer->drawRelative();
}

void
LevelFour::drawExceptionalRelativeImages()
{
	secondlayer->setOnlyClipNumber(1);
	secondlayer->generatePosition(150,getPlatformH()-60,100,220);
	secondlayer->drawRelative();

	secondlayer->generatePosition(690,getPlatformH()-20,100,220);
	secondlayer->drawRelative();

	secondlayer->setOnlyClipNumber(2);
	secondlayer->generatePosition(400,getPlatformH()-130,98,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(1100,getPlatformH()-180,98,250);
	secondlayer->drawRelative();
}

void
LevelFour::drawShadow()
{
	secondlayer->setOnlyClipNumber(5);
	int radius = 0;
	if(isCSpecial())
	{
		radius = 40+(int)(inventory->getQtdBattery()*1.75);
		secondlayer->defineCurrentIdleTime(1);
		if(secondlayer->getCurrentIdleTime() == 16)
		{
			secondlayer->setCurrentIdleTime(0);
			inventory->setQtdBattery(-1);
		}
		else
			secondlayer->setCurrentIdleTime(secondlayer->getCurrentIdleTime()+1);
	}
	int x = aim->getKernel().x;
	int y = aim->getKernel().y;
	int i = 0;
	int j = 0;
	for(i = 0; i<=100 ; i++)
	{
		for(j = 0; j<=100; j++)
		{
			if(	(8*i+getCameraLeftPosition()<=x-radius||6*j<=y-radius) ||
					(8*i+getCameraLeftPosition()>=x+radius||6*j>=y+radius) ||
					(8*i+getCameraLeftPosition()>x-radius&&6*j<=(y-radius))	)
			{
				secondlayer->generatePosition(8*i,6*j,8,6);
				secondlayer->draw();
			}
		}
	}
	drawHud();
	aim->draw();
}