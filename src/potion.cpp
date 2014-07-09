#include "potion.h"

Potion::Potion(int earlyPositionX, int earlyPositionY) : Item()
{
    step("[Potion] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 32, 40);
    generateClips();
    m_dropspeed = 5;
    id = 1;
}

Potion::~Potion()
{
    step("[Potion] Destroying.");
}

void 
Potion::generateClips()
{
    step("[Potion] Generating Sprite Clips.");
    addClip(0,0,32,40);
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
