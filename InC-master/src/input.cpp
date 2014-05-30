#include "input.h"
#include <queue>
#include <iostream>

using namespace std;

Input::Input()
{
}

Input::~Input()
{
}

void
Input::eventLoop()
{
	SDL_Event event;
	queue <SDL_Event> events;

	//pegando eventos pendentes
    while (SDL_PollEvent(&event) != 0)
    {
    	events.push(event);
	}
	while(events.empty() == false)
	{
		event = events.front();
		events.pop();
		for (size_t i = 0; i < m_handlers.size(); i++)
		{
			if (m_handlers[i]->handle(event))
			{
				break;
			}
		}
	}
}

void 
Input::addHandler(InputHandler * h)
{
	m_handlers.push_back(h);
}
