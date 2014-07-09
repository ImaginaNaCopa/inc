#include "hp.h"

Hp::Hp() : ImageSprite()
{
	step("[HP] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(0,10,50,15);
	generateClips();
	hp = 3;
	maxHp = 3;
	poisonedHp = 0;
}

Hp::~Hp(){}

void
Hp::generateClips()
{
	step("[HP] Generating Sprite Clips.");
	addClip(0,0,50,15);
	addClip(0,15,50,15);
	addClip(0,30,50,15);
}

void 
Hp::drawEach()
{
	loop("[HP] Drawing Each Health Bar.");
	m_position.y = 10;
	m_position.x = 10;
	int iterator = 0;
	int poisoned = poisonedHp;
	for(iterator = 0; iterator < maxHp; iterator++)
	{
		if(hp > iterator && poisoned == 0)
			setOnlyClipNumber(0);
		else if(hp > iterator && poisoned != 0)
		{
			setOnlyClipNumber(1);
			poisoned--;
		}
		else
			setOnlyClipNumber(2);
		draw();
		m_position.x += 45;
	}
}

void 
Hp::setHp(int health)
{
	hp = health;
}

void
Hp::setMaxHp(int max)
{
	maxHp = max;
}

void
Hp::setPoisonedHp(int poison)
{
	poisonedHp = poison;
}

int
Hp::getHp()
{
	return hp;
}