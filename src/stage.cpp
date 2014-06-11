#include "stage.h"
#include <iostream>

using namespace std;

Stage::Stage() : Scenario(), Hud(), Entity()
{}

Stage::~Stage()
{
}

void 
Stage::init()
{
	step("[Stage] Initiating Each Stage Object.");
	initScenario();
	initHud();
	initEntity();
}

void
Stage::draw()
{
	loop("[Stage] Drawing Each Stage Object.");
	drawScenarioStaticImages();
	drawScenarioRelativeImages();
	drawHud();
	drawEntity();
}

void 
Stage::update()
{
	loop("[Stage] Updating Each Stage Object.");

	if (caio->getHealth() == 0)
		cout << "game over" << endl;
	else
	{
		updateEntity();
		controlEntityEvents();
	}
}