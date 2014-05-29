#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "secondlayer.h"

using namespace std;

SecondLayer::SecondLayer()
{
	position.x = 60;
	position.y = 150;
	position.w = 120;
	position.h = 120;

	isDrawn = false;

    imageLoad = ImageLoad::getInstance();
}

SecondLayer::~SecondLayer()
{
	// Nothing yet
}

void
SecondLayer::init()
{
	m_texture = imageLoad->loadImg("res/images/sun.png");
}

void
SecondLayer::draw()
{
	imageLoad->update(m_texture, NULL, &position);
}

void
SecondLayer::release()
{
	SDL_DestroyTexture(m_texture);
}
