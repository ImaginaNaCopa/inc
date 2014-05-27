#ifndef AIM_H
#define AIM_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "inputhandler.h"

class Aim : public InputHandler
{
public:
	Aim();
	~Aim();

	void init();
	void draw();
	void update();
	void release();

	bool handle(SDL_Event& event);
private:
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
};

#endif // AIM_H