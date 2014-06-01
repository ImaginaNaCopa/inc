#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "hud.h"
#include "systemlogger.h"

using namespace std;

Hud::Hud()
{
	try 
	{
		hp = new Hp();
		inventory = new Inventory();
		dialogue = new Dialogue();
		sebastiao = new Sebastiao();
		gameMenu = new GameMenu();
	}
	catch (const string& e)
	{
		delete gameMenu;
		delete sebastiao;
		delete dialogue;
		delete inventory;
		delete hp;

		throw e;	
	}
}

Hud::~Hud()
{
	delete gameMenu;
	delete sebastiao;
	delete dialogue;
	delete inventory;
	delete hp;
}

void 
Hud::initHud()
{
	hp->init();
	inventory->init();
	dialogue->init();
	sebastiao->init();
	gameMenu->init();
}

void 
Hud::drawHud()
{
	hp->drawEach();
	inventory->drawEach();
	dialogue->draw();
	sebastiao->draw();
	gameMenu->draw();
    loop("[HUD] Finished Draw");
}

void 
Hud::updateHud()
{
	// Nothing yet
}

void 
Hud::releaseHud()
{
	hp->release();
	inventory->release();
	dialogue->release();
	sebastiao->release();
	gameMenu->release();
}