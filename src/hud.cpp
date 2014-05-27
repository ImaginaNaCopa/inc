#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "hud.h"

using namespace std;

Hud::Hud()
{
	try 
	{
		hp = new Hp();
		inventory = new Inventory();
		dialogue = new Dialogue();
		sebastiao = new Sebastiao();
	}
	catch (const string& e)
	{
		delete sebastiao;
		delete dialogue;
		delete inventory;
		delete hp;

		throw e;	
	}
}

Hud::~Hud()
{
	delete sebastiao;
	delete dialogue;
	delete inventory;
	delete hp;
}

void 
Hud::init()
{
	hp->init();
	inventory->init();
	dialogue->init();
	sebastiao->init();
}

void 
Hud::draw()
{
	hp->draw();
	inventory->draw();
	dialogue->draw();
	sebastiao->draw();
}

void 
Hud::update()
{
	// Nothing yet
}

void 
Hud::release()
{
	hp->release();
	inventory->release();
	dialogue->release();
	sebastiao->release();
}