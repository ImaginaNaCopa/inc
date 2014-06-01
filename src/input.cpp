#include "input.h"

namespace input
{
	vector<InputHandler *> handlers;

	void
	eventLoop()
	{
		SDL_Event event;
		queue <SDL_Event> events;

	    while (SDL_PollEvent(&event) != 0)
	    {
	    	events.push(event);
		}
		while(events.empty() == false)
		{
			event = events.front();
			events.pop();
			for (size_t i = 0; i < handlers.size(); i++)
			{
				if (handlers[i]->handle(event))
				{
					break;
				}
			}
		}
	}

	void 
	addHandler(InputHandler * h)
	{
		handlers.push_back(h);
	}
}