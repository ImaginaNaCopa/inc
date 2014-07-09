#include "gigante.h"
#include <iostream>

using namespace std;

Gigante::Gigante(int earlyPosition) : Enemy() 
{
	step("[Gigante] Constructing.");
	imagePath.assign("res/images/s_gigante.png");
	generatePosition(earlyPosition,(getPlatformH()-248),240,248);
	generateClips();
	m_state = STANDING;
	m_looking = BACKWARD;
	setClipNumber(0);
	m_isTheBoss = true;
	m_hunter = isPassive();

	m_health = haveEventHealth();

	m_stopWalking = false;
	m_bossHealth = 3;
}

Gigante::~Gigante()
{
	step("[Gigante] Destroying.");
}


void 
Gigante::generateClips()
{
	step("[Gigante] Generating Sprite Clips.");

	addClip(0,0,240,248);//0 foward
	addClip(240,0,240,256);
	addClip(480,0,240,256);
	addClip(720,0,240,256);

	addClip(0,260,240,248);//4 backward
	addClip(240,260,240,256);
	addClip(480,260,240,256);
	addClip(720,260,240,256);
}

void 
Gigante::update(SDL_Rect target)
{
	loop("[Gigante] Updating.");
	updatePosition(target);

	switch (m_state)
	{
		case STANDING:
			standing();
		break;
	
		case MOVING:
			moving();
		break;
	}

	if (m_stopWalking)
	{
		
		if(isOnLeftDirection())
		{
			condition("[Curupira] Moving Backward.");
			m_looking = BACKWARD;
		}
		else if(isOnRightDirection())
		{
			condition("[Curupira] Moving Forward.");
			m_looking = FORWARD;
		}	
	}
}

void
Gigante::standing()
{
	if(getCurrentIdleTime() == 3)
	{
		if(m_looking == FORWARD)
			setClipNumber(0);
		else
			setClipNumber(4);
	
		setCurrentIdleTime(0);
		//m_state = MOVING;
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}

void
Gigante::moving()
{
	if(getCurrentIdleTime() == 3)
	{
		
		if(m_looking == FORWARD)
		{
			if(m_clipNumber==0)
				setClipNumber(1);
			else if(m_clipNumber==1)
				setClipNumber(2);
			else if(m_clipNumber==2)
				setClipNumber(3);

			else
				setClipNumber(0);
		}
		else
		{
			if(m_clipNumber==4)
				setClipNumber(5);
			else if(m_clipNumber==5)
				setClipNumber(6);
			else if(m_clipNumber==6)
				setClipNumber(7);
			else
				setClipNumber(4);			
		}
		setCurrentIdleTime(0);
		m_state = STANDING;
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}
