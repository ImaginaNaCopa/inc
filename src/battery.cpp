#include "battery.h"

Battery::Battery(int earlyPositionX, int earlyPositionY) : Item()
{
    //step("[Battery] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 21, 40);
    generateClips();
    m_dropspeed = 5;
    id = 4;
}

Battery::~Battery(){}

void
Battery::generateClips()
{
    //step("[Battery] Generating Sprite Clips.");
    addClip(97,0,21,40);
}

void
Battery::update()
{
    //loop("[Battery] Updating.");
    m_clipNumber = 0;

    //condition("[Caio] If Battery is in the air.");
    m_position.y += m_dropspeed;
    m_dropspeed += 0.5f;

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        //condition("[Battery] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
    }
}
