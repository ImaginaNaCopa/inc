#include "aim.h"
#include <iostream>

Aim::Aim() : ImageSprite()
{
	step("[Aim] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(round(getWindowW()/2),round(getWindowH()/2),87,90);
	generateClips();
	defineEffects();
	SDL_ShowCursor(0);
}

Aim::~Aim()
{
	step("[Aim] Destroying.");
	release();
}

void
Aim::generateClips()
{
	image("[Aim] Generating Sprite Clips.");
	addClip(100,0,87,90);
	addClip(200,0,87,90);
	addClip(300,0,87,90);
}

void
Aim::defineEffects()
{
	step("[Aim] Defining Audio Effects.");
	shot1 = new AudioHandler();
	shot1->setCurrentEffect("res/audios/se/shot.ogg");
	shot1->setEffectVolume(100);
}

void 
Aim::update()
{
	loop("[Aim] Updating.");
	m_shoot = isCShooted();
	updateKernel();
	setOnlyClipNumber(2);
}

bool 
Aim::overEnemy(SDL_Rect rect)
{
	loop("[Aim] Searching if Targeted an Entity (Over Enemy).");   
	if (ifCollided(0,getKernel(),rect))
	{
		condition("[Aim] Targeted an Entity (Over Enemy).");
		setOnlyClipNumber(1);
		if(m_shoot==true)
			shot1->playEffect(0);
		return m_shoot;
	}

	return false;
}

void
Aim::overPlayer(SDL_Rect rect)
{
	loop("[Aim] Searching if Targeted an Entity (Over Player).");   
	if (ifCollided(0,getKernel(),rect))
	{
		condition("[Aim] Targeted an Entity (Over Player).");
		setOnlyClipNumber(0);
	}
}

SDL_Rect
Aim::getKernel()
{
	loop("[Aim] Getting Kernel Position.");
	return m_kernel;
}

void
Aim::updateKernel()
{
	loop("[Aim] Updating Kernel Position.");
	m_position = updateKernelMotionM(m_position);
	m_kernel = {m_position.x+getCameraLeftPosition()+40, m_position.y+40, 5, 5};
}

bool
Aim::getShoot()
{
	return m_shoot;
}

void
Aim::setShoot(bool shoot)
{
	m_shoot = shoot;
}