#include "caio.h"
#include "systemlogger.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

Caio::Caio() : ImageSprite()
{
    generatePosition();
    generateClips();
	speed = 110;
    jumpspeed = 10;
    isMoving = false;
    isJumping = false;
    isCrouching = false;
	dx = 0;
}

Caio::~Caio()
{
}

void 
Caio::init()
{
	loadFromFile("res/images/s_caio.png");
}

void 
Caio::draw()
{
    SDL_Rect clip = m_clips.at(m_clipNumber);
    imageLoad->update(m_texture, &clip, &m_position);
}

void
Caio::update(Uint32 delta)
{
    if( isJumping )
    {
        m_position.y -= jumpspeed;
        jumpspeed -= 0.5f;
    }

    if ( !isCrouching )
        m_position.x += round(((speed*delta)/1000.0)*dx);

    if( (m_position.x < 0) || ( (m_position.x + m_position.w) >= 800 ) )
        m_position.x -= round((speed*delta)/1000.0)*dx;

    if ( (m_position.y + m_position.h) >= 450 )
    {
        m_position.y = 450 - m_position.h;
        isJumping = false;
        jumpspeed = 10;
    }
}

void 
Caio::release()
{
	SDL_DestroyTexture(m_texture);
}

SDL_Rect
Caio::getPosition() const
{
    return m_position;
}

void
Caio::generatePosition()
{
    m_position.x = 50;
    m_position.y = 350;
    m_position.w = 50;
    m_position.h = 100;
}

void
Caio::generateClips()
{
    addClip(0,0,m_position.w,m_position.h);
    addClip(m_position.w,0,m_position.w,m_position.h);
    addClip(m_position.w*2,0,m_position.w,m_position.h);
    addClip(m_position.w*3,0,m_position.w,m_position.h);

    addClip(0,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w*2,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w*3,m_position.h,m_position.w,m_position.h);

    addClip(0,m_position.h*2,m_position.w,m_position.h);
    addClip(m_position.w,m_position.h*2,m_position.w,m_position.h-15);
    addClip(m_position.w*2,m_position.h*2,m_position.w,m_position.h-40);
    addClip(m_position.w*3,m_position.h*2,m_position.w,m_position.h-50);

    addClip(0,m_position.h*3,m_position.w,m_position.h);
    addClip(m_position.w,m_position.h*3,m_position.w,m_position.h);
    addClip(m_position.w*2,m_position.h*3,m_position.w,m_position.h);
    addClip(m_position.w*3,m_position.h*3,m_position.w,m_position.h);

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
                    processed = true;
                    moveBackward();
                break;
                case SDLK_d:
                    processed = true;
                    moveForward();
                break;
                case SDLK_s:
                    processed = true;
                    moveCrouch();
                break;
                case SDLK_SPACE:
                    processed = true;
                    moveJump();                
                break;                
                default:
                break;
            }
        break;

        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
                    processed = true;
                    isMoving = false;
                    dx = 0;
                break;
                case SDLK_d:
                    processed = true;
                    isMoving = false;
                    dx = 0;
                break;
                case SDLK_SPACE:
                    processed = true;
                break;
                case SDLK_s:
                    processed = true;
                    isCrouching = false;
                    m_position.h = 100;
                    m_clipNumber = 0;
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

void
Caio::moveForward()
{
    isMoving = true;
    if(!isCrouching)
    {
        dx = 1;
        if((m_clipNumber>=4) && (m_clipNumber<7))
            m_clipNumber++;
        else
            m_clipNumber=4;                        
    }
}

void
Caio::moveBackward()
{
    isMoving = true;
    if(!isCrouching)
    {
        dx = -1;
        if((m_clipNumber>=0) && (m_clipNumber<3))
            m_clipNumber++;
        else
            m_clipNumber=0;
    }
}

void
Caio::moveJump()
{
    if(!isCrouching)
    {
        isJumping = true;                        
        if((m_clipNumber>=12) && (m_clipNumber<15))
            m_clipNumber++;
        else
            m_clipNumber=12;                         
    }
}

void
Caio::moveCrouch()
{
    if( !isMoving )
    {
        isCrouching = true;
        if((m_clipNumber==8)&&(m_position.h==100)&&(!isJumping))
        {
            m_clipNumber++;
            m_position.h -= 15;
            m_position.y += 15;
        }
        else if((m_clipNumber==9)&&(m_position.h==85)&&(!isJumping))
        {
            m_clipNumber++;
            m_position.h -= 25;
            m_position.y += 25;
        }
        else if((m_clipNumber==10)&&(m_position.h==60)&&(!isJumping))
        {
            m_clipNumber++;
            m_position.h -= 10;
            m_position.y += 10;
        }
        else if((m_clipNumber==11)&&(m_position.h==50)&&(!isJumping)){}
        else
            m_clipNumber=8;
    }
}