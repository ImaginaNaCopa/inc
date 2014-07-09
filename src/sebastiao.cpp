#include "sebastiao.h"

Sebastiao::Sebastiao() : ImageEffect()
{
	step("[Sebastiao] Constructing.");
	imagePath.assign("res/images/s_sebastiao.png");
	generatePosition(600,60,98,38);

	m_level = ONE;
	m_shoot = false;

	m_background = new Background("res/images/s_sebastiao.png");
	m_background->init();
	m_background->generatePosition(600,10,160,90);
	m_platform = new Background("res/images/s_sebastiao.png");
	m_platform->init();
	m_platform->generatePosition(600,10,160,90);
	m_border = new Background("res/images/s_hud.png");
	m_border->init();
	m_border->generatePosition(595,10,160,90);


	generateClips();
	newIdleTime();
}

Sebastiao::~Sebastiao()
{
	step("[Sebastiao] Destroying.");
	delete m_background;
	delete m_border;
	delete m_platform;
}

void
Sebastiao::generateClips()
{
	step("[Sebastiao] Generating Sprite Clips.");
	m_background->addClip(0,0,5,5);
	m_platform->addClip(0,0,5,5);
	m_border->addClip(460,0,200,90);

	addClip(0,0,98,38);
	addClip(100,0,103,38);

	addClip(0,40,98,38);
	addClip(100,40,103,38);

	addClip(0,80,55,38);
	addClip(55,80,55,38);
	
	addClip(110,80,55,38);
}

void
Sebastiao::update()
{
	if(m_shoot)
		setClipNumber(1);
	else
		setClipNumber(0);
	switch(m_level)
	{
		case ONE:
		break;

		case TWO:
		break;

		case THREE:
		break;

		case FOUR:
			if(m_shoot)
				setClipNumber(2);
			else
				setClipNumber(3);
		break;

		case FIVE:
		break;

		default:
		break;
	}
	m_border->draw();
	m_background->draw();
	m_platform->draw();
	draw();
	defineCurrentIdleTime(1);
	if(getCurrentIdleTime() == 5)
	{
		setCurrentIdleTime(0);
		m_shoot = false;
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}

void
Sebastiao::setLevel(int level)
{
	if(level==1)
		m_level = ONE;
	else if(level==2)
		m_level = TWO;
	else if(level==3)
		m_level = THREE;
	else if(level==4)
		m_level = FOUR;
	else if(level==5)
		m_level = FIVE;
}

void
Sebastiao::setShoot(bool shoot)
{
	m_shoot = shoot;
}