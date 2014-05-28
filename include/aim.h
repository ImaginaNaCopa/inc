#ifndef AIM_H
#define AIM_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"
#include "inputhandler.h"
#include "caio.h"

class Aim : public InputHandler
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
private:
	SDL_Texture* m_texture;
	SDL_Rect m_position;
	SDL_Rect m_clips[3];
	ImageSprite* m_imageSprite;
	ImageLoad* imageLoad;

	int u;
};

#endif // AIM_H