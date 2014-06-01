#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "scenario.h"
#include "systemlogger.h"

using namespace std;

Scenario::Scenario() {}

Scenario::~Scenario()
{
	releaseScenario();
	delete secondlayer;
	delete platform;
	delete background;
}

void 
Scenario::initScenario()
{
	background->init();
	platform->init();
	secondlayer->init();
}

void 
Scenario::drawScenario()
{
	background->draw();
	secondlayer->drawEach();
	platform->draw();
    loop("[Scenario] Finished Draw");
}

void 
Scenario::updateScenario() {}

void 
Scenario::releaseScenario()
{
	secondlayer->release();
	platform->release();
	background->release();
}

void
Scenario::defineBackground() {}

void
Scenario::generatePlatform() {}

void
Scenario::generateSecondLayer() {}