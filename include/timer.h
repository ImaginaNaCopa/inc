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
	
	typedef enum {FRONTEND, MAINMENU, PROGRESSIONMENU, CONFIGURATIONMENU, CREDITS, LEVELONE, 
		LEVELTWO, LEVELTHREE, LEVELFOUR, LEVELFIVE, THEEND, GAMEOVER} Timeline;

	Timeline getTimelineEvent();
	void setTimelineEvent(Timeline timelineEvent);

	bool isStarted();
	void setStart(bool startState);

	bool isOver();
	void setOver(bool overState);
	
	void setLastToNow();

	void iWantToQuit();
	bool onQuit();
}

#endif // TIMER_H