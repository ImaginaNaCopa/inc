#ifndef INVENTORY_H
#define INVENTORY_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"


class Inventory : public ImageSprite
{
public:
	Inventory();
	~Inventory();

	void drawEach();
	void generateClips();

private:
	bool isDrawn;
};

#endif // INVENTORY_H