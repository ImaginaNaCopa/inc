#include "inclogo.h"

InCLogo::InCLogo(int earlyPositionX, int earlyPositionY) : Item()
{
    step("[InCLogo] Constructing.");
    imagePath.assign("res/images/s_item.png");
    generatePosition(earlyPositionX, earlyPositionY, 33, 40);
    generateClips();
    id = 7;
}

InCLogo::~InCLogo(){}

void
InCLogo::generateClips()
{
    step("[InCLogo] Generating Sprite Clips.");
    addClip(0,40,40,40);
}

void
InCLogo::update()
{
    loop("[InCLogo] Updating.");
    m_clipNumber = 0;
}
