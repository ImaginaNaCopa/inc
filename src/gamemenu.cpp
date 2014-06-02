#include "gamemenu.h"
#include "systemlogger.h"

GameMenu::GameMenu() : ImageSprite()
{
	imagePath.clear();
	imagePath.assign("res/images/s_hud.png");
	generatePosition(760,10,30,30);
	generateClips();
	isDrawn = false;
}

GameMenu::~GameMenu()
{
}

void
GameMenu::generateClips()
{
	step("[GameMenu] Generating Sprite Clips.");
	addClip(0,55,30,30);
	step("[GameMenu] Finished Generating Sprite Clips.");
}