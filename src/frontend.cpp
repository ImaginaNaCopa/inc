#include "frontend.h"

FrontEnd::FrontEnd() : ImageEffect()
{
	background = new Background("res/images/s_frontend.png");	
	imagePath.assign("res/images/s_frontend.png");
	m_alpha = 0;
	m_fading = true;
	m_fadingin = true;
	generatePosition(225,165,350,270);	
	generateClips();
	background->init();	
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

	background->addClip(420,310,10,10);
	background->addClip(460,310,10,10);
	background->addClip(500,310,10,10);
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
				background->m_clipNumber = 1;
			break;
			case 2:
				generatePosition(163,165,475,270);
				background->m_clipNumber = 2;				
			break;
			case 3:
				m_clipNumber = 0;
				background->m_clipNumber = 0;
				setOver(true);
			break;

			default:
				m_clipNumber = 0;
				background->m_clipNumber = 0;
				generatePosition(225,165,350,270);
			break;			
		}
	}
	if(!isOver())
	{
		background->draw();
		draw();
	}
}