#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "hp.h"
#include "systemlogger.h"

using namespace std;

Hp::Hp() : ImageSprite()
{
	imagePath.clear();
	imagePath.assign("res/images/s_hud.png");
	generatePosition(0,0,50,15);
	generateClips();
	isDrawn = false;
}

Hp::~Hp()
{
}

void 
Hp::drawEach()
{
	m_position.x = 10;
	m_position.y = 10;
    draw();
    m_position.x = 60;
    draw();
    m_position.x = 110;
    draw();
}

void
Hp::generateClips()
{
	step("[HP] Generating Sprite Clips.");
	addClip(0,0,m_position.w,m_position.h);
	addClip(m_position.w,0,m_position.w,m_position.h);
	step("[HP] Finished Generating Sprite Clips.");
}