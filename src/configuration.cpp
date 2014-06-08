#include "configuration.h"

namespace configuration
{
	int windowWidthBase = 800;
	int windowHeightBase = 600;

	float resizeFactor[3] = {1,1.28,1.8};
	int windowSizeType = 0;

	float multiplyFactorToLevel = 2;

	bool fullScreenMode = false;
	bool muteSound = false;

	int
	getWindowW()
	{
		loop("[Configuration] Getting Window Width.");
		return windowWidthBase*resizeFactor[windowSizeType];
	}

	int
	getWindowH()
	{
		loop("[Configuration] Getting Window Height.");
		return windowHeightBase*resizeFactor[windowSizeType];
	}

	int
	getWindowSizeType()
	{
		return windowSizeType;
	}

	void
	setWindowSizeType(int newWindowSizeType)
	{
		loop("[Configuration] Setting New Window Resize Factor according to Type.");
		windowSizeType = newWindowSizeType;
	}

	int
	getLevelW()
	{
		loop("[Configuration] Getting Level Width.");
		return round(getWindowW() * multiplyFactorToLevel);
	}

	void
	setLevelW(float newMultiplyFactorToLevel)
	{
		loop("[Configuration] Setting Level Width.");
		multiplyFactorToLevel = newMultiplyFactorToLevel;
	}

	int
	getPlatformH()
	{
		loop("[Configuration] Getting Platform Height.");
		return round(((getWindowH())/50)*37.5);
	}

	void
	setFullScreenMode()
	{

	}

	void
	setWindowScreenMode()
	{

	}

	void
	setNoSound()
	{

	}

	void
	setSound()
	{
		
	}
}