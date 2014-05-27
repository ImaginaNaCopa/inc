#include "inventory.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Inventory::Inventory()
{
	position.x = 10;
	position.y = 40;
	position.w = 35;
	position.h = 25;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Inventory::~Inventory()
{
	// Nothing yet
}

void 
Inventory::init()
{
	m_texture = imageLoad->loadImg("res/images/inventario.png");

}

void 
Inventory::draw()
{
    imageLoad->update(m_texture, &position);
    position.x = 50;
    imageLoad->update(m_texture, &position);
    position.x = 90;
    imageLoad->update(m_texture, &position);
    position.x = 130;
    imageLoad->update(m_texture, &position);
    position.x = 170;
    imageLoad->update(m_texture, &position);
    position.x = 210;
    imageLoad->update(m_texture, &position);
}

void 
Inventory::release()
{
	SDL_DestroyTexture(m_texture);
}