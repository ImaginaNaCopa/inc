#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>
#include "systemlogger.h"

using namespace systemLogger;

namespace timer
{
	void tick();

	bool isBeyondLimitsOfFPS();

	Uint32 getDelta();
	
	int getTimelineEvent();
	void setTimelineEvent(int eventNumber);

	int getIdleTime();
	void setIdleTime(int newIdleTime);

	bool isOver();
	void setOver(bool overState);
	
	void setLastToNow();
}

#endif // TIMER_H