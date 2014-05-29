#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "sebastiao.h"
#include "systemlogger.h"

using namespace std;

Sebastiao::Sebastiao() : ImageSprite()
{
	imagePath.clear();
	imagePath.insert(0,"res/images/s_sebastiao.png");
	generatePosition(550,10,200,90);
	generateClips();
	isDrawn = false;
}

Sebastiao::~Sebastiao()
{
}

void
Sebastiao::generateClips()
{
	SystemLogger::step("[Sebastiao] Generating Sprite Clips.");
	addClip(0,0,m_position.w,m_position.h);
	addClip(m_position.w,0,m_position.w,m_position.h);

	addClip(0,m_position.h,m_position.w,m_position.h);
	addClip(m_position.w,m_position.h,m_position.w,m_position.h);

	addClip(0,0,m_position.h*2,m_position.h);
	addClip(m_position.w,m_position.h*2,m_position.w,m_position.h);
	
	addClip(0,m_position.h*3,m_position.w,m_position.h);
	addClip(m_position.w,m_position.h*3,m_position.w,m_position.h);
	SystemLogger::step("[Sebastiao] Finished Generating Sprite Clips.");
}