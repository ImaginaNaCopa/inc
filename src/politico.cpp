#include "politico.h"
#include <iostream>

using namespace std;

Politico::Politico(int item, bool side, int earlyPosition) : Enemy() 
{
	//step("[Politico] Constructing.");
	imagePath.assign("res/images/s_politico.png");
	generatePosition(earlyPosition,(getPlatformH()-52),50,52);
	generateClips();
	generateBehaviour();
	m_side = side;
	m_item = item;
	m_state = ATTACKING;
	m_looking = FORWARD;
	wasJustBorn = true;
	passive = true;
	setClipNumber(0);

}

Politico::~Politico()
{
	//step("[Politico] Destroying.");
	setCurrentEffect(pDie);
	playEffect();
}

void
Politico::generateBehaviour()
{
	//step("[Politico] Generating Behaviour.");
	m_hunter = isHunter();
	m_flying = isTerrestrial();
	m_typeDamage = doSimpleDamageType();
	m_health = haveNormalHealth();
	m_patrol = dontPatrol();
	m_patrolRange[0] = (m_position.x - m_patrol);
	m_patrolRange[1] = (m_position.x + m_patrol);
	m_speed = haveSlowSpeed();
	m_taxRotation = haveZombieRotation();
	m_typeDetection = haveCommonDetection();
}

void 
Politico::generateClips()
{
	//step("[Politico] Generating Sprite Clips.");

	addClip(0,0,50,52);//0 foward
	addClip(50,0,50,53);
	addClip(100,0,51,53);
	addClip(151,0,50,54);

	addClip(0,55,50,52);//4 backward
	addClip(50,55,50,53);
	addClip(100,55,51,53);
	addClip(151,55,50,54);

	addClip(0,110,51,53);//8
	addClip(51,110,49,53);
	addClip(110,110,50,54);

	addClip(0,165,51,53);//11
	addClip(51,165,49,53);
	addClip(100,165,50,54);
}

void 
Politico::update(SDL_Rect target)
{
	//loop("[Politico] Updating.");
	updatePosition(target);

	switch (m_state)
	{
		case STANDING:
			standing();
		break;
		case ATTACKING:
			attacking();
		break;
		case MOVING:
			moving();
		break;
	}

	if(!m_hunt)
	{
		m_state = STANDING;
	}
	else if (m_damaging)
	{
		m_state = ATTACKING;
	}
	else
	{
		m_state = MOVING;
		if(isOnLeftDirection())
		{
			//condition("[Curupira] Moving Backward.");
			m_looking = BACKWARD;
		}
		else if(isOnRightDirection())
		{
			//condition("[Curupira] Moving Forward.");
			m_looking = FORWARD;
		}	
	}
}

void
Politico::standing()
{
	if(m_looking == FORWARD)
		setClipNumber(0);
	else
		setClipNumber(4);
}

void
Politico::attacking()
{
	if(getCurrentIdleTime() == 3)
	{
		if(m_looking == FORWARD)
		{
			if(m_clipNumber==8)
				setClipNumber(9);
			else if(m_clipNumber==9)
				setClipNumber(10);
			else if(m_clipNumber==10)
				m_damaging = false;
			else
				setClipNumber(8);
		}
		else
		{
			if(m_clipNumber==11)
				setClipNumber(12);
			else if(m_clipNumber==12)
				setClipNumber(13);
			else if(m_clipNumber==13)
				m_damaging = false;
			else
				setClipNumber(11);			
		}
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}

void
Politico::moving()
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
		
		
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}
