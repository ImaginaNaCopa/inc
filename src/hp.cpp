#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "hp.h"

using namespace std;

Hp::Hp() : ImageSprite()
{
	generatePosition(0,0,50,15);
	generateClips();
	isDrawn = false;
}

Hp::~Hp()
{
}

void 
Hp::init()
{
	loadFromFile("res/images/s_hud.png");
}

void 
Hp::draw()
{
	m_position.x = 10;
	m_position.y = 10;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
    m_position.x = 60;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
    m_position.x = 110;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
}

void 
Hp::release()
{
	SDL_DestroyTexture(m_texture);	
}

void
Hp::generateClips()
{
	addClip(0,0,m_position.w,m_position.h);
	addClip(m_position.w,0,m_position.w,m_position.h);
}