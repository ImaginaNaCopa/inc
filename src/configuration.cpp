#include "configuration.h"

namespace configuration
{
	int WindowWidthBase = 32;
	int WindowHeightBase = 24;
	int multiplyFactor = 25;

	int multiplyFactorToNormalLevel = 2;

	int
	getWindowW()
	{
		return WindowWidthBase*multiplyFactor;
	}

	int
	getWindowH()
	{
		return WindowHeightBase*multiplyFactor;
	}

	void
	setNewWindowDimension(int newMultiplyFactor)
	{
		multiplyFactor = newMultiplyFactor;	
	}

	int
	getNormalLevelW()
	{
		return WindowWidthBase * multiplyFactor * multiplyFactorToNormalLevel;
	}

	void
	setNormalLevelW(int newMultiplyFactorToNormalLevel)
	{
		multiplyFactorToNormalLevel = newMultiplyFactorToNormalLevel;
	}

	int
	getPlatformH()
	{
		return round(((WindowHeightBase*multiplyFactor)/50)*37.5);
	}
}