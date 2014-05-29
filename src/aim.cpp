#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "aim.h"

using namespace std;

Aim::Aim() : ImageSprite()
{
    SystemLogger::step("[Aim] Trying to Construct.");
    imagePath.clear();
    imagePath.insert(0,"res/images/s_hud.png");
    generatePosition(400,300,87,90);
    generateClips();
    SDL_ShowCursor(0);
}

Aim::~Aim()
{
    SystemLogger::step("[Aim] Destroying.");
    release();
}

void 
Aim::update()
{
    SystemLogger::loop("[Aim] Updating.");
    m_clipNumber = 0;
}

void
Aim::overPlayer(SDL_Rect rect)
{
    SystemLogger::loop("[Aim] Searching if Targeted an Entity (Over Player).");   
    if (    (m_position.x < rect.x) && (m_position.x > rect.x-45) &&
            (m_position.y < rect.y+55) && (m_position.y > rect.y-45)    )
    {
        SystemLogger::condition("[Aim] Targeted an Entity (Over Player).");
        m_clipNumber = 2;
    }
}

void
Aim::generateClips()
{
    SystemLogger::step("[Aim] Generating Sprite Clips.");
    addClip(100,0,87,90);
    addClip(200,0,87,90);
    addClip(300,0,87,90);
    SystemLogger::step("[Aim] Finished Generating Sprite Clips.");
}

bool 
Aim::handle(SDL_Event& event)
{
    SystemLogger::loop("[Aim] Handling Events.");
	bool processed = false;
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
            SystemLogger::conditionPlus(0,"[Aim] MouseMotion.");
            m_position.x = event.motion.x;
            m_position.y = event.motion.y;
            processed = true;
        break;

        case SDL_MOUSEBUTTONDOWN:
            SystemLogger::conditionPlus(0,"[Aim] MouseButtonDown.");
            processed = true;
        break;

        case SDL_MOUSEBUTTONUP:
            SystemLogger::conditionPlus(0,"[Aim] MouseButtonUp.");
            processed = true;
        break;

        default:
        break;
    }
    return processed;
}
