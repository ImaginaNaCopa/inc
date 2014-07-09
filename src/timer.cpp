#include "timer.h"

namespace timer
{
	Uint32 now = 0;
	Uint32 last = 0;
	int normalFPS = 40;
	Timeline backupGameOver = MAINMENU;
	Timeline timelineEvent = FRONTEND;
	bool start = false;
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

	Timeline
	getTimelineEvent()
	{
		loop("[Timer] Getting Timeline Event.");
		return timelineEvent;
	}

	void
	setTimelineEvent(Timeline newTimelineEvent)
	{
		loop("[Timer] Setting a New Timeline Event.");
		setOver(true);
		timelineEvent = newTimelineEvent;
	}

	Timeline
	getLastTimelineEvent()
	{
		loop("[Timer] Getting Timeline Event.");
		return backupGameOver;
	}

	void
	recordCurrentTimelineEvent()
	{
		loop("[Timer] Setting a New Timeline Event.");
		backupGameOver = timelineEvent;
	}

	bool
	isStarted()
	{
		loop("[Timer] Returning Started Condition from Timeline Event.");
		return start;
	}

	void
	setStart(bool startState)
	{
		loop("[Timer] Setting the Start State.");
		start = startState;
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
		loop("[Timer] Setting the Over State.");
		over = overState;
		setStart(!isOver());
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