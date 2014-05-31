#include "system.h"

System::System()
{
	step("[System] Trying to Construct.");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        errorSDL("Couldn't Initialize SDL Video.", SDL_GetError());
}

System::~System()
{
	step("[System] Destroying.");
    SDL_Quit();
}