#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <vector>
#include "inputhandler.h"

using namespace std;

class Input
{
public:
	Input();
	~Input();
	void eventLoop();
	void addHandler(InputHandler * h);
private:
	vector<InputHandler *> m_handlers;
};

#endif // INPUT_H
