#include "caio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

Caio::Caio()
{
	position.x = 50;
	position.y = 350;
	position.w = 50;
	position.h = 100;

	isDrawn = false;
	speed = 110;
    gravity = 0;
	dx = 0;
    dy = 0;

    imageLoad = imageLoad->getInstance();
}

Caio::~Caio()
{
	// Nothing yet
}

void 
Caio::init()
{
	m_texture = imageLoad->loadImg("res/images/caio.png");
}

void 
Caio::draw()
{
    imageLoad->update(m_texture, &position);
}

void
Caio::update(Uint32 delta)
{
    position.x += round(((speed*delta)/1000.0)*dx);
	position.y -= round(((speed*delta)/1000.0)*dy);

	if( (position.x < 0) || ( position.x > 800 ) )
    {
        position.x -= ((speed*delta)/1000.0)*dx;
    }
    
    if( position.y < 150)
    {
        position.y += ((speed*delta)/1000.0)*dy;
        gravity = 0;
    }
}

void 
Caio::release()
{
	SDL_DestroyTexture(m_texture);
}

bool 
Caio::handle(SDL_Event& event)
{
    bool processed = false;
    switch (event.type)
    {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
					dx = -1;
                    processed = true;
                break;
                case SDLK_d:
                    dx = 1;
                    processed = true;
                break;
                case SDLK_SPACE:
                    dy = 1;
                    processed = true;
                break;
                default:
                break;
            }
        break;

        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
                	dx = 0;
                    processed = true;
                break;
                case SDLK_d:
                	dx = 0;
                    processed = true;
                break;
                case SDLK_SPACE:
                    dy = 0;
                    processed = true;
                break;
                default:
                break;
            }
        break;

        default:
        break;
    }
    return processed;
}
