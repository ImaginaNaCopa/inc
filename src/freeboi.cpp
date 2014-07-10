#include "freeboi.h"

Freeboi::Freeboi(int earlyPositionX, int earlyPositionY) : Item()
{
    //step("[Freeboi] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 40, 22);
    generateClips();
    m_dropspeed = 5;
    id = 5;
}

Freeboi::~Freeboi(){}

void
Freeboi::generateClips()
{
    //step("[Freeboi] Generating Sprite Clips.");
    addClip(118,0,40,22);
}

void
Freeboi::update()
{
    //loop("[Freeboi] Updating.");
    m_clipNumber = 0;

    //condition("[Caio] If Freeboi is in the air.");
    m_position.y += m_dropspeed;
    m_dropspeed += 0.5f;

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        //condition("[Freeboi] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
    }
}
