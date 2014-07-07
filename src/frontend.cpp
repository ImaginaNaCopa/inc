#include "frontend.h"

FrontEnd::FrontEnd() : ImageEffect()
{
	step("[FrontEnd] Constructing.");
	background = new Background("res/images/s_frontend.png");	
	imagePath.assign("res/images/s_frontend.png");
	m_alpha = 0;
	m_fading = true;
	m_fadingin = true;
	m_use = false;
	m_skip = false;
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
	newFade();
}

void
FrontEnd::update()
{
	if(isCOpenedMenu())
	{
		if(!m_use)
		{
			m_use = true;
			m_skip = true;
		}
	}
	else
		m_use = false;

	loop("[FrontEnd] Updating and Drawing.");
	fade(15,60);
		loop("[FrontEnd] If using a new Clip.");
	switch(m_clipNumber)
	{
		case 1:
			loop("[FrontEnd] Generating Rating.");
			generatePosition(200,100,403,403);
			background->setOnlyClipNumber(1);
			if(isFadeEnded() || m_skip)
			{
				generatePosition(282,165,235,270);
				background->setOnlyClipNumber(2);
				setOnlyClipNumber(2);
				newFade();
			}
		break;
		case 2:
			loop("[FrontEnd] Generating Other Logos.");
			generatePosition(282,165,235,270);
			background->setOnlyClipNumber(2);			
			if(isFadeEnded() || m_skip)
			{
				step("[FrontEnd] And its over...");
				setOver(true);
				setTimelineEvent(MAINMENU);
			}
		break;

		default:
			loop("[FrontEnd] Generating Default Values.");
			generatePosition(225,165,350,270);
			background->setOnlyClipNumber(0);
			if(isFadeEnded() || m_skip)
			{
				generatePosition(200,100,403,403);
				background->setOnlyClipNumber(1);
				setOnlyClipNumber(1);
				newFade();
			}
		break;			
	}

	loop("[FrontEnd] Drawing if is not Over.");
	background->draw();
	draw();
}