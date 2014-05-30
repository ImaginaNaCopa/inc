#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "stage.h"
#include "camera.h"

using namespace std;

Stage::Stage()
{
	try
	{
		hud = new Hud();
		entity = new StageEntity();
		scenario = new Scenario();
		//camera = new Camera();
	}
	catch (const string& e)
	{
		//delete camera;
		delete scenario;
		delete entity;
		delete hud;

		throw e;
	}
}

Stage::~Stage()
{
	//delete camera;
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
    SystemLogger::loop("[Stage] Finished Draw");
}

void 
Stage::update(Uint32 delta)
{
	entity->update(delta);
	SystemLogger::loop("[Stage] Finished Updates");
	//camera->update();
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