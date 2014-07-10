#include "aim.h"
#include <iostream>

Aim::Aim() : ImageSprite()
{
	//step("[Aim] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(round(getWindowW()/2),round(getWindowH()/2),50,50);
	generateClips();
	defineEffects();
	SDL_ShowCursor(0);
}

Aim::~Aim()
{
	//step("[Aim] Destroying.");
}

void
Aim::generateClips()
{
	image("[Aim] Generating Sprite Clips.");
	addClip(50,0,50,50);
	addClip(100,0,50,50);
	addClip(150,0,50,50);
}

void
Aim::defineEffects()
{
	//step("[Aim] Defining Audio Effects.");
}

void 
Aim::update()
{
	//loop("[Aim] Updating.");
	m_shoot = isCShooted();
	updateKernel();
	setOnlyClipNumber(1);
}

bool 
Aim::overEnemy(SDL_Rect rect)
{
	//loop("[Aim] Searching if Targeted an Entity (Over Enemy).");   
	if (ifCollided(0,getKernel(),rect))
	{
		//condition("[Aim] Targeted an Entity (Over Enemy).");
		setOnlyClipNumber(2);
		if(m_shoot==true)
		{
			if(getTimelineEvent()==LEVELFOUR)
			{
				setCurrentEffect(S2);
				playEffect();
			}
			else
			{
				setCurrentEffect(S1);
				playEffect();
			}
		}
		return m_shoot;
	}

	return false;
}

void
Aim::overPlayer(SDL_Rect rect)
{
	//loop("[Aim] Searching if Targeted an Entity (Over Player).");   
	if (ifCollided(0,getKernel(),rect))
	{
		//condition("[Aim] Targeted an Entity (Over Player).");
		setOnlyClipNumber(0);
	}
}

SDL_Rect
Aim::getKernel()
{
	//loop("[Aim] Getting Kernel Position.");
	return m_kernel;
}

void
Aim::updateKernel()
{
	//loop("[Aim] Updating Kernel Position.");
	m_position = updateKernelMotionM(m_position);
	m_kernel = {m_position.x+getCameraLeftPosition()+22, m_position.y+22, 6, 6};
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