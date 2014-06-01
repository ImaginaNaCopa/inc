#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>
#include "systemlogger.h"

using namespace systemLogger;

namespace collision
{
	bool ifCollided(int type, SDL_Rect positionSource, SDL_Rect positionTarget);
}

#endif // COLLISION_H