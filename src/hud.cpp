#include "hud.h"

Hud::Hud()
{
	step("[HUD] Constructing.");
	dialogue = new Dialogue();
	gameMenu = new GameMenu();
	hp = new Hp();
	inventory = new Inventory();
	sebastiao = new Sebastiao();
}

Hud::~Hud()
{
	step("[HUD] Destroying.");
	delete sebastiao;
	delete inventory;
	delete hp;
	delete gameMenu;
	delete dialogue;
}

void 
Hud::initHud()
{
	step("[HUD] Uploading Sprite Sheets.");
	dialogue->init();
	gameMenu->init();
	hp->init();
	inventory->init();
	sebastiao->init();
}

void 
Hud::drawHud()
{
	loop("[HUD] Rendering HUD.");
	dialogue->draw();
	gameMenu->draw();
	hp->drawEach();
	inventory->drawEach();
	sebastiao->update();
}

void 
Hud::updateHud()
{
	inventory->updateInventory();
}
