#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "inputhandler.h"
#include "imagesprite.h"

class Caio : public InputHandler
{
public:
	Caio();
	~Caio();

	void init();
	void draw();
	void update(Uint32 delta);
	void release();

	bool handle(SDL_Event& event);
private:
	SDL_Rect m_clips[16];
	SDL_Rect m_position;
	ImageSprite* m_imageSprite;
	ImageLoad* imageLoad;

	bool isDrawn;
	int speed;
	int gravity;
	int dx;
	int dy;
	int u;
};

#endif // CAIO_H