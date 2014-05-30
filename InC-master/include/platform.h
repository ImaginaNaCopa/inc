#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include "imageload.h"

class Platform 
{
public:
	Platform();
	~Platform();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // PLATFORM_H