#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <cmath>
#include "systemlogger.h"

using namespace systemLogger;

namespace configuration
{
	int getWindowW();
	int getWindowH();
	void setNewWindowDimension(int newMultiplyFactor);

	int getLevelW();
	void setLevelW(int newMultiplyFactorToLevel);

	int getPlatformH();
}

#endif // CONFIGURATION_H