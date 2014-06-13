#include "urubu.h"

Urubu::Urubu(int item, int earlyPosition) : Enemy() 
{
	step("[Urubu] Constructing.");
  imagePath.assign("res/images/s_urubu.png");
	generatePosition(earlyPosition,getFlyingStandardHeight(),51,36);
  generateClips();
	generateBehaviour();
	m_item = item;
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
}

void 
Urubu::generateClips()
{
	step("[Urubu] Generating Sprite Clips.");
	addClip(0,0,m_position.w,m_position.h);
	m_clipNumber = 0;
}

void 
Urubu::update(SDL_Rect target)
{
	loop("[Urubu] Updating.");
	updatePosition(target);
}
