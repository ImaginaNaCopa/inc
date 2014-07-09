#include "levelfour.h"

LevelFour::LevelFour() : Stage()
{
	step("[LevelFour] Constructing.");
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
	step("[LevelFour] Destroying.");
}

void
LevelFour::defineBackground()
{
	step("[LevelFour] Defining Background.");
	background = new Background("res/images/s_level04.png");
	background->addClip(162,132,46,46);
}

void
LevelFour::generatePlatform()
{
	step("[LevelFour] Generating Platform.");
	platform = new Platform("res/images/s_level04.png");
	platform->addClip(222,132,46,46);
}

void
LevelFour::generateSecondLayer()
{
	step("[LevelFour] Generating SecondLayer.");
	secondlayer = new SecondLayer("res/images/s_level04.png");
	secondlayer->addClip(80,0,270,120);
	secondlayer->addClip(0,0,80,250);
	secondlayer->addClip(102,132,46,46);
}

void
LevelFour::generateEnemies()
{
	enemy = new Curupira(0,990);
	enemies.push_back(enemy);
}

void
LevelFour::generateCivilians(){}

void
LevelFour::drawScenarioRelativeImages()
{
	loop("[Sebastiao] Drawing Each Image from Second Layer.");
	secondlayer->setOnlyClipNumber(0);
	secondlayer->generatePosition(0,getPlatformH()-120,270,120);
	secondlayer->drawRelative();

	secondlayer->setOnlyClipNumber(1);
	secondlayer->generatePosition(310,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(420,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(510,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(700,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(820,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(950,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(1050,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(1130,getPlatformH()-250,80,250);
	secondlayer->drawRelative();

	secondlayer->generatePosition(1450,getPlatformH()-250,80,250);
	secondlayer->drawRelative();
}
