#include "timer.h"

namespace timer
{
	Uint32 now = 0;
	Uint32 last = 0;
	int normalFPS = 40;
	int timelineEventNumber = 1;
	int idleTime = 0;
	bool over = false;
	bool quit = false;

	void
	tick()
	{
    	loop("[Timer] Tic-Tac.");
		now = SDL_GetTicks();
	}

	bool
	isBeyondLimitsOfFPS()
	{
    	loop("[Timer] Idle Miliseconds relative to normal FPS.");
		if(now > (last + (1000/normalFPS)))
			return true;
		return false;
	}

	Uint32
	getDelta()
	{
    	loop("[Timer] Getting Delta Time.");
		return (now - last);
	}

	int
	getTimelineEvent()
	{
    	loop("[Timer] Getting Timeline Event Number.");
		return timelineEventNumber;
	}

	void
	setTimelineEvent(int eventNumber)
	{
    	step("[Timer] Setting a New Timeline Event Number.");
		timelineEventNumber = eventNumber;
		over = false;
	}

	int
	getIdleTime()
	{
    	loop("[Timer] Getting Timeline Event Number.");
		return idleTime;
	}

	void
	setIdleTime(int newIdleTime)
	{
    	loop("[Timer] Setting a new Idle Time.");
		idleTime = newIdleTime;
	}

	bool
	isOver()
	{
    	loop("[Timer] Returning Over Condition from Timeline Event.");
		return over;
	}

	void
	setOver(bool overState)
	{
    	step("[Timer] Setting the Over State.");
		over = overState;
	}

	void
	setLastToNow()
	{
    	loop("[Timer] Defining Time Delta = 0.");
		last = now;
	}

	void
	iWantToQuit()
	{
		quit = true;
	}

	bool
	onQuit()
	{
		return quit;
	}
}