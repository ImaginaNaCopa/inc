#include "../include/urubu.h"

Urubu::Urubu(int item, int earlyPosition) : Enemy() 
{
	//step("[Urubu] Constructing.");
  imagePath.assign("res/images/s_urubu.png");
	generatePosition(earlyPosition,getFlyingStandardHeight(),87,57);
  generateClips();
	generateBehaviour();
	m_item = item;
  
	srand(earlyPosition);
	m_idleFlying = (int) rand() % 100;
}

Urubu::~Urubu()
{
	setCurrentEffect(uDie);
	playEffect();
	tickRand();
}

void
Urubu::generateBehaviour()
{
	//step("[Urubu] Generating Behaviour.");
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
	//step("[Urubu] Generating Sprite Clips.");
	addClip(0,0,87,57);
	addClip(90,0,91,51);
	addClip(185,0,83,54);

	addClip(0,60,59,59);
	addClip(60,60,87,56);

	addClip(0,120,87,57);
	addClip(90,120,91,51);
	addClip(185,120,83,54);

	addClip(0,180,59,59);
	addClip(60,180,87,56);
}

void 
Urubu::update(SDL_Rect target)
{
	//loop("[Urubu] Updating.");
	updatePosition(target);
	defineCurrentIdleTime(2);

	if(getCurrentIdleTime() == 4)
	{
		if(isOnLeftDirection())
		{
			if(m_attacking)
			{
				setClipNumber(8);
			}
			else
			{
				//condition("[Curupira] Moving Backward.");
				if(m_clipNumber==5)
					setClipNumber(6);
				else if (m_clipNumber==6)
					setClipNumber(7);
				else
					setClipNumber(5);				
			}
		}
		else if(isOnRightDirection())
		{
			if(m_attacking)
			{
				setClipNumber(3);
			}
			else
			{
				//condition("[Curupira] Moving Forward.");
				if(m_clipNumber==0)
					setClipNumber(1);
				else if (m_clipNumber==1)
					setClipNumber(2);
				else
					setClipNumber(0);
			}
		}
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}
