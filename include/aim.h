#ifndef AIM_H
#define AIM_H

#include <SDL2/SDL.h>
#include "caio.h"
#include "imagesprite.h"
#include "inputhandler.h"
#include "systemlogger.h"

class Aim : public InputHandler, public ImageSprite
{
public:
	Aim();
	~Aim();

	void overPlayer(SDL_Rect rect);

	void update();
	bool handle(SDL_Event& event);

	void generateClips();
};

#endif // AIM_H