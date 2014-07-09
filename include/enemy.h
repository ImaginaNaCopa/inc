#ifndef ENEMY_H
#define ENEMY_H

#include <time.h>
#include "behaviour.h"
#include "imageeffect.h"

using namespace behaviour;

class Enemy : public ImageEffect
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void update(SDL_Rect target);

	void updatePosition(SDL_Rect target);
	void hunt();
	void updateDetection();
	void updateDirection();

	int calculatePosition(int direction);
	void setEnemyHealth(int damage);
	int getEnemyHealth();

	bool isOnLeftDirection();
	bool isOnRightDirection();

	void setDamaging(bool dmg);
	int getItem();

protected:
	SDL_Rect m_target;

	bool m_hunter;
	bool m_hunt;

	bool m_damaging;

	bool m_flying;
	bool m_attacking;
	bool m_tracking;
	
	int m_idleFlying;

	int m_health;
	int m_item;

	int m_patrol;
	int m_speed;
	int m_taxRotation;
	int m_typeDamage;
	int m_direction;
	int m_typeDetection;
	int m_patrolRange[2];

	bool died;

};

#endif // ENEMY_H
