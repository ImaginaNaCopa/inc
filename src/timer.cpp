#include "timer.h"

namespace timer
{
	Uint32 now = 0;
	Uint32 last = 0;
	int normalFPS = 40;
	int timelineEventNumber = 0;
	int idleTime = 0;
	bool over = false;

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
		over = false;
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

	bool
	isOver()
	{
		return over;
	}

	void
	setOver(bool overState)
	{
		over = overState;
	}

	void
	setLastToNow()
	{
		last = now;
	}	
}