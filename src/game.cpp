#include "game.h"

using namespace std;

Game::Game()
{
    step("[Game] Trying to Construct.");

    m_system = new System();
    m_window = new Window();
    imageLoad = ImageLoad::getInstance();
    imageLoad->setRenderer(m_window->renderer());

    m_frontEnd = new FrontEnd();
    levelOne = new LevelOne();

    exitstate[0] = false;
    exitstate[1] = false;

    addHandler(this);
    //m_input->addHandler(m_fade);
}

Game::~Game()
{
    step("[Game] Destroying.");
    delete levelOne;
    delete m_frontEnd;
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
    while ( !m_quit )
    {
        tick();
        eventLoop();
        if(isBeyondLimitsOfFPS())
        {
            switch(getTimelineEvent())
            {
                case 0: // FRONT END
                    if(!m_frontEnd->isOver())
                    {
                        m_frontEnd->update();
                        m_frontEnd->draw();
                    }
                    else
                        setTimelineEvent(1);
                break;
                case 1: // MAIN MENU
                    setTimelineEvent(2);
                break;

                case 2: // PROGRESSION MENU
                    setTimelineEvent(3);
                break;

                case 3: // LEVEL ONE
                    if(!levelOne->isOver())
                    {
                        levelOne->update();
                        levelOne->draw();                        
                    }
                    else
                        m_quit = true;
                break;

                default:
                break;                
            }
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
