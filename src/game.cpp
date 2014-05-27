#include "game.h"
#include "systemlogger.h"

#include <string>
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

Game::Game()
{
    try 
    {
        SystemLogger::step("[Game] Trying to Construct.");

        m_system = new System();
        m_window = new Window();
        m_input = new Input();
        m_stage = new Stage();

        imageLoad = ImageLoad::getInstance();
        imageLoad->setRenderer(m_window->renderer());

        m_frontEnd = new FrontEnd();

        m_stack = NULL;
        exitstate[0] = false;
        exitstate[1] = false;

        m_input->addHandler(this);
        m_input->addHandler(m_stage->getEntity()->getCaio());
        m_input->addHandler(m_stage->getEntity()->getAim());
        //m_input->addHandler(m_fade);
    } 
    catch (const string& e)
    {
        SystemLogger::error(e);
        SystemLogger::step("[Game] Destroying Manually.");

        free(m_stack);
        delete m_frontEnd;
        delete m_stage;
        delete m_input;
        delete m_window;
        delete m_system;
    }
}

Game::~Game()
{
    SystemLogger::step("[Game] Destroying.");
    free(m_stack);
    delete m_frontEnd;
    delete m_stage;
    delete m_input;
    delete m_window;
    delete m_system;
}

void
Game::init()
{
    SystemLogger::step("[Game] Using Init Method.");
    m_frontEnd->init();
    m_stage->init();
}

void
Game::shutdown()
{
    SystemLogger::step("[Game] Using Shutdown Method.");
    m_stage->release();
    m_frontEnd->release();
}

void
Game::run()
{
    SystemLogger::step("[Game] Using Run Method.");
    m_frontEnd->draw();

    Uint32 now = SDL_GetTicks();
    Uint32 last = 0;

    while ( !m_quit )
    {
        now = SDL_GetTicks();
        m_input->eventLoop();
        if(now > last + 25)
        {
            m_stage->update(now - last);  
            m_stage->draw();
            imageLoad->render();
            last = now;
        }
    }
}

bool 
Game::handle(SDL_Event &event)
{
    bool processed = false;

    if (event.type == SDL_QUIT)
    {
        m_quit = true;
    }

    switch (event.type)
    {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                //SDL_keycodes
                case SDLK_LCTRL:
                    exitstate[0] = true;
                    processed = true;
                break;
                case SDLK_q:
                    exitstate[1] = true;
                    processed = true;
                break;
                default:
                break;
            }
        break;

        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_LCTRL:
                    exitstate[0] = false;
                    processed = true;
                break;
                case SDLK_q:
                    exitstate[1] = false;
                    processed = true;
                break;
                default:
                break;
            }
        break;

        default:
        break;
    }
    
    if (exitstate[0] == true && exitstate[1] == true)
    {
        m_quit = true;
    }

    return processed;
}
