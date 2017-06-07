#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/systemlogger.h"
#include "../include/configuration.h"

using namespace configuration;
using namespace systemLogger;

class Window {
	public:
		Window();
		~Window();

		SDL_Renderer * renderer() const;
		SDL_Surface * getSurface() const;

	private:
		unsigned int m_width;
		unsigned int m_height;
		int imageFlags;

		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Surface *m_surface;
};

#endif // WINDOW_H
