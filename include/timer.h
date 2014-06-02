#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

namespace timer
{
	void tick();

	bool isBeyondLimitsOfFPS();

	Uint32 getDelta();
	
	int getTimelineEvent();
	void setTimelineEvent(int eventNumber);

	int getIdleTime();
	void setIdleTime(int newIdleTime);
	
	void setLastToNow();
}

#endif // TIMER_H