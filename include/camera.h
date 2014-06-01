#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include "systemlogger.h"

using namespace systemLogger;

namespace camera
{
	void updateCamera(SDL_Rect target, int levelWidth);
	
	SDL_Rect getCameraRange();
	int getCameraLeftPosition();
	int getCameraRightPosition();
}

#endif // CAMERA_H