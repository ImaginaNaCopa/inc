#include "alteredpotion.h"

AlteredPotion::AlteredPotion(int earlyPositionX, int earlyPositionY) : Item()
{
    step("[AlteredPotion] Constructing.");
    imagePath.assign("res/images/s_alteredpotion.png");
    generatePosition(earlyPositionX, earlyPositionY, 20, 20);
    generateClips();
    m_dropspeed = 5;
    id = 2;
}

AlteredPotion::~AlteredPotion(){}

void
AlteredPotion::generateClips()
{
    step("[AlteredPotion] Generating Sprite Clips.");
    addClip(0,0,m_position.w,m_position.h);
}

void
AlteredPotion::update()
{
    loop("[AlteredPotion] Updating.");
    m_clipNumber = 0;

    condition("[Caio] If AlteredPotion is in the air.");
    m_position.y += m_dropspeed;
    m_dropspeed += 0.5f;

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        condition("[AlteredPotion] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
    }
}
