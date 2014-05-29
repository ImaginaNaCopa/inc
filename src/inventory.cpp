#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "inventory.h"

using namespace std;

Inventory::Inventory() : ImageSprite()
{
    generatePosition(0,0,40,40);
    generateClips();
    isDrawn = false;
}

Inventory::~Inventory()
{
}

void 
Inventory::init()
{
	loadFromFile("res/images/s_hud.png");
}

void 
Inventory::draw()
{
    m_position.x = 10;
    m_position.y = 30;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
    m_position.x += 5 + m_position.w;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
    m_position.x += 5 + m_position.w;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
    m_position.x += 5 + m_position.w;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
    m_position.x += 5 + m_position.w;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
    m_position.x += 5 + m_position.w;
    imageLoad->update(m_texture, &m_clips.at(0), &m_position);
}

void 
Inventory::release()
{
	SDL_DestroyTexture(m_texture);
}

void
Inventory::generateClips()
{
    addClip(0,15,m_position.w,m_position.h);
}