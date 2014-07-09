#include "configurationmenu.h"

ConfigurationMenu::ConfigurationMenu() : Menu("res/images/s_mainmenu.png")
{
	generateIndexTexts();
	m_background = new Background("res/images/s_mainmenu.png");
	m_background->addClip(0,0,800,600);
	m_background->init();
}

ConfigurationMenu::~ConfigurationMenu()
{
	delete m_background;
	delete m_textIndex;
	delete m_textTitle;
	delete m_textOption;
}

void
ConfigurationMenu::generateIndexTexts()
{
	m_textTitle = new Text(getFontTulpenOne(),getFontSize(8));
	m_textTitle->addPosition(50,30);
	m_textTitle->addText("Configuracoes");

	m_textIndex = new Text(getFontTulpenOne(),getFontSize(5));
	m_textIndex->addPosition(50,150);
	m_textIndex->addText("Resolucao:");
	m_textIndex->addPosition(50,200);
	m_textIndex->addText("Modo de Tela:");
	m_textIndex->addPosition(50,250);
	m_textIndex->addText("Sons:");
	m_textIndex->addPosition(50,300);
	m_textIndex->addText("Configuracoes do Controle:");
	m_textIndex->addPosition(100,360);
	m_textIndex->addText("Configurar Controle do Jogador #01");
	m_textIndex->addPosition(100,420);
	m_textIndex->addText("Configurar Controle do Jogador #02");

	m_textOption = new Text(getFontTulpenOne(),getFontSize(3));
	m_textOption->addPosition(200,160);
	m_textOption->addText("800x600");
	m_textOption->addPosition(350,160);
	m_textOption->addText("1024x768");
	m_textOption->addPosition(500,160);
	m_textOption->addText("1440x1080");

	m_textOption->addPosition(300,210);
	m_textOption->addText("Tela Cheia");
	m_textOption->addPosition(500,210);
	m_textOption->addText("Em Janela");

	m_textOption->addPosition(300,260);
	m_textOption->addText("Ativado");
	m_textOption->addPosition(500,260);
	m_textOption->addText("Desativado");

	m_textApply = new Text(getFontNulshock(),getFontSize(1));
	m_textApply->setColor(255,255,0,255);
	m_textApply->addPosition(100,530);
	m_textApply->addText("Aplicar Configuracoes");
	m_textApply->addPosition(600,530);
	m_textApply->addText("Sair");
}

void
ConfigurationMenu::update()
{
	if(isCOpenedMenu())
	{
		falseCOpenMenu();
		setOver(true);
		setTimelineEvent(MAINMENU);
	}
	else
	{
		m_background->setCurrentIdleTime(0);
		m_background->draw();

		m_textTitle->setTextNumber(0);
		m_textTitle->setPositionNumber(0);
		m_textTitle->drawText();

		m_textIndex->setTextNumber(0);
		m_textIndex->setPositionNumber(0);
		m_textIndex->drawText();
		m_textIndex->setTextNumber(1);
		m_textIndex->setPositionNumber(1);
		m_textIndex->drawText();
		m_textIndex->setTextNumber(2);
		m_textIndex->setPositionNumber(2);
		m_textIndex->drawText();
		m_textIndex->setTextNumber(3);
		m_textIndex->setPositionNumber(3);
		m_textIndex->drawText();

		m_textIndex->setColor(255,255,0,255);
		m_textIndex->setTextNumber(4);
		m_textIndex->setPositionNumber(4);
		m_textIndex->drawText();
		m_textIndex->setTextNumber(5);
		m_textIndex->setPositionNumber(5);
		m_textIndex->drawText();

		m_textIndex->setColor(255,255,255,255);

		m_textOption->setTextNumber(0);
		m_textOption->setPositionNumber(0);
		m_textOption->drawText();
		m_textOption->setTextNumber(1);
		m_textOption->setPositionNumber(1);
		m_textOption->drawText();
		m_textOption->setTextNumber(2);
		m_textOption->setPositionNumber(2);
		m_textOption->drawText();
		m_textOption->setTextNumber(3);
		m_textOption->setPositionNumber(3);
		m_textOption->drawText();
		m_textOption->setTextNumber(4);
		m_textOption->setPositionNumber(4);
		m_textOption->drawText();
		m_textOption->setTextNumber(5);
		m_textOption->setPositionNumber(5);
		m_textOption->drawText();
		m_textOption->setTextNumber(6);
		m_textOption->setPositionNumber(6);
		m_textOption->drawText();

		m_textApply->setPositionNumber(0);
		m_textApply->setTextNumber(0);
		m_textApply->drawText();
		m_textApply->setPositionNumber(1);
		m_textApply->setTextNumber(1);
		m_textApply->drawText();
	}
}