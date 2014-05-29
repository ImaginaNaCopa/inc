#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "imageload.h"
#include "systemlogger.h"

using namespace std;

ImageLoad::ImageLoad()
{
    SystemLogger::step("[Image Load] Contructing.");
	m_renderer = NULL;
}

static ImageLoad* instance = NULL;

ImageLoad* 
ImageLoad::getInstance()
{
    SystemLogger::step("[Image Load] Getting Instance.");
	if (instance == NULL)
	{
        SystemLogger::step("[Image Load] Using Constructor to Instance.");
		instance = new ImageLoad();
	}
		
	return instance;
}

void 
ImageLoad::releaseInstance()
{
    SystemLogger::step("[Image Load] Releasing Instance.");
	delete instance;
}

void 
ImageLoad::setRenderer(SDL_Renderer* renderer)
{
    SystemLogger::step("[Image Load] Setting Renderer.");
	m_renderer = renderer;
}


SDL_Texture* 
ImageLoad::loadImg(const string& path)
{
    SystemLogger::step("[Image Load] Loading Image."); // PAREI AQUI ARKYE

	if (m_renderer == NULL)
	{
		return NULL;
	}
	
	SDL_Surface* surface = IMG_Load( path.c_str() );

    if( surface == NULL )
    {
        cout << SDL_GetError() << endl;
        throw "Impossível carregar a imagem!";
    }

    SDL_SetColorKey (surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFA, 0xCF, 0xAC));

    SDL_Texture* texture = SDL_CreateTextureFromSurface( m_renderer, surface );

    if( texture == NULL )
    {
    	SDL_FreeSurface(surface);
    	throw "Impossível criar a textura!";
    }

    return texture;
}

void 
ImageLoad::release(SDL_Texture* texture)
{
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}
}

void
ImageLoad::update(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
    SDL_RenderCopy( m_renderer, texture, srcRect, destRect);
}

void
ImageLoad::render()
{
    SDL_RenderPresent( m_renderer );
    SDL_RenderClear ( m_renderer );
}

void
ImageLoad::fadein(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
    for (m_alpha = 0x00; m_alpha < 0xFF;)
    {
        m_alpha += 0x05;

        SDL_SetTextureBlendMode( texture, SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod( texture, m_alpha );

        SDL_RenderClear( m_renderer );
        SDL_RenderCopy( m_renderer, texture, srcRect, destRect );
        SDL_RenderPresent( m_renderer );
    }
}

void
ImageLoad::fadeout(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
    for (m_alpha = 0xFF; m_alpha > 0x00;)
    {
        m_alpha -= 0x01;
     
        SDL_SetTextureBlendMode( texture, SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod( texture, m_alpha );

        SDL_RenderClear( m_renderer );
        SDL_RenderCopy( m_renderer, texture, srcRect, destRect );
        SDL_RenderPresent( m_renderer );
    }

}
