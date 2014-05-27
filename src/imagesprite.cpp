#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "imagesprite.h"
#include "systemlogger.h"
#include "imageload.h"

using namespace std;

ImageSprite::ImageSprite()
{
	imageLoad = imageLoad->getInstance();
	m_texture = NULL;
	m_width = 0;
	m_height = 0;
}

ImageSprite::~ImageSprite()
{
	free();
}

bool
ImageSprite::loadFromFile(const string& path)
{
	free();
	SDL_Texture* newTexture = imageLoad->loadImg(path);
	//m_width = newTexture->w;
	//m_height = newTexture->h;
	m_texture = newTexture;
	return m_texture != NULL;
}

void
ImageSprite::free()
{
	if(m_texture!=NULL)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
		m_width = 0;
		m_height = 0;
	}
}

void
ImageSprite::render(int x, int y, SDL_Rect* clip)
{
	SDL_Rect renderQuad = {x, y, m_width, m_height};
	if(clip!=NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	imageLoad->update(m_texture, clip, &renderQuad);
}

int
ImageSprite::getWidth()
{
	return m_width;
}

int
ImageSprite::getHeight()
{
	return m_height;
}