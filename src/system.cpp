#include "system.h"

System::System()
{
	step("[System] Trying to Construct.");
	if (TTF_Init() < 0)
		errorSDL("Couldn't Initialize SDL Fonts.", TTF_GetError());
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		errorSDL("Couldn't Initialize SDL Video.", SDL_GetError());
}

System::~System()
{
	step("[System] Destroying.");
	TTF_Quit();
	SDL_Quit();
}