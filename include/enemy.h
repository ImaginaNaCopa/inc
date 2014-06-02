#ifndef ENEMY_H
#define ENEMY_H

#include "imagesprite.h"
#include "behaviour.h"

using namespace behaviour;

class Enemy : public ImageSprite
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void update();
	void updatePositionX();
	void updateDirectionX();
	bool isOnRightDirection();
	bool isOnLeftDirection();

protected:
	bool m_hunter;
	bool m_flying;

	int m_health;
	int m_patrol;
	int m_speed;
	int m_taxRotation;
	int m_typeDamage;
	int m_typeDetection;
	int m_direction[2];
	int m_patrolRange[2];
};

#endif // ENEMY_H
