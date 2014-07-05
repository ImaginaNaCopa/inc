#include "imageload.h"

namespace imageLoad
{
	SDL_Renderer* renderer = NULL;

	void
	setRenderer(SDL_Renderer* newRenderer)
	{
		step("[Image Load] Setting Renderer.");
		renderer = newRenderer;
	}

	void
	freeRenderer()
	{
		step("[Image Load] Freeing Renderer.");
		free(renderer);
	}

	SDL_Texture*
	loadImage(const string& path)
	{
		loop("[Image Load] Loading Image.");

		if (renderer == NULL)
		{
			return NULL;
		}
		
		SDL_Surface* surface = IMG_Load( path.c_str() );

		if( surface == NULL )
		{
			errorSDL("[Image Load] Null Surface", SDL_GetError());
		}

		SDL_SetColorKey (surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFA, 0xCF, 0xAC));

		SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface );

		if( texture == NULL )
		{
			errorSDL("[Image Load] Null Texture", SDL_GetError());
		}

		return texture;		 
	}

	void
	imageDraw(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
	{
		loop("[Image Load] Updating the Image.");
		SDL_RenderCopy( renderer, texture, srcRect, destRect);
	}

	void
	render()
	{
		loop("[Image Load] Rendering the Image.");
		SDL_RenderPresent( renderer );
		SDL_RenderClear ( renderer );
	}

	SDL_Texture*
	surfaceToTexture(SDL_Surface* targetSurface)
	{
		return SDL_CreateTextureFromSurface(renderer,targetSurface); 
	}
}
