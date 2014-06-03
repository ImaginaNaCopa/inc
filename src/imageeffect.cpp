#include "imageeffect.h"

ImageEffect::ImageEffect() : ImageSprite() {}

ImageEffect::~ImageEffect() {}

void
ImageEffect::fade()
{
    loop("[ImageEffect] Ticking a new Fade.");
    if(m_fading)
    {
        loop("[ImageEffect] Its Fading...");
        if(m_fadingin)
        {
            loop("[ImageEffect] ...And its fading IN!");
            if(m_alpha!=SDL_ALPHA_OPAQUE)
                fadeinTick();
            else
                m_fading = false;
        }
        else
        {
            loop("[ImageEffect] ...And its fading OUT!");
            if(m_alpha!=SDL_ALPHA_TRANSPARENT)
                fadeoutTick();
            else
                m_fading = false;
        }
    }
    else
    {
        loop("[ImageEffect] Its NOT Fading...");
        if(m_alpha==SDL_ALPHA_OPAQUE)
            setIdleTime(getIdleTime()+1);
        else if((m_alpha==SDL_ALPHA_TRANSPARENT) && (m_clipNumber!=3))
        {
            loop("[ImageEffect] Starting a New Fading In.");
            m_clipNumber++;
            m_fading = true;
            m_fadingin = true;
        }

        if(getIdleTime() == 60)
        {
            loop("[ImageEffect] Finished Idle Time.");
            setIdleTime(0);
            m_fading = true;
            m_fadingin = false;
        }       
    }   
}

void
ImageEffect::fadeinTick()
{
    loop("[ImageEffect] Ticking a Fade In.");
    if(m_alpha<SDL_ALPHA_OPAQUE)
    {
        SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(m_texture, m_alpha);
        m_alpha += 15;
    }
    else
        m_alpha = SDL_ALPHA_OPAQUE;
}

void
ImageEffect::fadeoutTick()
{
    loop("[ImageEffect] Ticking a Fade Out.");
    if(m_alpha>SDL_ALPHA_TRANSPARENT)
    {
        SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(m_texture, m_alpha);
        m_alpha -= 15;
    }
    else
        m_alpha = SDL_ALPHA_TRANSPARENT;
}