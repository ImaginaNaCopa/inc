#ifndef IMAGELOAD_H
#define IMAGELOAD_H

#include <SDL2/SDL_image.h>
#include "systemlogger.h"

using namespace systemLogger;

class ImageLoad
{
public:
	static ImageLoad* getInstance();
	static void releaseInstance();

	void setRenderer(SDL_Renderer* renderer);

	SDL_Texture* loadImg(const string& path);
	void release(SDL_Texture* texture);
	void update(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect);
	void render();
	void fadein(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect);
	void fadeout(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect);
	SDL_Renderer* m_renderer;
	
private:
	ImageLoad();
};

#endif // IMAGELOAD_H