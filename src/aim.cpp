#include "aim.h"

Aim::Aim() : ImageSprite()
{
    step("[Aim] Constructing.");
    imagePath.assign("res/images/s_hud.png");
    generatePosition(round(getWindowW()/2),round(getWindowH()/2),87,90);
    generateClips();
    SDL_ShowCursor(0);
}

Aim::~Aim()
{
    step("[Aim] Destroying.");
    release();
}

void
Aim::generateClips()
{
    image("[Aim] Generating Sprite Clips.");
    addClip(100,0,87,90);
    addClip(200,0,87,90);
    addClip(300,0,87,90);
}

void 
Aim::update()
{
    loop("[Aim] Updating.");
    updateKernel();
    m_clipNumber = 2;
}

void
Aim::overPlayer(SDL_Rect rect)
{
    loop("[Aim] Searching if Targeted an Entity (Over Player).");   
    if (ifCollided(0,getKernel(),rect))
    {
        condition("[Aim] Targeted an Entity (Over Player).");
        m_clipNumber = 0;
    }
}

bool 
Aim::overEnemy(SDL_Rect rect)
{
    loop("[Aim] Searching if Targeted an Entity (Over Enemy).");   
    if (ifCollided(0,getKernel(),rect))
    {
        condition("[Aim] Targeted an Entity (Over Enemy).");
        m_clipNumber = 1;
        return m_shoot;
    }

    return false;
}



bool 
Aim::handle(SDL_Event& event)
{
    loop("[Aim] Handling Events.");
    bool processed = false;
    m_shoot = false;
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
            controls(0,"[Aim] MouseMotion.");
            m_position.x = event.motion.x - 45;
            m_position.y = event.motion.y - 45;
            processed = true;
        break;

        case SDL_MOUSEBUTTONDOWN:
            controls(0,"[Aim] MouseButtonDown.");
            m_shoot = true;
            processed = true;
        break;

        case SDL_MOUSEBUTTONUP:
            controls(0,"[Aim] MouseButtonUp.");
            processed = true;
        break;

        default:
        break;
    }
    return processed;
}

SDL_Rect
Aim::getKernel()
{
    loop("[Aim] Getting Kernel Position.");
    return m_kernel;
}

void
Aim::updateKernel()
{
    loop("[Aim] Updating Kernel Position.");
    m_kernel = {m_position.x+getCameraLeftPosition()+40, m_position.y+40, 5, 5};
}