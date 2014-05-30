#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "imagesprite.h"
#include "imageload.h"

class Enemy : public ImageSprite
{
public:
	Enemy(int x, int y);
	Enemy();
	virtual ~Enemy();

	virtual void update(Uint32 delta);


protected:
	int m_speed;
	int m_dx;
	int m_frame;
	SDL_Rect m_box;
	ImageSprite* m_sprite;

	ImageLoad* imageLoad;
};

#endif // ENEMY_H
