#include "gamemenu.h"

GameMenu::GameMenu() : ImageSprite()
{
	generatePosition(760,10,30,30);
	generateClips();
	isDrawn = false;
}

GameMenu::~GameMenu()
{
}

void
GameMenu::init()
{
	loadFromFile("res/images/s_hud.png");
}

void
GameMenu::draw()
{
	imageLoad->update(m_texture, &m_clips.at(0), &m_position);
}

void
GameMenu::release()
{
	SDL_DestroyTexture(m_texture);
}

void
GameMenu::generateClips()
{
	addClip(0,55,30,30);
}