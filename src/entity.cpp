#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

Entity::Entity()
{
	try 
	{
		caio = new Caio();
		aim = new Aim();
		enemy = new Enemy();
	}
	catch (const string& e)
	{
		delete enemy;
		delete aim;
		delete caio;

		throw e;	
	}

}

Entity::~Entity()
{
	delete enemy;
	delete aim;
	delete caio;
}

void 
Entity::init()
{
	caio->init();
	aim->init();
	enemy->init();
}

void 
Entity::draw()
{
	caio->draw();
	enemy->draw();
	aim->draw();
}

void 
Entity::update(Uint32 delta)
{
	caio->update(delta);
	enemy->update(delta);
	aim->update();
	aim->overPlayer(caio->getRect());
}

void 
Entity::release()
{
	caio->release();
	aim->release();
	enemy->release();
}

Caio*
Entity::getCaio() const
{
	return caio;
}

Aim*
Entity::getAim() const
{
	return aim;
}