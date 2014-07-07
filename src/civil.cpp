#include "civil.h"

Civil::Civil(int item, int earlyPosition) : ImageEffect()
{
	step("[Civil] Constructing.");
	imagePath.assign("res/images/s_curupira.png"); //por enquanto fica esse
	generatePosition(earlyPosition,(getPlatformH()-50),25,50);
	addClip(0,0,50,100);

	m_item = item;
	m_safe = false;
	m_runned = false;
}

Civil::~Civil()
{
	step("[Civil] Destroying.");
	release();
}

void
Civil::generateClips(){}

void
Civil::updatePosition()
{
	loop("[Civil] Updating Position.");
	if (isSafe())
		m_position.x += calculatePosition(-1);

	if(m_position.x < 0)
		m_runned = true;
}

int
Civil::calculatePosition(int direction)
{
	loop("[Civil] Updating Position in Horizontal axis.");
	return round(((100*getDelta())/1000.0)*direction);
}

void
Civil::update()
{
	updatePosition();
}

int
Civil::getItem()
{
	return m_item;
}

bool
Civil::isSafe()
{
	return m_safe;
}

void
Civil::saved()
{
	m_safe = true;
}

bool
Civil::isRunned()
{
	return m_runned;
}