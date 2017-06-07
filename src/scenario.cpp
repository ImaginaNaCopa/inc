#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "../include/scenario.h"
#include "../include/systemlogger.h"

using namespace std;

Scenario::Scenario() {}

Scenario::~Scenario()
{
	//step("[Scenario] Destroying.");
	delete secondlayer;
	delete platform;
	delete background;
}

void 
Scenario::initScenario()
{
	//step("[Scenario] Uploading Sprite Sheets.");
	background->init();
	platform->init();
	secondlayer->init();
}

void 
Scenario::drawScenarioStaticImages()
{
	//loop("[Scenario] Drawing Scenario Non-Relative Images.");
	background->draw();
	platform->draw();
}

void
Scenario::defineBackground() {}

void
Scenario::generatePlatform() {}

void
Scenario::generateSecondLayer() {}

void
Scenario::drawScenarioRelativeImages() {}
