#include "hp.h"

Hp::Hp() : ImageSprite()
{
	step("[HP] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(0,10,50,15);
	generateClips();
}

Hp::~Hp()
{
	step("[HP] Destroying.");
	release();
}

void
Hp::generateClips()
{
	step("[HP] Generating Sprite Clips.");
	addClip(0,0,m_position.w,m_position.h);
	addClip(m_position.w,0,m_position.w,m_position.h);
}

void 
Hp::drawEach()
{
	loop("[HP] Drawing Each Health Bar.");
	m_position.x = 10;
	m_position.y = 10;
    draw();
    m_position.x = 60;
    draw();
    m_position.x = 110;
    draw();
}