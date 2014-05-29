#ifndef SEBASTIAO_H
#define SEBASTIAO_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"


class Sebastiao : public ImageSprite
{
public:
	Sebastiao();
	~Sebastiao();

	void generateClips();

private:
	bool isDrawn;
};

#endif // SEBASTIAO_H