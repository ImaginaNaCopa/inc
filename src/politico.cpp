#include "politico.h"
#include <iostream>

using namespace std;

Politico::Politico(int item, bool side, int earlyPosition) : Enemy() 
{
	step("[Politico] Constructing.");
	imagePath.assign("res/images/s_politico.png");
	generatePosition(earlyPosition,(getPlatformH()-52),50,52);
	generateClips();
	generateBehaviour();
	m_side = side;
	m_item = item;
	m_state = MOVING;
	m_looking = BACKWARD;
	wasJustBorn = true;
	setClipNumber(0);

}

Politico::~Politico()
{
	step("[Politico] Destroying.");
}

void
Politico::generateBehaviour()
{
	step("[Politico] Generating Behaviour.");
	m_hunter = isPassive();
	m_flying = isTerrestrial();
	m_typeDamage = doPoisonDamageType();
	m_health = haveNormalHealth();
	m_patrol = dontPatrol();
	m_speed = haveSlowSpeed();
	m_taxRotation = haveZombieRotation();
	m_typeDetection = haveDumbDetection();
}

void 
Politico::generateClips()
{
	step("[Politico] Generating Sprite Clips.");

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
	addClip(110,165,50,54);
}

void 
Politico::update(SDL_Rect target)
{
	loop("[Politico] Updating.");
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
		m_state = STANDING;
	else
		m_state = ATTACKING;
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
			m_position.x = calculatePosition(1);
			
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
			m_position.x = calculatePosition(-1);

			if(m_clipNumber==15)
				setClipNumber(16);
			else if(m_clipNumber==16)
				setClipNumber(17);
			else if(m_clipNumber==17)
				m_damaging = false;
			else
				setClipNumber(15);			
		}
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}

void
Politico::moving()
{
	cout << "aqui" << endl;
	if(getCurrentIdleTime() == 3)
	{

		if(m_looking == FORWARD)
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
		else
		{
			if(m_clipNumber==11)
				setClipNumber(12);
			else if(m_clipNumber==12)
				setClipNumber(13);
			else if(m_clipNumber==13)
				setClipNumber(14);
			else
				setClipNumber(11);			
		}
		setCurrentIdleTime(0);
		m_position.x = calculatePosition(1);
	/*	
		if (wasJustBorn && m_side) //true for forward
		{
			m_position.x = calculatePosition(1);
			if (m_position.x >= (rand()%550))
			{
				//m_looking = FORWARD;
				wasJustBorn = false;
				m_state = STANDING;
			}
		}
		else if (wasJustBorn && !m_side)
		{
			m_position.x = calculatePosition(-1);
			if (m_position.x <= (rand()%550))
			{
				//m_looking = BACKWARD;
				wasJustBorn = false;
				m_state = STANDING;
			}
		}*/
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}
