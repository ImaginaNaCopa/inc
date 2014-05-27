#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SDL2/SDL.h>
#include "imageload.h"


class Dialogue
{
public:
	Dialogue();
	~Dialogue();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;

};

#endif // DIALOGUE_H