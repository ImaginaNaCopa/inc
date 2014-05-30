#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "inputhandler.h"

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
	SDL_Texture* m_texture;
	SDL_Rect position;
	ImageLoad* imageLoad;

	bool isDrawn;
	int speed;
	int gravity;
	int dx;
	int dy;
};

#endif // CAIO_H