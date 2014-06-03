#include "configuration.h"

namespace configuration
{
	int WindowWidthBase = 32;
	int WindowHeightBase = 24;
	int multiplyFactor = 25;

	int multiplyFactorToLevel = 2;

	int
	getWindowW()
	{
		loop("[Configuration] Getting Window Width.");
		return WindowWidthBase*multiplyFactor;
	}

	int
	getWindowH()
	{
		loop("[Configuration] Getting Window Height.");
		return WindowHeightBase*multiplyFactor;
	}

	void
	setNewWindowDimension(int newMultiplyFactor)
	{
		loop("[Configuration] Setting New Window Multiply Factor.");
		multiplyFactor = newMultiplyFactor;	
	}

	int
	getLevelW()
	{
		loop("[Configuration] Getting Level Width.");
		return WindowWidthBase * multiplyFactor * multiplyFactorToLevel;
	}

	void
	setLevelW(int newMultiplyFactorToLevel)
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
}