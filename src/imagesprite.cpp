#include "imagesprite.h"

ImageSprite::ImageSprite()
{
	loop("[ImageSprite] Constructing.");
	m_texture = NULL;
	m_width = 0;
	m_height = 0;
	m_clipNumber = 0;
}

ImageSprite::~ImageSprite()
{
	loop("[ImageSprite] Destroying.");
	release();
}

void
ImageSprite::init()
{
	loop("[ImageSprite] Loading the Image According to Path.");
	m_texture = loadImage(imagePath);
}

void
ImageSprite::draw()
{
	loop("[ImageSprite] Drawing Usually.");
	imageDraw(m_texture, &m_clips.at(m_clipNumber), &m_position);
}

void
ImageSprite::drawRelative()
{
	loop("[ImageSprite] Drawing Relative to Camera Position.");
	SDL_Rect relative = {m_position.x - getCameraLeftPosition(),
		m_position.y, m_position.w, m_position.h };

	if(ifCollided(0,getCameraRange(),m_position))
		imageDraw(m_texture, &m_clips.at(m_clipNumber), &relative);
}

void
ImageSprite::release()
{
	loop("[ImageSprite] Releasing a Texture.");
	if(m_texture!=NULL)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
		m_width = 0;
		m_height = 0;
	}
}

void
ImageSprite::generatePosition(int x, int y, int w, int h)
{
	loop("[ImageSprite] Generating a Position Rect.");
	m_position.x = x;
	m_position.y = y;
	m_position.w = w;
	m_position.h = h;
}

void
ImageSprite::addClip(int x, int y, int w, int h)
{
	loop("[ImageSprite] Pushing Back in Vector.");
	SDL_Rect clipBase = {x,y,w,h};
	m_clips.push_back(clipBase);
}

SDL_Rect
ImageSprite::getPosition()
{
	loop("[ImageSprite] Getting a Position.");
	return m_position;
}

int
ImageSprite::getWidth()
{
	loop("[ImageSprite] Getting Width from Image.");
	return m_width;
}

int
ImageSprite::getHeight()
{
	loop("[ImageSprite] Getting Height from Image.");
	return m_height;
}

void
ImageSprite::setClipNumber(int clipNumber)
{
	m_position.y += m_clips.at(m_clipNumber).h - m_clips.at(clipNumber).h;
	m_position.x += m_clips.at(m_clipNumber).w - m_clips.at(clipNumber).w;
	m_clipNumber = clipNumber;
	m_position.h = m_clips.at(m_clipNumber).h;
	m_position.w = m_clips.at(m_clipNumber).w;
}

void
ImageSprite::setOnlyClipNumber(int clipNumber)
{
	m_clipNumber = clipNumber;
}