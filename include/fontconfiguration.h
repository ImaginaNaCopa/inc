#ifndef FONTCONFIGURATION_H
#define FONTCONFIGURATION_H

#include <string>
#include <SDL2/SDL_ttf.h>

using namespace std;

namespace fontConfiguration
{
	const string& getFontNulshock();
	const string& getFontTulpenOne();
	int getFontSize(int fontTypeSize);
}

#endif // FONTCONFIGURATION_H