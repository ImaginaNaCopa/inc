#include "stageentity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

StageEntity::StageEntity()
{
	try 
	{
		caio = new Caio();
		aim = new Aim();
		//enemy = new Enemy();
	}
	catch (const string& e)
	{
		//delete enemy;
		delete aim;
		delete caio;

		throw e;	
	}

}

StageEntity::~StageEntity()
{
	//delete enemy;
	delete aim;
	delete caio;
}

void 
StageEntity::init()
{
	caio->init();
	aim->init();
	//enemy->init();
}

void 
StageEntity::draw()
{
	caio->draw();
	//enemy->draw();
	aim->draw();
}

void 
StageEntity::update(Uint32 delta)
{
	caio->update(delta);
	//enemy->update(delta);
	aim->update();
	aim->overPlayer(caio->getPosition());
}

void 
StageEntity::release()
{
	caio->release();
	aim->release();
	//enemy->release();
}

Caio*
StageEntity::getCaio() const
{
	return caio;
}

Aim*
StageEntity::getAim() const
{
	return aim;
}