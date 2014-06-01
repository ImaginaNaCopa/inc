#include "stage.h"

using namespace std;

Stage::Stage() : Scenario(), Hud(), Entity()
{}

Stage::~Stage()
{
	release();
}

void 
Stage::init()
{
    initScenario();
	initHud();
    initEntity();
}

void 
Stage::draw()
{
    drawScenario();
	drawHud();
    drawEntity();
}

void 
Stage::update()
{
	updateEntity();
	controlEntityEvents();
}

void 
Stage::release()
{
    releaseScenario();
	releaseHud();
    releaseEntity();
}