#include "fontconfiguration.h"

namespace fontConfiguration
{
	const string& nulshock = "res/fonts/nulshock/nulshock_bd.ttf";
	const string& tulpenOne = "res/fonts/tulpen-one/TulpenOne-Regular.ttf";
	int fontSizes[10] = {10,20,30,40,50,60,70,80,90,100};

	const string&
	getFontNulshock()
	{
		return nulshock;
	}

	const string&
	getFontTulpenOne()
	{
		return tulpenOne;
	}

	int
	getFontSize(int fontTypeSize)
	{
		return fontSizes[fontTypeSize];
	}
}