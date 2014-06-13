#include "potion.h"

Potion::Potion(int earlyPositionX, int earlyPositionY) : Item()
{
    step("[Potion] Constructing.");
    imagePath.assign("res/images/s_potion.png");
    generatePosition(earlyPositionX, earlyPositionY, 20, 20);
    generateClips();
    m_dropspeed = 5;
    id = 1;
}

Potion::~Potion()
{
    step("[Potion] Destroying.");
    release();
}

void 
Potion::generateClips()
{
    step("[Potion] Generating Sprite Clips.");
    addClip(0,0,m_position.w,m_position.h);
}

void 
Potion::update()
{
    loop("[Potion] Updating.");
    m_clipNumber = 0;

    condition("[Caio] If Potion is in the air.");
    m_position.y += m_dropspeed;
    m_dropspeed += 0.5f;

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        condition("[Potion] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
    }
}
