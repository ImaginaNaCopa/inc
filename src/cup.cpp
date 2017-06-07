#include "../include/cup.h"

Cup::Cup(int earlyPositionX, int earlyPositionY) : Item()
{
    //step("[Cup] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 22, 40);
    generateClips();
    id = 6;
}

Cup::~Cup(){}

void
Cup::generateClips()
{
    //step("[Cup] Generating Sprite Clips.");
    addClip(158,0,22,40);
}

void
Cup::update()
{
    //loop("[Cup] Updating.");
    m_clipNumber = 0;
}
