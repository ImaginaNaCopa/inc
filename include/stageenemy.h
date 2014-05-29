#ifndef STAGEENEMY_H
#define STAGEENEMY_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"

class StageEnemy
{
public:
	StageEnemy();
	~StageEnemy();
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