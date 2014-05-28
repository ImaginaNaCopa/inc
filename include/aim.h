#ifndef AIM_H
#define AIM_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"
#include "inputhandler.h"
#include "caio.h"

class Aim : public InputHandler, public ImageSprite
{
public:
	Aim();
	~Aim();

	void init();
	void draw();
	void update();
	void release();

	void overPlayer(SDL_Rect rect);

	bool handle(SDL_Event& event);

	void generatePosition();
	void generateClips();
};

#endif // AIM_H