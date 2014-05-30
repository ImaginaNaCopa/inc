#include "background.h"
#include "imageload.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

Background::Background()
{
	position.x = 0;
	position.y = 0;
	position.w = 800;
	position.h = 600;

	isDrawn = false;

    imageLoad = ImageLoad::getInstance();
}

Background::~Background()
{
	// Nothing yet
}

void
Background::init()
{

	m_texture = imageLoad->loadImg("res/images/background.png");
}

void
Background::draw()
{
	imageLoad->update(m_texture, &position);
}

void
Background::release()
{
	SDL_DestroyTexture(m_texture);
}
