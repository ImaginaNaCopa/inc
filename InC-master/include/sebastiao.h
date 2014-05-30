#ifndef SEBASTIAO_H
#define SEBASTIAO_H

#include <SDL2/SDL.h>
#include "imageload.h"


class Sebastiao
{
public:
	Sebastiao();
	~Sebastiao();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
	

};

#endif // SEBASTIAO_H