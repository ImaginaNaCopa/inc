#include "gameover.h"

GameOver::GameOver() : ImageEffect()
{
	step("[GameOver] Constructing.");
	imagePath.assign("res/images/s_gameover.png");
	generatePosition(0,0,800,600);
	generateClips();
	m_use = false;
	m_return = false;
	m_skip = false;

	m_text = new Text(getFontTulpenOne(),getFontSize(8));
	m_text->addPosition(getWindowW()/2-280, getWindowH()/2+60);
	m_text->addText("Pressione ESC para continuar!");
	m_text->setColor(255, 255, 255, 255);
	m_text->setTextNumber(0);
	m_text->setPositionNumber(0);
}

GameOver::~GameOver()
{
	step("[GameOver] Destroying.");
	release();
}

void
GameOver::generateClips()
{
	step("[GameOver] Generating Sprite Clips.");
	addClip(0,0,800,600);
}

void
GameOver::update()
{
	loop("[GameOver] Drawing if is not Over.");
	
	if (m_skip)
		setTimelineEvent(MAINMENU);

	if(isCOpenedMenu())
	{
		if(!m_use)
		{
			m_use = true;
			m_skip = true;
			falseCOpenMenu();
		}
	}
	else
		m_use = false;

	draw();
	m_text->drawText();
}