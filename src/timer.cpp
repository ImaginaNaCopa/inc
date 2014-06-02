#include "timer.h"

namespace timer
{
	Uint32 now = 0;
	Uint32 last = 0;
	int normalFPS = 40;
	int timelineEventNumber = 0;
	int idleTime = 0;

	void
	tick()
	{
		now = SDL_GetTicks();
	}

	bool
	isBeyondLimitsOfFPS()
	{
		if(now > (last + (1000/normalFPS)))
			return true;
		return false;
	}

	Uint32
	getDelta()
	{
		return (now - last);
	}

	int
	getTimelineEvent()
	{
		return timelineEventNumber;
	}

	void
	setTimelineEvent(int eventNumber)
	{
		timelineEventNumber = eventNumber;
	}

	int
	getIdleTime()
	{
		return idleTime;
	}

	void
	setIdleTime(int newIdleTime)
	{
		idleTime = newIdleTime;
	}

	void
	setLastToNow()
	{
		last = now;
	}
}