#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "stage.h"

using namespace std;

Stage::Stage()
{
	try
	{
		hud = new Hud();
		entity = new StageEntity();
		scenario = new Scenario();
	}
	catch (const string& e)
	{
		delete scenario;
		delete entity;
		delete hud;

		throw e;
	}
}

Stage::~Stage()
{
	delete scenario;
	delete entity;
	delete hud;
}

void 
Stage::init()
{
    scenario->init();
	hud->init();
    entity->init();
}

void 
Stage::draw()
{
    scenario->draw();
	hud->draw();
    entity->draw();
}

void 
Stage::update(Uint32 delta)
{
	entity->update(delta);
}

void 
Stage::release()
{
    scenario->release();
	hud->release();
    entity->release();
}

StageEntity*
Stage::getEntity() const
{
	return entity;
}