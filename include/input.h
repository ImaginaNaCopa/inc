#ifndef INPUT_H
#define INPUT_H

#include "inputhandler.h"
#include "systemlogger.h"

using namespace systemLogger;

namespace input
{
	void eventLoop();
	void addHandler(InputHandler* h);
	void removeHandler(InputHandler* h);
}

#endif // INPUT_H
