#include "timer.h"

namespace timer
{
	Uint32 now = 0;
	Uint32 last = 0;
	int normalFPS = 40;
	bool limitFPS = false;

	bool
	beyondLimitsOfFPS()
	{
		if(now > (last + (1000/normalFPS)))
			limitFPS = true;
		else
			limitFPS = false;
		return limitFPS;
	}

	void
	waitMiliseconds(int waitingTime)
	{
		while(now < (last + waitingTime))
		{
			tick();
		}
	}

	Uint32
	getDelta()
	{
		return (now - last);
	}

	void
	setLastToNow()
	{
		last = now;
	}

	void
	tick()
	{
		now = SDL_GetTicks();
	}
}