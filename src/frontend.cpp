#include "frontend.h"

FrontEnd::FrontEnd() : ImageEffect()
{
	m_alpha = 0;
	m_over = false;
	m_fading = true;
	m_fadingin = true;
	imagePath.assign("res/images/s_frontend.png");
	generatePosition(225,165,350,270);	
	generateClips();
}

FrontEnd::~FrontEnd()
{
	release();
}

void
FrontEnd::generateClips()
{
	addClip(0,0,350,270);
	addClip(0,280,400,400);
	addClip(360,0,475,270);

	addClip(410,300,40,30);
	addClip(450,300,40,30);
	addClip(490,300,40,30);
}

void
FrontEnd::update()
{
	int before = m_clipNumber;
	fade();
	if(before != m_clipNumber)
	{
		switch(m_clipNumber)
		{
			case 1:
				generatePosition(200,100,400,400);
			break;
			case 2:
				generatePosition(163,165,475,270);
			break;
			case 3:
				m_clipNumber = 0;
				setOver(true);
			break;

			default:
				m_clipNumber = 0;
				generatePosition(225,165,350,270);
			break;			
		}
	}
}

bool
FrontEnd::isOver()
{
	return m_over;
}

void
FrontEnd::setOver(bool overState)
{
	m_over = overState;
}