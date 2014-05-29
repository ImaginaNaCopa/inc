#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "platform.h"

using namespace std;

Platform::Platform()
{
	m_position.x = 0;
	m_position.y = 450;
	m_position.w = 800;
	m_position.h = 150;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Platform::~Platform()
{
	// Nothing yet
}

void 
Platform::init()
{
	loadFromFile("res/images/platform.png");
}

void 
Platform::draw()
{
   	imageLoad->update(m_texture, NULL, &m_position);
}

void 
Platform::release()
{
	SDL_DestroyTexture(m_texture);
}