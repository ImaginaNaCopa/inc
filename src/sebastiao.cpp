#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "sebastiao.h"

using namespace std;

Sebastiao::Sebastiao() : ImageSprite()
{
	generatePosition(550,10,200,90);
	generateClips();
	isDrawn = false;
}

Sebastiao::~Sebastiao()
{
}

void 
Sebastiao::init()
{
	loadFromFile("res/images/s_sebastiao.png");
}

void 
Sebastiao::draw()
{
	imageLoad->update(m_texture, &m_clips.at(0), &m_position);
}

void 
Sebastiao::release()
{
	SDL_DestroyTexture(m_texture);
}

void
Sebastiao::generateClips()
{
	addClip(0,0,m_position.w,m_position.h);
	addClip(m_position.w,0,m_position.w,m_position.h);

	addClip(0,m_position.h,m_position.w,m_position.h);
	addClip(m_position.w,m_position.h,m_position.w,m_position.h);

	addClip(0,0,m_position.h*2,m_position.h);
	addClip(m_position.w,m_position.h*2,m_position.w,m_position.h);
	
	addClip(0,m_position.h*3,m_position.w,m_position.h);
	addClip(m_position.w,m_position.h*3,m_position.w,m_position.h);
}