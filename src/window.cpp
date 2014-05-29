#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "systemlogger.h"
#include "window.h"

using namespace std;

Window::Window(unsigned int width, unsigned int height) : m_w(width), m_h(height)
{
    SystemLogger::step("[Window] Trying to Construct.");
    // Setando filtro de textura linear
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

    // Criando a janela
    m_window = SDL_CreateWindow( "InC. - Imagina na Copa", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        m_w, m_h, SDL_WINDOW_SHOWN );

    if ( m_window == NULL )
        SystemLogger::errorSDL("Couldn't Create Window.", SDL_GetError());

    // Criando renderer para a janela
    m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );

    if ( m_renderer == NULL )
    {
        SDL_DestroyWindow(m_window);
        SystemLogger::errorSDL("Couldn't Create Renderer.", SDL_GetError());;
    }

    SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 255 );

    // Criando imagem
    imageFlags = IMG_INIT_PNG;

    if (!(IMG_Init(imageFlags) & imageFlags))
    {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SystemLogger::errorSDL("Couldn't Initialize IMG with PNG Flag.", SDL_GetError());
    }
    else{
        m_surface = SDL_GetWindowSurface (m_window);
    }
}

Window::~Window()
{
    SystemLogger::step("[Window] Destroying.");
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

SDL_Renderer *
Window::renderer() const
{
    SystemLogger::step("[Window] Getting the Renderer.");
    return m_renderer;
}

SDL_Surface *
Window::getSurface() const
{
    SystemLogger::step("[Window] Getting the Surface.");
    return m_surface;
}

int
Window::w() const
{
    SystemLogger::step("[Window] Getting the Width.");
    return m_w;
}

int
Window::h() const
{
    SystemLogger::step("[Window] Getting the Height.");
    return m_h;
}
