#include "system.h"
#include "systemlogger.h"

#include <SDL2/SDL.h>

System::System()
{
	SystemLogger::step("[System] Trying to Construct.");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        SystemLogger::errorSDL("Couldn't Initialize SDL Video.", SDL_GetError());
}

System::~System()
{
	SystemLogger::step("[System] Destroying.");
    SDL_Quit();
}