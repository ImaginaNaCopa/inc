#ifndef INPUT_H
#define INPUT_H

#include "inputhandler.h"

using namespace std;

namespace input
{
	void eventLoop();
	void addHandler(InputHandler * h);
}

#endif // INPUT_H
