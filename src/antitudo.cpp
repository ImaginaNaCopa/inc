#include "antitudo.h"

AntiTudo::AntiTudo(int earlyPositionX, int earlyPositionY) : Item()
{
    step("[AntiTudo] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 33, 40);
    generateClips();
    m_dropspeed = 5;
    id = 3;
}

AntiTudo::~AntiTudo(){}

void
AntiTudo::generateClips()
{
    step("[AntiTudo] Generating Sprite Clips.");
    addClip(64,0,33,40);
}

void
AntiTudo::update()
{
    loop("[AntiTudo] Updating.");
    m_clipNumber = 0;

    condition("[Caio] If AntiTudo is in the air.");
    m_position.y += m_dropspeed;
    m_dropspeed += 0.5f;

    if((m_position.y+m_position.h) >= getPlatformH())
    {
        condition("[AntiTudo] Platform Collision.");
        m_position.y = getPlatformH() - m_position.h;
    }
}
