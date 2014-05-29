#ifndef SECONDLAYER_H
#define SECONDLAYER_H

#include <SDL2/SDL.h>
#include "imageload.h"

class SecondLayer 
{
public:
	SecondLayer();
	~SecondLayer();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // SECONDLAYER_H