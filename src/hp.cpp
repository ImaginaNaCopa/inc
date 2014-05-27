#include "hp.h"
#include "imageload.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Hp::Hp()
{
	position.x = 10;
	position.y = 10;
	position.w = 30;
	position.h = 20;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Hp::~Hp()
{
	// Nothing yet
}

void 
Hp::init()
{
	m_texture = imageLoad->loadImg("res/images/hp.png");
}

void 
Hp::draw()
{
    imageLoad->update(m_texture, NULL, &position);
    position.x = 50;
    imageLoad->update(m_texture, NULL, &position);
    position.x = 90;
    imageLoad->update(m_texture, NULL, &position);
}

void 
Hp::release()
{
	SDL_DestroyTexture(m_texture);	
}