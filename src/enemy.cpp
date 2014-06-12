#include "enemy.h"

Enemy::Enemy() : ImageSprite()
{
	m_hunt = false;
	m_attacking = false;
	m_patrolStep = 0;
	m_direction = -1;
}

Enemy::~Enemy() {}

void
Enemy::update(SDL_Rect target) {}

void
Enemy::updatePosition(SDL_Rect target)
{
	m_target = target;
	if(m_hunt)
		hunt();
	else if(m_hunter)
	{
		updateDetection();
		if((m_patrol == doNormalPatrol()) || (m_patrol == doExtensePatrol()))
		{
			updateDirection();
		}		
	}
}

void
Enemy::hunt()
{
	if(m_flying)
	{
			if(!m_attacking)
			{
				if(m_position.y > getFlyingStandardHeight())
					m_position.y -= calculatePosition();
				else
				{
					m_position.y = getFlyingStandardHeight();
					if(m_patrolStep<30)
						m_patrolStep++;
					else
					{
						m_patrolStep = 0;
						m_attacking = true;
					}

					/*updateDirection();
					if(m_patrolStep==0)
						m_attacking = true;*/				
				}
			}
			else
			{
				if(m_target.y+m_target.h >= m_position.y)
					m_position.y += calculatePosition();
				else
				{
					m_attacking = false;
				}
			}
	}
	if(m_target.x <= m_position.x)
	{
		m_position.x -= calculatePosition();
		m_direction = -1;
	}
	else
	{
		m_position.x += calculatePosition();
		m_direction = 1;
	}
}

void
Enemy::updateDetection()
{
	switch(m_typeDetection)
	{
		case 0:
			if(ifCollided(0,m_position, m_target))
			{
				m_hunt = true;
			}
		break;

		case 1:
			m_hunt = true;
		break;

		case 400:
			SDL_Rect rangeDetection =
			{	m_position.x-((m_typeDetection)/2),
				m_position.y-((m_typeDetection)/2),
				m_position.w+m_typeDetection,
				m_position.h+m_typeDetection	};
			if((ifCollided(0,rangeDetection,m_target)))
			{
				m_hunt = true;
			}
		break;
	}
}

int
Enemy::calculatePosition()
{
	loop("[Enemy] Updating Position in Horizontal axis.");
		return round((m_speed*getDelta())/1000.0);
}

void
Enemy::updateDirection()
{
	loop("[Enemy] Updating Direction in Horizontal axis.");
	if (m_position.x >= m_patrolRange[1])
	{
		m_position.x -= calculatePosition();
		m_direction = -1;
		m_patrolStep++;
	}
	else if (m_position.x <= m_patrolRange[0])
	{
		m_position.x += calculatePosition();
		m_direction = 1;
		m_patrolStep--;
	}
}

bool
Enemy::isOnRightDirection()
{
	loop("[Enemy] Verifying if is on Right Direction.");
	if(m_direction == 1)
		return true;
	return false;
}

bool
Enemy::isOnLeftDirection()
{
	loop("[Enemy] Verifying if is on Left Direction.");
	if(m_direction == -1)
		return true;
	return false;
}

int
Enemy::getItem()
{
	return m_item;
}