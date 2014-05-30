#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "imageload.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	void init();
	void draw();
	void release();
	
private:
	SDL_Texture* m_texture;
	SDL_Texture* m_texture2;
	SDL_Rect positionCurupira;
	SDL_Rect positionUrubu;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // ENEMY_H