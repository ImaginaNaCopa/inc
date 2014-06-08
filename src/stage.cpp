#include "stage.h"

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
	updateEntity();
	controlEntityEvents();
}