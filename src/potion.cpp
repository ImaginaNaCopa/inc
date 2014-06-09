#include "potion.h"

Potion::Potion(int earlyPosition) : Item()
{
	step("[Potion] Constructing.");
    imagePath.assign("res/images/s_potion.png");
	generatePosition(earlyPosition,(getPlatformH()-200),10,10);
    generateClips();
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
}