#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "imageload.h"
#include <SDL2/SDL.h>

class Background 
{
public:
	Background();
	~Background();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // BACKGROUND_H