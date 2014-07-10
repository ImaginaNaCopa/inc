#include "gameover.h"

GameOver::GameOver() : ImageEffect()
{
	//step("[GameOver] Constructing.");
	imagePath.assign("res/images/s_gameover.png");
	generatePosition(0,0,800,600);
	addClip(0,0,800,600);

	m_text = new Text(getFontTulpenOne(),getFontSize(5));
	m_text->addPosition(150,500);
	m_text->addText("Pressione ABRIR MENU para retornar ao jogo!");
	m_text->setColor(255, 255, 255, 255);
	m_text->setTextNumber(0);
	m_text->setPositionNumber(0);
}

GameOver::~GameOver()
{
	//step("[GameOver] Destroying.");
	delete m_text;
}

void
GameOver::update()
{
	//loop("[GameOver] Drawing if is not Over.");

	if(isCOpenedMenu())
	{
		falseCOpenMenu();
		setOver(true);
	}
	else
	{
		draw();
		m_text->drawText();
	}
}