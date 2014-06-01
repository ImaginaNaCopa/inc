#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <cmath>

namespace configuration
{
	int getWindowW();
	int getWindowH();
	void setNewWindowDimension(int newMultiplyFactor);

	int getNormalLevelW();
	void setNormalLevelW(int newMultiplyFactorToNormalLevel);

	int getPlatformH();
}

#endif // CONFIGURATION_H