#include "frontend.h"

FrontEnd::FrontEnd() : ImageEffect()
{
	step("[FrontEnd] Constructing.");
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
	step("[FrontEnd] Destroying.");
	release();
	delete background;
}

void
FrontEnd::generateClips()
{
	step("[FrontEnd] Generating Sprite Clips.");
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
	loop("[FrontEnd] Updating and Drawing.");
	int before = m_clipNumber;
	fade();
	if(before != m_clipNumber)
	{
		loop("[FrontEnd] If using a new Clip.");
		switch(m_clipNumber)
		{
			case 1:
				loop("[FrontEnd] Generating Rating.");
				generatePosition(200,100,400,400);
				background->m_clipNumber = 1;
			break;
			case 2:
				loop("[FrontEnd] Generating Other Logos.");
				generatePosition(163,165,475,270);
				background->m_clipNumber = 2;				
			break;
			case 3:
				step("[FrontEnd] Reseting and its over...");
				m_clipNumber = 0;
				background->m_clipNumber = 0;
				setOver(true);
			break;

			default:
				loop("[FrontEnd] Generating Default Values.");
				m_clipNumber = 0;
				background->m_clipNumber = 0;
				generatePosition(225,165,350,270);
			break;			
		}
	}
	if(!isOver())
	{
		loop("[FrontEnd] Drawing if is not Over.");
		background->draw();
		draw();
	}
}