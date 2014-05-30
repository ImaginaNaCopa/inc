#ifndef AIM_H
#define AIM_H

#include "imagesprite.h"
#include "inputhandler.h"
#include "systemlogger.h"

class Aim : public InputHandler, public ImageSprite
{
public:
	Aim();
	~Aim();

	void overPlayer(SDL_Rect rect);
	bool overEnemy(SDL_Rect rect);

	void update();
	bool handle(SDL_Event& event);

	void generateClips();
	
private:
	bool shoot;
};

#endif // AIM_H