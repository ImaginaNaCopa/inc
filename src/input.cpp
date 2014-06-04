#include "input.h"

namespace input
{
	vector<InputHandler *> handlers;

	void
	eventLoop()
	{
		loop("[Input] Beginning the event Handling Loop.");
		SDL_Event event;
		queue <SDL_Event> events;

		loop("[Input] Adding all Events in a Queue.");
	    while (SDL_PollEvent(&event) != 0)
	    {
	    	events.push(event);
		}

		loop("[Input] Handling each Event until Queue empty.");
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
		loop("[Input] Adding a input handler in a Vector.");
		handlers.push_back(h);
	}
}