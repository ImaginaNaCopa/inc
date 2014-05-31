#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "imagesprite.h"
#include "imageload.h"

class Enemy : public ImageSprite
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void update(Uint32 delta);

protected:
	int m_speed;
	int m_dx;
	int m_frame;
};

#endif // ENEMY_H
