#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"

class Platform : public ImageSprite
{
public:
	Platform();
	~Platform();

	void generateClips();
private:
	bool isDrawn;
};

#endif // PLATFORM_H