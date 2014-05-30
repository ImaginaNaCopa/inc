#ifndef INVENTORY_H
#define INVENTORY_H

#include <SDL2/SDL.h>
#include "imageload.h"


class Inventory
{
public:
	Inventory();
	~Inventory();
	void init();
	void draw();
	void release();
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // INVENTORY_H