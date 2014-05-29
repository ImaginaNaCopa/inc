#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "platform.h"
#include "systemlogger.h"

using namespace std;

Platform::Platform()
{
	imagePath.clear();
	imagePath.assign("res/images/platform.png");
	generatePosition(0,450,800,150);
	generateClips();
}

Platform::~Platform()
{
}

void
Platform::generateClips()
{
	SystemLogger::step("[Platform] Generating Sprite Clips.");
	addClip(0,0,800,150);
	SystemLogger::step("[Platform] Finished Generating Sprite Clips.");
}