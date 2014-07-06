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
	addClip(0,280,403,403);
	addClip(0,690,235,270);

	background->addClip(252,702,34,24);
	background->addClip(302,702,34,24);
	background->addClip(352,702,34,24);
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
				generatePosition(200,100,403,403);
				background->setClipNumber(1);
			break;
			case 2:
				loop("[FrontEnd] Generating Other Logos.");
				generatePosition(282,165,235,270);
				background->setClipNumber(2);			
			break;
			case 3:
				step("[FrontEnd] Reseting and its over...");
				m_clipNumber = 0;
				background->setClipNumber(0);
				setOver(true);
			break;

			default:
				loop("[FrontEnd] Generating Default Values.");
				m_clipNumber = 0;
				background->setClipNumber(0);
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