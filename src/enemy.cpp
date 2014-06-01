#include "enemy.h"

Enemy::Enemy() : ImageSprite() {}

Enemy::~Enemy() {}

void
Enemy::update() {}

void
Enemy::updatePositionX()
{
	loop("[Enemy] Updating Position in Horizontal axis.");
	m_position.x += round(((m_speed*getDelta())/1000.0)*m_direction[0]);
}

void
Enemy::updateDirectionX()
{
	loop("[Enemy] Updating Direction in Horizontal axis.");
	if (m_position.x >= m_patrolRange[1])
		m_direction[0] = -1;
	else if (m_position.x <= m_patrolRange[0])
		m_direction[0] = 1;
}

bool
Enemy::isOnRightDirection()
{
	loop("[Enemy] Verifying if is on Right Direction.");
	if(m_direction[0] == 1)
		return true;
	return false;
}

bool
Enemy::isOnLeftDirection()
{
	loop("[Enemy] Verifying if is on Left Direction.");
	if(m_direction[0] == -1)
		return true;
	return false;
}