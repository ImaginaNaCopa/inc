#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "scenario.h"

using namespace std;

Scenario::Scenario()
{
	try
	{
		background = new Background();
		secondlayer = new SecondLayer();
		platform = new Platform();
	}
	catch (const string& e)
	{
		delete platform;
		delete secondlayer;
		delete background;

		throw e;
	}
}

Scenario::~Scenario()
{
	delete platform;
	delete secondlayer;
	delete background;
}

void 
Scenario::init()
{
	background->init();
	secondlayer->init();
	platform->init();
}

void 
Scenario::draw()
{
	background->draw();
	secondlayer->draw();
	platform->draw();
}

void 
Scenario::update()
{
	// Nothing yet
}

void 
Scenario::release()
{
	platform->release();
	secondlayer->release();
	background->release();
}