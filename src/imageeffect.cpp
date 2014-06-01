#include "imageeffect.h"

ImageEffect::ImageEffect() : ImageSprite()
{

}

ImageEffect::~ImageEffect()
{

}

void
ImageEffect::fadein()
{
    m_alpha = SDL_ALPHA_TRANSPARENT;
    while(m_alpha<SDL_ALPHA_OPAQUE)
    {
        waitMiliseconds(10);
        SDL_SetTextureBlendMode( m_texture, SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod(m_texture, m_alpha);
        m_alpha += 5;
        if(m_alpha>=SDL_ALPHA_OPAQUE)
            m_alpha = SDL_ALPHA_OPAQUE;
        draw();
        render();
    }
}

void
ImageEffect::fadeout()
{
    m_alpha = SDL_ALPHA_OPAQUE;
    while(m_alpha>SDL_ALPHA_TRANSPARENT)
    {
        waitMiliseconds(10);
        SDL_SetTextureBlendMode( m_texture, SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod(m_texture, m_alpha);
        m_alpha -= 5;
        if(m_alpha<=SDL_ALPHA_TRANSPARENT)
            m_alpha = SDL_ALPHA_TRANSPARENT;
        draw();
        render();
    }
}