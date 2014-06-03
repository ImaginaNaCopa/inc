#include "caio.h"

Caio::Caio() : ImageEffect()
{
    step("[Caio] Constructing.");
    imagePath.assign("res/images/s_caio.png");
    generatePosition(round(getWindowW()/16),getPlatformH(),50,100);
    generateClips();
    m_crouching = false;
    m_jumping = false;
    m_moving = false;
	m_dx = 0;
    m_speed = haveNormalSpeed();
    m_jumpspeed = 10;
}

Caio::Caio(int initialPosition) : ImageEffect()
{
    step("[Caio] Constructing.");
    imagePath.assign("res/images/s_caio.png");
    generatePosition(initialPosition,getPlatformH(),50,100);
    generateClips();
    m_crouching = false;
    m_jumping = false;
    m_moving = false;
    m_dx = 0;
    m_speed = haveNormalSpeed();
    m_jumpspeed = 10;
}

Caio::~Caio()
{
    step("[Caio] Destroying.");
    release();
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
}

void
Caio::update()
{
    loop("[Caio] Updating.");
    if(isJumping())
    {
        condition("[Caio] If Jumping, handle movement.");
        m_position.y -= m_jumpspeed;
        m_jumpspeed -= 0.4f;
    }

    if(!isCrouching())
    {
        condition("[Caio] If isnt Crouching, Caio moves.");
        m_position.x += round(((m_speed*getDelta())/1000.0)*m_dx);
    }

    if((m_position.x < 0) || ((m_position.x+m_position.w) >= getLevelW()))
    {
        condition("[Caio] Scenario Limit Collision.");
        m_position.x -= round(((m_speed*getDelta())/1000.0)*m_dx);
    }

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        condition("[Caio] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
        m_jumping = false;
        m_jumpspeed = 10;
    }
}

bool
Caio::overEnemy(SDL_Rect rect)
{
    loop("[Caio] Checking if Collided with a Rectangle.");
    if(ifCollided(1,getPosition(),rect))
    {
        condition("[Caio] Collided on left side.");
        m_position.x -= 1;
        return true;
    }
    else if(ifCollided(2,getPosition(),rect))
    {
        condition("[Caio] Collided on right side.");
        m_position.x += 1;
        return true;
    }
    return false;
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
                    m_moving = false;
                    m_dx = 0;
                break;
                case SDLK_d:
                    controls(1,"[Caio] Button d Up.");
                    processed = true;
                    m_moving = false;
                    m_dx = 0;
                break;
                case SDLK_s:
                    controls(1,"[Caio] Button s Up.");
                    processed = true;
                    m_crouching = false;
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
Caio::moveBackward()
{
    action(0,"[Caio] Moving Backward.");
    m_moving = true;
    if(!isCrouching())
    {
        m_dx = -1;
        if((m_clipNumber >= 0) && (m_clipNumber < 3))
            m_clipNumber++;
        else
            m_clipNumber=0;
    }
}

void
Caio::moveCrouch()
{
    action(0,"[Caio] Crouching.");
    if(!isMoving())
    {
        m_crouching = true;
        if((m_clipNumber==8) && (m_position.h==100) && (!isJumping()))
        {
            m_clipNumber++;
            m_position.h -= 15;
            m_position.y += 15;
        }
        else if((m_clipNumber==9) && (m_position.h==85) && (!isJumping()))
        {
            m_clipNumber++;
            m_position.h -= 25;
            m_position.y += 25;
        }
        else if((m_clipNumber==10) && (m_position.h==60) && (!isJumping()))
        {
            m_clipNumber++;
            m_position.h -= 10;
            m_position.y += 10;
        }
        else if((m_clipNumber==11) && (m_position.h==50) && (!isJumping())){}
        else
            m_clipNumber=8;
    }
}

void
Caio::moveForward()
{
    action(0,"[Caio] Moving Forward.");
    m_moving = true;
    if(!isCrouching())
    {
        m_dx = 1;
        if((m_clipNumber >= 4) && (m_clipNumber < 7))
            m_clipNumber++;
        else
            m_clipNumber=4;                        
    }
}

void
Caio::moveJump()
{
    action(0,"[Caio] Jumping.");
    if(!isCrouching())
    {
        m_jumping = true;                        
        if((m_clipNumber >= 12) && (m_clipNumber < 15))
            m_clipNumber++;
        else
            m_clipNumber=12;                         
    }
}

bool
Caio::isCrouching()
{
    loop("[Caio] Verifying if Caio is Crouching.");
    return m_crouching;
}

bool
Caio::isJumping()
{
    loop("[Caio] Verifying if Caio is Jumping.");
    return m_jumping;
}

bool
Caio::isMoving()
{
    loop("[Caio] Verifying if Caio is Moving.");
    return m_moving;
}

float
Caio::getJumpspeed()
{
    loop("[Caio] Getting Jump Speed.");
    return m_jumpspeed;
}

int
Caio::getDirection()
{
    loop("[Caio] Getting Direction.");
    return m_dx;
}

int
Caio::getSpeed()
{
    loop("[Caio] Getting Speed.");
    return m_speed;
}

void
Caio::setSpeed(int speed)
{
    loop("[Caio] Setting a New Speed.");
    m_speed = speed;
}