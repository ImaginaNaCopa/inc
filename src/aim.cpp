#include "aim.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

//construtor modificado
Aim::Aim()
{
	m_position.x = 400;
	m_position.y = 300;
	m_position.w = 87;
	m_position.h = 90;

    m_clips[0].x = 100;
    m_clips[0].y = 0;
    m_clips[0].w = 90;
    m_clips[0].h = 90;

    m_clips[1].x = 200;
    m_clips[1].y = 0;
    m_clips[1].w = 90;
    m_clips[1].h = 90;
    
    m_clips[2].x = 300;
    m_clips[2].y = 0;
    m_clips[2].w = 90;
    m_clips[2].h = 90;

    u = 2;

    imageLoad = imageLoad->getInstance();
    m_imageSprite = new ImageSprite();
    SDL_ShowCursor(0);
}

Aim::~Aim()
{
	delete m_imageSprite;
}

// Função modificada
void 
Aim::init()
{
    m_imageSprite->loadFromFile("res/images/s_aim.png");
}

// Função modificada
void 
Aim::draw()
{
    imageLoad->update(m_imageSprite->m_texture, &m_clips[u], &m_position);   
}

void 
Aim::update()
{
	if(m_position.y < 90)
        u = 0;
    else
        u = 2;

    //cout << Caio::getPositionX() << endl;
	//if((m_position.x + 90) > 800)
     //   m_position.x = 710;
}

void
Aim::overPlayer(SDL_Rect rect)
{   
    // Caution cursor if it's pointed to Caio   
    if (m_position.x < rect.x && m_position.x > rect.x-45 && m_position.y < rect.y+55 && m_position.y > rect.y-45)
        u = 0;
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
            m_position.x = event.motion.x;
            m_position.y = event.motion.y;
            processed = true;
        break;

        case SDL_MOUSEBUTTONDOWN:
            //u++;
            processed = true;
        break;

        case SDL_MOUSEBUTTONUP:
            //u--;
            processed = true;
        break;

        default:
        break;
    }
    return processed;
}
