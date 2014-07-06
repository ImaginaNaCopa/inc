#include "imageeffect.h"
#include <iostream>

ImageEffect::ImageEffect() : ImageSprite()
{
	m_iTimeNumber = 0;
	m_alpha = 0;
	m_fading = false;
	m_fadingin = false;
	m_endedFade = false;
	newIdleTime();
}

ImageEffect::~ImageEffect() {}

void
ImageEffect::fade(Uint8 fadeTick, int idle)
{
	defineCurrentIdleTime(0);
	if(!m_endedFade)
	{
		loop("[ImageEffect] Ticking a new Fade.");
		if(m_fading)
		{
			loop("[ImageEffect] Its Fading...");
			if(m_fadingin)
			{
				loop("[ImageEffect] ...And its fading IN!");
				if(m_alpha!=SDL_ALPHA_OPAQUE)
					fadeinTick(fadeTick);
				else
					m_fading = false;
			}
			else
			{
				loop("[ImageEffect] ...And its fading OUT!");
				if(m_alpha!=SDL_ALPHA_TRANSPARENT)
					fadeoutTick(fadeTick);
				else
					m_fading = false;
			}
		}
		else
		{
			loop("[ImageEffect] Its NOT Fading...");
			if(getCurrentIdleTime() == idle)
			{
				loop("[ImageEffect] Finished Idle Time.");
				setCurrentIdleTime(0);
				m_fading = true;
				m_fadingin = false;
			}
			else if(m_alpha==SDL_ALPHA_OPAQUE)
				setCurrentIdleTime(getCurrentIdleTime()+1);
			if(m_alpha==SDL_ALPHA_TRANSPARENT)
			{
				loop("[ImageEffect] Ending Fade.");
				SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
				SDL_SetTextureAlphaMod(m_texture, SDL_ALPHA_TRANSPARENT);
				m_endedFade = true;
			}
		}
	}
}

void
ImageEffect::reverseFade(Uint8 fadeTick, int idle)
{
	defineCurrentIdleTime(0);
	if(!m_endedFade)
	{
		loop("[ImageEffect] Ticking a new Fade.");
		if(m_fading)
		{
			loop("[ImageEffect] Its Fading...");
			if(m_fadingin)
			{
				loop("[ImageEffect] ...And its fading IN!");
				if(m_alpha!=SDL_ALPHA_OPAQUE)
					fadeinTick(fadeTick);
				else
					m_fading = false;
			}
			else
			{
				loop("[ImageEffect] ...And its fading OUT!");
				if(m_alpha!=SDL_ALPHA_TRANSPARENT)
					fadeoutTick(fadeTick);
				else
					m_fading = false;
			}
		}
		else
		{
			loop("[ImageEffect] Its NOT Fading...");
			if(getCurrentIdleTime() == idle)
			{
				loop("[ImageEffect] Finished Idle Time.");
				setCurrentIdleTime(0);
				m_fading = true;
				m_fadingin = true;
			}
			else if(m_alpha==SDL_ALPHA_TRANSPARENT)
				setCurrentIdleTime(getCurrentIdleTime()+1);
			if(m_alpha==SDL_ALPHA_OPAQUE)
			{
				loop("[ImageEffect] Ending Fade.");
				SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
				SDL_SetTextureAlphaMod(m_texture, SDL_ALPHA_TRANSPARENT);
				m_endedFade = true;
			}
		}
	}
}

void
ImageEffect::fadeinTick(Uint8 fadeTick)
{
	loop("[ImageEffect] Ticking a Fade In.");
	if(m_alpha<SDL_ALPHA_OPAQUE)
	{
		SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(m_texture, m_alpha);
		m_alpha += fadeTick;
	}
	else
		m_alpha = SDL_ALPHA_OPAQUE;
}

void
ImageEffect::fadeoutTick(Uint8 fadeTick)
{
	loop("[ImageEffect] Ticking a Fade Out.");
	if(m_alpha>SDL_ALPHA_TRANSPARENT)
	{
		SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(m_texture, m_alpha);
		m_alpha -= fadeTick;
	}
	else
		m_alpha = SDL_ALPHA_TRANSPARENT;
}

int
ImageEffect::getCurrentIdleTime()
{
	loop("[ImageEffect] Getting Idle Time.");
	return idleTimes.at(m_iTimeNumber);
}

void
ImageEffect::setCurrentIdleTime(int newITimeNumber)
{
	loop("[ImageEffect] Setting a new Idle Time.");
	idleTimes.at(m_iTimeNumber) = newITimeNumber;
}

void
ImageEffect::newIdleTime()
{
	loop("[ImageEffect] New IdleTime.");
	idleTimes.push_back(0);
}

void
ImageEffect::newVariousIdleTimes(int quantity)
{
	int iterator = quantity;
	while(iterator!=0)
	{
		idleTimes.push_back(0);
		iterator--;
	}
}

void
ImageEffect::defineCurrentIdleTime(int coordinate)
{
	m_iTimeNumber = coordinate;
}

bool
ImageEffect::isFadeEnded()
{
	return m_endedFade;
}

void
ImageEffect::newFade()
{
	m_endedFade = false;
	m_fading = true;
	m_fadingin = true;
	m_alpha = SDL_ALPHA_TRANSPARENT;
}

void
ImageEffect::newReverseFade()
{
	m_endedFade = false;
	m_fading = true;
	m_fadingin = false;
	m_alpha = SDL_ALPHA_OPAQUE;
}