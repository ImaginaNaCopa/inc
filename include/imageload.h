#ifndef IMAGELOAD_H
#define IMAGELOAD_H

#include <SDL2/SDL_image.h>
#include "../include/systemlogger.h"

using namespace systemLogger;

namespace imageLoad
{
	void setRenderer(SDL_Renderer* renderer);
	void freeRenderer();

	SDL_Texture* loadImage(const string& path);
	void imageDraw(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect);
	void render();
	SDL_Texture* surfaceToTexture(SDL_Surface* targetSurface);
}

#endif // IMAGELOAD_H