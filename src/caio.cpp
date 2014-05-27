#include "caio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

Caio::Caio()
{
	m_position.x = 50;
	m_position.y = 350;
	m_position.w = 50;
	m_position.h = 100;

    m_clips[0].x = 0;
    m_clips[0].y = 0;
    m_clips[0].w = 50;
    m_clips[0].h = 100;

    m_clips[1].x = 50;
    m_clips[1].y = 0;
    m_clips[1].w = 50;
    m_clips[1].h = 100;

    m_clips[2].x = 100;
    m_clips[2].y = 0;
    m_clips[2].w = 50;
    m_clips[2].h = 100;

    m_clips[3].x = 150;
    m_clips[3].y = 0;
    m_clips[3].w = 50;
    m_clips[3].h = 100;

    m_clips[4].x = 0;
    m_clips[4].y = 100;
    m_clips[4].w = 50;
    m_clips[4].h = 100;

    m_clips[5].x = 50;
    m_clips[5].y = 100;
    m_clips[5].w = 50;
    m_clips[5].h = 100;

    m_clips[6].x = 100;
    m_clips[6].y = 100;
    m_clips[6].w = 50;
    m_clips[6].h = 100;

    m_clips[7].x = 150;
    m_clips[7].y = 100;
    m_clips[7].w = 50;
    m_clips[7].h = 100;

    m_clips[8].x = 0;
    m_clips[8].y = 200;
    m_clips[8].w = 50;
    m_clips[8].h = 100;

    m_clips[9].x = 50;
    m_clips[9].y = 200;
    m_clips[9].w = 50;
    m_clips[9].h = 85;

    m_clips[10].x = 100;
    m_clips[10].y = 200;
    m_clips[10].w = 50;
    m_clips[10].h = 60;

    m_clips[11].x = 150;
    m_clips[11].y = 200;
    m_clips[11].w = 50;
    m_clips[11].h = 50;

    m_clips[12].x = 0;
    m_clips[12].y = 300;
    m_clips[12].w = 50;
    m_clips[12].h = 100;

    m_clips[13].x = 50;
    m_clips[13].y = 300;
    m_clips[13].w = 50;
    m_clips[13].h = 100;

    m_clips[14].x = 100;
    m_clips[14].y = 300;
    m_clips[14].w = 50;
    m_clips[14].h = 100;

    m_clips[15].x = 150;
    m_clips[15].y = 300;
    m_clips[15].w = 50;
    m_clips[15].h = 100;

	isDrawn = false;
	speed = 110;
    gravity = 0;
	dx = 0;
    dy = 0;
    u = 0;

    imageLoad = imageLoad->getInstance();
    m_imageSprite = new ImageSprite();
}

Caio::~Caio()
{
	// Nothing yet
}

void 
Caio::init()
{
	m_imageSprite->loadFromFile("res/images/s_caio.png");
}

void 
Caio::draw()
{
    imageLoad->update(m_imageSprite->m_texture, &m_clips[u], &m_position);
}

void
Caio::update(Uint32 delta)
{
    m_position.x += ((speed*delta)/1000.0)*dx;
	m_position.y -= ((speed*delta)/1000.0)*dy;

	if( (m_position.x < 0) || ( m_position.x > 800 ) )
    {
        m_position.x -= ((speed*delta)/1000.0)*dx;
    }
    
    if( m_position.y < 150)
    {
        m_position.y += ((speed*delta)/1000.0)*dy;
        gravity = 0;
    }
}

void 
Caio::release()
{
	SDL_DestroyTexture(m_imageSprite->m_texture);
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
                    if(u<=3)
                        u++;
                    else
                        u=0;
                break;
                case SDLK_d:
                    dx = 1;
                    processed = true;
                    if((u>=4) && (u<8))
                        u++;
                    else
                        u=4;
                break;
                case SDLK_SPACE:
                    dy = 1;
                    processed = true;
                    u++;
                    if((u>=12) && (u<15))
                        u++;
                    else
                        u=12;                    
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
