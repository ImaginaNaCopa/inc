#include "../include/enemy.h"

Enemy::Enemy() : ImageEffect()
{
	m_hunt = false;
	m_attacking = false;
	m_direction = -1;
	m_tracking = false;
	m_damaging = false;
	m_health = 0;
	died = false;
}

Enemy::~Enemy()
{
	//step("[Enemy] Destroying.");
}

void
Enemy::update(SDL_Rect target) 
{
	return (void) target;
}

void
Enemy::updatePosition(SDL_Rect target)
{
	m_target = target;
	if(m_hunt)
		hunt();
	else if(m_hunter)
	{
		updateDetection();
	}
	if(((m_patrol == doNormalPatrol()) || (m_patrol == doExtensePatrol())) && !m_attacking)
	{
		updateDirection();
		m_position.x += calculatePosition(m_direction);
	}
	if (ifCollided(1,m_position,target) || ifCollided(2,m_position,target))
		m_hunt = true;
}

void
Enemy::hunt()
{
	if(m_flying)
	{
		if(!m_attacking)
		{
			defineCurrentIdleTime(1);
			if(m_position.y > getFlyingStandardHeight())
				m_position.y += calculatePosition(-1);
			else
			{
				m_position.y = getFlyingStandardHeight();
				if(getCurrentIdleTime() == m_idleFlying)
				{
					setCurrentIdleTime(0);
					m_attacking = true;
					m_tracking = false;
				}
				else
				{
					m_tracking = true;
					if((m_position.x+m_position.w+150 > m_target.x) && (m_position.x < m_target.x+m_target.w+150))
						setCurrentIdleTime(getCurrentIdleTime()+1);
					updateDirection();
				}
			}
		}
		else
		{
			if(getPlatformH()-55 >= m_position.y+m_position.h)
				m_position.y += round(2*calculatePosition(1));
			else
			{
				m_attacking = false;
			}
		}
	}
	else
		m_attacking = true;
	if(m_attacking)
	{
		if(m_target.x+m_target.w-10 <= m_position.x)
		{
			m_direction = -1;
			m_position.x += calculatePosition(m_direction);
		}
		else if(m_position.x+m_position.w <= m_target.x+10)
		{
			m_direction = 1;
			m_position.x += calculatePosition(m_direction);
		}
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
			if((ifCollided(0,rangeDetection,m_target)) || ((m_flying) && (ifCollided(0,getCameraRange(),m_position))))
				m_hunt = true;
		break;
	}
}

int
Enemy::calculatePosition(int direction)
{
	//loop("[Enemy] Updating Position in Horizontal axis.");
		return round(((m_speed*getDelta())/1000.0)*direction);
}

void
Enemy::updateDirection()
{
	//loop("[Enemy] Updating Direction in Horizontal axis.");
	if(m_flying && m_tracking)
	{
			if(m_target.x+150 <= m_position.x)
				m_direction = -1;
			else if(m_target.x-150 >= m_position.x+m_position.w)
				m_direction = 1;
	}
	else
	{
		if (m_position.x >= m_patrolRange[1])
			m_direction = -1;
		else if (m_position.x <= m_patrolRange[0])
			m_direction = 1;
	}
}

void
Enemy::setEnemyHealth(int damage)
{
	if (m_health > 0)
		m_health += damage;
	if (m_health == 0)
		died = true;
	if (m_health == -1){}
		//Do BOSS things here
}

int
Enemy::getEnemyHealth()
{
	return m_health;
}

bool
Enemy::isOnRightDirection()
{
	//loop("[Enemy] Verifying if is on Right Direction.");
	if(m_direction == 1)
		return true;
	return false;
}

bool
Enemy::isOnLeftDirection()
{
	//loop("[Enemy] Verifying if is on Left Direction.");
	if(m_direction == -1)
		return true;
	return false;
}

int
Enemy::getItem()
{
	return m_item;
}

void
Enemy::setDamaging(bool dmg)
{
	m_damaging = dmg;
}

bool
Enemy::isTheBoss()
{
	return m_isTheBoss;
}

int
Enemy::getBossHealth()
{
	return m_bossHealth;
}

void
Enemy::setBossHealth(int value)
{
	m_bossHealth += value;
}