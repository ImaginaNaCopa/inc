#include "game.h"

using namespace std;

Game::Game()
{
    try 
    {
        step("[Game] Trying to Construct.");

        m_system = new System();
        m_window = new Window();
        levelOne = new LevelOne();

        imageLoad = ImageLoad::getInstance();
        imageLoad->setRenderer(m_window->renderer());

        m_frontEnd = new FrontEnd();

        m_stack = NULL;
        exitstate[0] = false;
        exitstate[1] = false;

        addHandler(this);
        //m_input->addHandler(m_fade);
    } 
    catch (const string& e)
    {
        error(e);
        step("[Game] Destroying Manually.");

        free(m_stack);
        delete m_frontEnd;
        delete levelOne;
        delete m_window;
        delete m_system;
    }
}

Game::~Game()
{
    step("[Game] Destroying.");
    free(m_stack);
    delete m_frontEnd;
    delete levelOne;
    delete m_window;
    delete m_system;
}

void
Game::init()
{
    step("[Game] Using Init Method.");
    m_frontEnd->init();
    levelOne->init();
}

void
Game::shutdown()
{
    step("[Game] Using Shutdown Method.");
    levelOne->release();
    m_frontEnd->release();
    delete m_frontEnd;
    delete levelOne;
    delete m_window;
    delete m_system;
}

void
Game::run()
{
    step("[Game] Using Run Method.");
    m_frontEnd->drawEach();

    while ( !m_quit )
    {
        tick();
        eventLoop();
        if(beyondLimitsOfFPS())
        {
            levelOne->update();
            loop("[Game] Finished Updates");
            levelOne->draw();
            loop("[Game] Finished Draw");
            imageLoad->render();
            setLastToNow();
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
                case SDLK_LALT:
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
                case SDLK_LALT:
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
