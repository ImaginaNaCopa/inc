#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "frontend.h"
#include "imageload.h"

using namespace std;

FrontEnd::FrontEnd()
{
	destTryforceLogo.x = 800/2 - 261/2;
    destTryforceLogo.y = 600/2 - 151/2;
    destTryforceLogo.w = 261;
    destTryforceLogo.h = 151;

    
    destOtherLogo.x = 800/2 - 459/2;
    destOtherLogo.y = 600/2 - 400/2;
    destOtherLogo.w = 459;
    destOtherLogo.h = 400;
    
    destRating.x = 800/2 - 191/2;
    destRating.y = 600/2 - 285/2;
    destRating.w = 191;
    destRating.h = 285;

    destMenu.x = 800/2 - 682/2;
    destMenu.y = 600/2 - 437/2;
    destMenu.w = 682;
    destMenu.h = 437;

	isDrawn = false;

	m_stack = NULL;

    imageLoad = imageLoad->getInstance();
}

FrontEnd::~FrontEnd()
{
	// Nothing yet
}

void 
FrontEnd::init()
{
	try
	{
		menu_texture = imageLoad->loadImg("res/images/menu.png");
	    m_stack = ISM_Insert(m_stack, NULL, &destMenu, menu_texture);
	    rating_texture = imageLoad->loadImg("res/images/rating.png");
	    m_stack = ISM_Insert(m_stack, NULL, &destRating, rating_texture);
	    otherlogos_texture = imageLoad->loadImg("res/images/otherlogos.png");
	    m_stack = ISM_Insert(m_stack, NULL, &destOtherLogo, otherlogos_texture);
	    tryforcelogo_texture = imageLoad->loadImg("res/images/logo.png");
	    m_stack = ISM_Insert(m_stack, NULL, &destTryforceLogo, tryforcelogo_texture);
	}
	catch (const std::string& e)
	{
		SDL_DestroyTexture (tryforcelogo_texture);
		SDL_DestroyTexture (rating_texture);
		SDL_DestroyTexture (otherlogos_texture);
		SDL_DestroyTexture (menu_texture);
	    throw e;
	}
}

void 
FrontEnd::draw()
{
	while (!ISM_IfEmpty(m_stack))
	{
	    imageLoad->fadein(ISM_TopTexture(m_stack), NULL, ISM_TopDest(m_stack));
	    imageLoad->fadeout(ISM_TopTexture(m_stack), NULL, ISM_TopDest(m_stack));
	    m_stack = ISM_Pop(m_stack);		
	}
}

void 
FrontEnd::release()
{
	SDL_DestroyTexture (tryforcelogo_texture);
	SDL_DestroyTexture (rating_texture);
	SDL_DestroyTexture (otherlogos_texture);
	SDL_DestroyTexture (menu_texture);
}
