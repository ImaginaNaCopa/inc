#include "hp.h"

Hp::Hp() : ImageSprite()
{
	step("[HP] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(0,10,50,15);
	generateClips();
	hp = 3;
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
	m_position.y = 10;

	switch (hp)
	{
		case 1:
			m_position.x = 10;
			draw();
		break;
		case 2:
			m_position.x = 10;
			draw();
			m_position.x = 60;
			draw();
		break;
		case 3:
			m_position.x = 10;
			draw();
			m_position.x = 60;
			draw();
			m_position.x = 110;
			draw();
		break;
		case 4:
			m_position.x = 10;
			draw();
			m_position.x = 60;
			draw();
			m_position.x = 110;
			draw();
			m_position.x = 160;
			draw();
		break;
		case 5:
			m_position.x = 10;
			draw();
			m_position.x = 60;
			draw();
			m_position.x = 110;
			draw();
			m_position.x = 160;
			draw();
			m_position.x = 210;
			draw();
		break;
		default:
		break;
	}
}

void 
Hp::setHp(int health)
{
	hp = health;
}

int
Hp::getHp()
{
	return hp;
}