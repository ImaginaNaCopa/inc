#include "fontconfiguration.h"

namespace fontConfiguration
{
	const string& nulshock = "res/fonts/nulshock/nulshock_bd.ttf";
	const string& tulpenOne = "res/fonts/tulpen-one/TulpenOne-Regular.ttf";
	const int fontSizes[30] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};

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