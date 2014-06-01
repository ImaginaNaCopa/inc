#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

namespace timer
{
	bool beyondLimitsOfFPS();
	void tick();
	void waitMiliseconds(int waitingTime);
	Uint32 getDelta();
	void setLastToNow();
}

#endif // TIMER_H