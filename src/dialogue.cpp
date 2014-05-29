#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "dialogue.h"
#include "imageload.h"

using namespace std;

Dialogue::Dialogue()
{
	position.x = 265;
	position.y = 10;
	position.w = 250;
	position.h = 125;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Dialogue::~Dialogue()
{
	// Nothing yet
}

void 
Dialogue::init()
{
	m_texture = imageLoad->loadImg("res/images/dialogue.png");
}

void 
Dialogue::draw()
{
    imageLoad->update(m_texture, NULL, &position);
}

void 
Dialogue::release()
{
	SDL_DestroyTexture(m_texture);
}