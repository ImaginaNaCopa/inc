#include "alteredpotion.h"

AlteredPotion::AlteredPotion(int earlyPositionX, int earlyPositionY) : Item()
{
    //step("[AlteredPotion] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 32, 40);
    generateClips();
    m_dropspeed = 5;
    id = 2;
}

AlteredPotion::~AlteredPotion()
{
    //step("[Aim] Destroying.");
}

void
AlteredPotion::generateClips()
{
    //step("[AlteredPotion] Generating Sprite Clips.");
    addClip(32,0,32,40);
}

void
AlteredPotion::update()
{
    //loop("[AlteredPotion] Updating.");
    m_clipNumber = 0;

    //condition("[Caio] If AlteredPotion is in the air.");
    m_position.y += m_dropspeed;
    m_dropspeed += 0.5f;

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        //condition("[AlteredPotion] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
    }
}
