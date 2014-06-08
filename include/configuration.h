#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <cmath>
#include "systemlogger.h"
#include "imageload.h"

using namespace systemLogger;

namespace configuration
{
	int getWindowW();
	int getWindowH();

	int getWindowSizeType();
	void setWindowSizeType(int newWindowSizeType);

	int getLevelW();
	void setLevelW(float newMultiplyFactorToLevel);

	int getPlatformH();
}

#endif // CONFIGURATION_H