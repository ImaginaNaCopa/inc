#include "urubu.h"

Urubu::Urubu(int item, int earlyPosition) : Enemy() 
{
	step("[Urubu] Constructing.");
  imagePath.assign("res/images/s_urubu.png");
	generatePosition(earlyPosition,getFlyingStandardHeight(),87,57);
  generateClips();
	generateBehaviour();
	m_item = item;
  
	srand(earlyPosition);
	m_idleFlying = (rand() % 40) + 50;
}

Urubu::~Urubu()
{
	step("[Urubu] Destroying.");
	release();
}

void
Urubu::generateBehaviour()
{
	step("[Urubu] Generating Behaviour.");
	m_hunter = isHunter();
	m_flying = isFlying();
	m_typeDamage = doSimpleDamageType();
	m_health = haveWeakHealth();
	m_patrol = doNormalPatrol();
	m_patrolRange[0] = (m_position.x - m_patrol);
	m_patrolRange[1] = (m_position.x + m_patrol);
	m_speed = haveQuicklySpeed();
	m_taxRotation = haveZombieRotation();
	m_typeDetection = haveCommonDetection();
	newVariousIdleTimes(2);
}

void 
Urubu::generateClips()
{
	step("[Urubu] Generating Sprite Clips.");
	addClip(0,0,87,57);
	addClip(90,0,91,51);
	addClip(185,0,83,54);

	addClip(0,60,59,59);
	addClip(60,60,87,56);
}

void 
Urubu::update(SDL_Rect target)
{
	defineCurrentIdleTime(2);
	loop("[Urubu] Updating.");
	updatePosition(target);

	if(getCurrentIdleTime() == 4)
	{
		if(isOnLeftDirection())
		{
			if(m_attacking)
			{
				setClipNumber(3);
			}
			else
			{
				condition("[Curupira] Moving Backward.");
				if(m_clipNumber==0)
					setClipNumber(1);
				else if (m_clipNumber==1)
					setClipNumber(2);
				else
					setClipNumber(0);				
			}
		}
		else if(isOnRightDirection())
		{
			condition("[Curupira] Moving Forward.");
			if(m_clipNumber==0)
				setClipNumber(1);
			else if (m_clipNumber==1)
				setClipNumber(2);
			else
				setClipNumber(0);
		}
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}
