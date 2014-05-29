#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "imageload.h"
#include "imagesprite.h"
#include "systemlogger.h"

using namespace std;

ImageSprite::ImageSprite()
{
	imageLoad = imageLoad->getInstance();
	m_texture = NULL;
	m_width = 0;
	m_height = 0;
	m_clipNumber = 0;
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

void
ImageSprite::generatePosition(int x, int y, int w, int h)
{
	m_position.x = x;
	m_position.y = y;
	m_position.w = w;
	m_position.h = h;
}

void
ImageSprite::addClip(int x, int y, int w, int h)
{
	SystemLogger::step("[ImageSprite] Trying to Push Back in Vector.");
	SDL_Rect clipBase;
	clipBase.x = x;
	clipBase.y = y;
	clipBase.w = w;
	clipBase.h = h;
	m_clips.push_back(clipBase);
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