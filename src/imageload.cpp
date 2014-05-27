#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "systemlogger.h"
#include "imageload.h"
#include <iostream>

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
ImageLoad::update(SDL_Texture* m_texture, SDL_Rect* destRect)
{
    SDL_RenderCopy( m_renderer, m_texture, NULL, destRect );
}

void
ImageLoad::render()
{
    SDL_RenderPresent( m_renderer );
    SDL_RenderClear ( m_renderer );
}

void
ImageLoad::fadein(SDL_Texture* m_texture, SDL_Rect* destRect)
{
    for (alpha = 0x00; alpha < 0xFF;)
    {
        alpha += 0x05;

        SDL_SetTextureBlendMode( m_texture, SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod( m_texture, alpha );

        SDL_RenderClear( m_renderer );
        SDL_RenderCopy( m_renderer, m_texture, NULL, destRect );
        SDL_RenderPresent( m_renderer );
    }
}

void
ImageLoad::fadeout(SDL_Texture* m_texture, SDL_Rect* destRect)
{
    for (alpha = 0xFF; alpha > 0x00;)
    {
        alpha -= 0x01;
     
        SDL_SetTextureBlendMode( m_texture, SDL_BLENDMODE_BLEND );
        SDL_SetTextureAlphaMod( m_texture, alpha );

        SDL_RenderClear( m_renderer );
        SDL_RenderCopy( m_renderer, m_texture, NULL, destRect );
        SDL_RenderPresent( m_renderer );
    }

}
