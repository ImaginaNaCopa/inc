#ifndef HP_H
#define HP_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"

class Hp
{
public:
	Hp();
	~Hp();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // HP_H