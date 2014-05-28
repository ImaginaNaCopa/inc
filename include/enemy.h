#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "imagesprite.h"
#include "imageload.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	void init();
	void draw();
	void update(Uint32 delta);
	void release();
	
private:
	SDL_Texture* m_texture;
	SDL_Texture* m_texture2;
	SDL_Rect positionCurupira[2];
	SDL_Rect positionUrubu[3];
	ImageLoad* imageLoad;
	ImageSprite* m_imageSpriteUrubu;
	ImageSprite* m_imageSpriteCurupira;

	SDL_Rect m_clips[8];
	int uC[2];
	int dxC[2];
	int dxU[3];
	int speedC;
	int speedU;
};

#endif // ENEMY_H