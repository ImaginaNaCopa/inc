#include "antiboss.h"

AntiBoss::AntiBoss(int earlyPositionX, int earlyPositionY) : Item()
{
    step("[AntiBoss] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 33, 40);
    generateClips();
    m_dropspeed = 5;
    id = 8;
}

AntiBoss::~AntiBoss(){}

void
AntiBoss::generateClips()
{
    step("[AntiBoss] Generating Sprite Clips.");
    addClip(40,40,32,40);
}

void
AntiBoss::update()
{
    loop("[AntiBoss] Updating.");
    m_clipNumber = 0;

    condition("[Caio] If AntiBoss is in the air.");
    m_position.y += m_dropspeed;
    m_dropspeed += 0.5f;

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        condition("[AntiBoss] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
    }
}
