#include "aim.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

Aim::Aim()
{
	position.x = 400;
	position.y = 300;
	position.w = 20;
	position.h = 20;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Aim::~Aim()
{
	// Nothing yet
}

void 
Aim::init()
{
	m_texture = imageLoad->loadImg("res/images/aim.png");
}

void 
Aim::draw()
{
    imageLoad->update(m_texture, &position);   
}

void 
Aim::update()
{
	if(position.x < 0)
        position.x = 0;
	if((position.x + 20) > 800)
        position.x = 780;
}

void 
Aim::release()
{
	SDL_DestroyTexture(m_texture);
}

bool 
Aim::handle(SDL_Event& event)
{
	bool processed = false;
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
            position.x = event.motion.x-10;
            position.y = event.motion.y-10;

            isDrawn = false;
            return true;
        break;
        default:
        break;
    }
    return processed;
}
