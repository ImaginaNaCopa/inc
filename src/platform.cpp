#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "platform.h"

using namespace std;

Platform::Platform()
{
	imagePath.clear();
	imagePath.insert(0,"res/images/platform.png");
	generatePosition(0,450,800,150);
}

Platform::~Platform()
{
}

void
Platform::generateClips()
{
	addClip(0,0,800,150);
}