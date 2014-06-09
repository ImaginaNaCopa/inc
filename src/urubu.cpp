#include "urubu.h"

Urubu::Urubu(int earlyPosition) : Enemy() 
{
	step("[Urubu] Constructing.");
    imagePath.assign("res/images/s_urubu.png");
	generatePosition(earlyPosition,(getPlatformH()-300),51,36);
    generateClips();
	generateBehaviour();
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
	m_direction[0] = 1;
	m_direction[1] = 0;
	m_speed = haveNormalSpeed();
	m_taxRotation = haveZombieRotation();
	m_typeDetection = haveCommonDetection();
}

void 
Urubu::generateClips()
{
	step("[Urubu] Generating Sprite Clips.");
	addClip(0,0,m_position.w,m_position.h);
}

void 
Urubu::update()
{
	loop("[Urubu] Updating.");
	updatePositionX();
	updateDirectionX();

	m_clipNumber = 0;
}