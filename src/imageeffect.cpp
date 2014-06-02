#include "imageeffect.h"

ImageEffect::ImageEffect() : ImageSprite()
{

}

ImageEffect::~ImageEffect()
{

}


void
ImageEffect::fade()
{
    if(m_fading)
    {
        if(m_fadingin)
        {
            if(m_alpha!=SDL_ALPHA_OPAQUE)
                fadeinTick();
            else
                m_fading = false;
        }
        else
        {
            if(m_alpha!=SDL_ALPHA_TRANSPARENT)
                fadeoutTick();
            else
                m_fading = false;
        }
    }
    else
    {
        if(m_alpha==SDL_ALPHA_OPAQUE)
            setIdleTime(getIdleTime()+1);
        else if((m_alpha==SDL_ALPHA_TRANSPARENT) && (m_clipNumber!=3))
        {
            m_clipNumber++;
            m_fading = true;
            m_fadingin = true;
        }

        if(getIdleTime() == 60)
        {
            setIdleTime(0);
            m_fading = true;
            m_fadingin = false;
        }       
    }   
}

void
ImageEffect::fadeinTick()
{
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
    if(m_alpha>SDL_ALPHA_TRANSPARENT)
    {
        SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(m_texture, m_alpha);
        m_alpha -= 15;
    }
    else
        m_alpha = SDL_ALPHA_TRANSPARENT;
}