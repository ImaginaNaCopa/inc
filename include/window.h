#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "systemlogger.h"

using namespace systemLogger;

class Window {
	public:
        Window(unsigned int w = 800, unsigned int h = 600);
        ~Window();

        SDL_Renderer * renderer() const;
        int w() const;
        int h() const;
        SDL_Surface * getSurface() const;

    private:
        unsigned int m_w;
        unsigned int m_h;
        int imageFlags;

        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Surface *m_surface;
};

#endif // WINDOW_H
