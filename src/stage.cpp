#include "stage.h"
#include <iostream>

using namespace std;

Stage::Stage() : Scenario(), Hud(), Entity()
{}

Stage::~Stage()
{
	delete m_text;
}

void 
Stage::init()
{
	m_text = new Text(getFontTulpenOne(),getFontSize(8));
	m_text->addPosition(getWindowW()/2-120, getWindowH()/2-60);
	m_text->addText("Caio morreu!");
	m_text->setColor(0, 0, 0, 255);
	m_text->setTextNumber(0);
	m_text->setPositionNumber(0);
	
	step("[Stage] Initiating Each Stage Object.");
	initScenario();
	initHud();
	initEntity();
}

void
Stage::draw()
{
	loop("[Stage] Drawing Each Stage Object.");
	
	if (caio->getHealth() == 0)
	{
		m_text->drawText();
	}
	else
	{
		drawScenarioStaticImages();
		drawScenarioRelativeImages();
		drawHud();
		drawEntity();
	}
}

void 
Stage::update()
{
	loop("[Stage] Updating Each Stage Object.");
	if (caio->getHealth() != 0)
	{
		updateEntity();
		controlEntityEvents();
	}
	else
	{
		SDL_Delay(1500);
		setOver(true);
		setFinished(false);
		setGameOver(true);
	}
	if(caio->getPosition().x >= 1500)
	{
		setOver(true);
		setFinished(true);
		removeHandler(caio);
		removeHandler(aim);
	}
}

void
Stage::setGameOver(bool over)
{
	m_gameOver = over;
}

bool
Stage::gameOver()
{
	cout << "returning game over" << endl;
	return m_gameOver;
}

void 
Stage::setFinished(bool finished)
{
	m_finished = finished;
}

bool
Stage::isFinished()
{
	cout << "is done" << endl;
	return m_finished;
}