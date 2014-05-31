#include "caio.h"

using namespace std;
using namespace collision;

Caio::Caio() : ImageEffect()
{
    step("[Caio] Trying to Construct.");
    imagePath.clear();
    imagePath.insert(0,"res/images/s_caio.png");
    generatePosition(50,350,50,100);
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
    step("[Caio] Destroying.");
    release();
}

void
Caio::update(Uint32 delta)
{
    loop("[Caio] Updating.");
    if( isJumping )
    {
        action(0,"[Caio] Jumping.");
        m_position.y -= jumpspeed;
        jumpspeed -= 0.4f;
    }

    if ( !isCrouching )
    {
        action(0,"[Caio] Moving.");
        m_position.x += round(((speed*delta)/1000.0)*dx);
    }

    if( (m_position.x < 0) || ( (m_position.x + m_position.w) >= 1600 ) )
    {
        action(0,"[Caio] Window Collision.");
        m_position.x -= round((speed*delta)/1000.0)*dx;
    }

    if ( (m_position.y + m_position.h) >= 450 )
    {
        action(0,"[Caio] Platform Collision.");
        m_position.y = 450 - m_position.h;
        isJumping = false;
        jumpspeed = 10;
    }
}

bool
Caio::overEnemy(SDL_Rect rect)
{
    if(ifCollided(1,getPosition(),rect))
    {
        m_position.x -= 1;
        return true;
    }
    else if(ifCollided(2,getPosition(),rect))
    {
        m_position.x += 1;
        return true;
    }
    return false;
}

void
Caio::generateClips()
{
    step("[Caio] Generating Sprite Clips.");
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
    step("[Caio] Finished Generating Sprite Clips.");

}

bool 
Caio::handle(SDL_Event& event)
{
    loop("[Caio] Handling Events.");
    bool processed = false;
    switch (event.type)
    {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
                    controls(1,"[Caio] Button a Down.");
                    processed = true;
                    moveBackward();
                break;
                case SDLK_d:
                    controls(1,"[Caio] Button d Down.");
                    processed = true;
                    moveForward();
                break;
                case SDLK_s:
                    controls(1,"[Caio] Button s Down.");
                    processed = true;
                    moveCrouch();
                break;
                case SDLK_SPACE:
                    controls(1,"[Caio] Button SPACE Down.");
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
                    controls(1,"[Caio] Button a Up.");
                    processed = true;
                    isMoving = false;
                    dx = 0;
                break;
                case SDLK_d:
                    controls(1,"[Caio] Button d Up.");
                    processed = true;
                    isMoving = false;
                    dx = 0;
                break;
                case SDLK_s:
                    controls(1,"[Caio] Button s Up.");
                    processed = true;
                    isCrouching = false;
                    m_position.h = 100;
                    m_clipNumber = 0;
                break;              
                case SDLK_SPACE:
                    controls(1,"[Caio] Button SPACE Up.");
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