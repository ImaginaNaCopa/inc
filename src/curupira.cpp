#include "../include/curupira.h"


Curupira::Curupira(int item, int earlyPosition) : Enemy() 
{
	//step("[Curupira] Constructing.");
	imagePath.assign("res/images/s_curupira.png");
	generatePosition(earlyPosition,(getPlatformH()-15),50,15);
	generateClips();
	generateBehaviour();
	m_item = item;
	m_rose = false;
	m_state = UNDERGROUND;
	m_looking = BACKWARD;
	setClipNumber(18);
}

Curupira::~Curupira()
{
	//step("[Curupira] Destroying.");
	if(m_position.x % 23 == 0)
		setCurrentEffect(eDerp1);
	else if(m_position.x % 19 == 0)
		setCurrentEffect(eDerp2);
	else if(m_position.x % 17 == 0)
		setCurrentEffect(eDerp3);
	else if(m_position.x % 13 == 0)
		setCurrentEffect(eDerp4);
	else if(m_position.x % 11 == 0)
		setCurrentEffect(eDerp5);
	else if(m_position.x % 9 == 0)
		setCurrentEffect(eDerp6);
	else
		setCurrentEffect(eDerp7);
	playEffect();
}

void
Curupira::generateBehaviour()
{
	//step("[Curupira] Generating Behaviour.");
	m_hunter = isHunter();
	m_flying = isTerrestrial();
	m_typeDamage = doSimpleDamageType();
	m_health = haveWeakHealth();
	m_patrol = dontPatrol();
	m_patrolRange[0] = (m_position.x - m_patrol);
	m_patrolRange[1] = (m_position.x + m_patrol);
	m_speed = haveNormalSpeed();
	m_taxRotation = haveZombieRotation();
	m_typeDetection = haveCommonDetection();
}

void 
Curupira::generateClips()
{
	//step("[Curupira] Generating Sprite Clips.");

	addClip(0,0,56,15);
	addClip(0,0,56,30);
	addClip(0,0,56,45);
	addClip(0,0,56,60);

	addClip(56,0,50,63);
	addClip(106,0,50,65);
	addClip(156,0,50,65);
	addClip(206,0,50,65);

	addClip(0,80,56,65);
	addClip(56,80,54,65);
	addClip(110,80,60,63);

	addClip(0,160,50,63);
	addClip(50,160,50,65);
	addClip(100,160,50,65);
	addClip(150,160,50,65);

	addClip(0,240,56,65);
	addClip(56,240,54,65);
	addClip(110,240,60,63);
	
	addClip(5,5,1,1);//18
}

void 
Curupira::update(SDL_Rect target)
{
	//loop("[Curupira] Updating.");
	updatePosition(target);

	switch (m_state)
	{
		case UNDERGROUND:
			underground();
		break;
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

	if(!m_hunt || !m_rose)
	{
		m_state = UNDERGROUND;
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
Curupira::underground()
{
	if (m_attacking)
	{
		if(getCurrentIdleTime() == 3)
		{
			if(m_clipNumber==0)
				setClipNumber(1);
			else if(m_clipNumber==1)
				setClipNumber(2);
			else if(m_clipNumber==2)
				setClipNumber(3);
			else if (m_clipNumber==3)
				m_rose = true;
			else
				setClipNumber(0);

			setCurrentIdleTime(0);
		}
		else
			setCurrentIdleTime(getCurrentIdleTime()+1);
	}
}

void
Curupira::standing()
{
	if(m_looking == FORWARD)
		setClipNumber(1);
	else
		setClipNumber(8);
}

void
Curupira::attacking()
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
Curupira::moving()
{
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
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);

}
