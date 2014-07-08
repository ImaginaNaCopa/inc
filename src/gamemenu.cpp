#include "gamemenu.h"
#include "systemlogger.h"

GameMenu::GameMenu() : ImageSprite()
{
	step("[GameMenu] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(760,10,35,35);
	generateClips();
}

GameMenu::~GameMenu()
{
	step("[GameMenu] Destroying.");
	release();
}

void
GameMenu::generateClips()
{
	step("[GameMenu] Generating Sprite Clips.");
	addClip(40,50,35,35);
}