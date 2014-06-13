#ifndef ENEMY_H
#define ENEMY_H

#include "behaviour.h"
#include "imagesprite.h"

using namespace behaviour;

class Enemy : public ImageSprite
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

	bool isOnLeftDirection();
	bool isOnRightDirection();

	int getItem();

protected:
	SDL_Rect m_target;

	bool m_hunter;
	bool m_hunt;

	bool m_flying;
	bool m_attacking;
	int m_patrolStep;

	int m_health;
	int m_item;

	int m_patrol;
	int m_speed;
	int m_taxRotation;
	int m_typeDamage;
	int m_direction;
	int m_typeDetection;
	int m_patrolRange[2];
};

#endif // ENEMY_H
