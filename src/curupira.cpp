#include "curupira.h"

Curupira::Curupira(int item, int earlyPosition) : Enemy() 
{
	step("[Curupira] Constructing.");
	imagePath.assign("res/images/s_curupira.png");
	generatePosition(earlyPosition,(getPlatformH()-100),50,100);
	generateClips();
	generateBehaviour();
	m_item = item;
}

Curupira::~Curupira()
{
	step("[Curupira] Destroying.");
	release();
}

void
Curupira::generateBehaviour()
{
	step("[Curupira] Generating Behaviour.");
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
	step("[Curupira] Generating Sprite Clips.");
	addClip(0,0,m_position.w,m_position.h);
	addClip(m_position.w,0,m_position.w,m_position.h);
	addClip(m_position.w*2,0,m_position.w,m_position.h);
	addClip(m_position.w*3,0,m_position.w,m_position.h);

	addClip(0,m_position.h,m_position.w,m_position.h);
	addClip(m_position.w,m_position.h,m_position.w,m_position.h);
	addClip(m_position.w*2,m_position.h,m_position.w,m_position.h);
	addClip(m_position.w*3,m_position.h,m_position.w,m_position.h);
}

void 
Curupira::update(SDL_Rect target)
{
	loop("[Curupira] Updating.");
	updatePosition(target);

	if(isOnLeftDirection())
	{
		condition("[Curupira] Moving Backward.");
		if (m_position.x % 8 == 0)
			m_clipNumber = 0;
		if (m_position.x % 8 == 1)
			m_clipNumber = 1;
		if (m_position.x % 8 == 2)
			m_clipNumber = 2;
		if (m_position.x % 8 == 3)
			m_clipNumber = 3;
	}
	else if(isOnRightDirection())
	{
		condition("[Curupira] Moving Forward.");
		if (m_position.x % 8 == 4)
			m_clipNumber = 4;
		if (m_position.x % 8 == 5)
			m_clipNumber = 5;
		if (m_position.x % 8 == 6)
			m_clipNumber = 6;
		if (m_position.x % 8 == 7)
			m_clipNumber = 7;	
	}
}
