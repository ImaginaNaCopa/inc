#include "imageload.h"

ImageLoad::ImageLoad()
{
    step("[Image Load] Constructing.");
	m_renderer = NULL;
}

static ImageLoad* instance = NULL;

ImageLoad* 
ImageLoad::getInstance()
{
    loop("[Image Load] Getting Instance.");
	if (instance == NULL)
	{
        step("[Image Load] Using Constructor to Instance.");
		instance = new ImageLoad();
	}
		
	return instance;
}

void 
ImageLoad::setRenderer(SDL_Renderer* renderer)
{
    step("[Image Load] Setting Renderer.");
	m_renderer = renderer;
}


SDL_Texture* 
ImageLoad::loadImg(const string& path)
{
    loop("[Image Load] Loading Image.");

	if (m_renderer == NULL)
	{
		return NULL;
	}
	
	SDL_Surface* surface = IMG_Load( path.c_str() );

    if( surface == NULL )
    {
        errorSDL("[Image Load] Null Surface", SDL_GetError());
    }

    SDL_SetColorKey (surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFA, 0xCF, 0xAC));

    SDL_Texture* texture = SDL_CreateTextureFromSurface( m_renderer, surface );

    if( texture == NULL )
    {
        errorSDL("[Image Load] Null Texture", SDL_GetError());
    }

    return texture;
}

void 
ImageLoad::release(SDL_Texture* texture)
{
    loop("[Image Load] Releasing a Texture.");
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}
}

void
ImageLoad::update(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
    loop("[Image Load] Updating the Image.");
    SDL_RenderCopy( m_renderer, texture, srcRect, destRect);
}

void
ImageLoad::render()
{
    loop("[Image Load] Rendering the Image.");
    SDL_RenderPresent( m_renderer );
    SDL_RenderClear ( m_renderer );
}