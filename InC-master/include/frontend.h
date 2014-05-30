#ifndef FRONTEND_H
#define FRONTEND_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "resource.h"

class FrontEnd
{
public:
	FrontEnd();
	~FrontEnd();
	void init();
	void draw();
	void release();
	void fadein();
	void fadeout();
private:
	SDL_Texture* menu_texture;
	SDL_Texture* rating_texture;
	SDL_Texture* otherlogos_texture;
	SDL_Texture* tryforcelogo_texture;

	SDL_Rect destTryforceLogo;
	SDL_Rect destOtherLogo;
	SDL_Rect destRating;
	SDL_Rect destMenu;

	ImageLoad* imageLoad;

	struct ISM* m_stack;

	bool isDrawn;
	Uint8 alpha;
};

#endif // FRONTEND_H