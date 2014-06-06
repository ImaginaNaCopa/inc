#ifndef GAME_H
#define GAME_H

#include "frontend.h"
#include "imageload.h"
#include "input.h"
#include "mainmenu.h"
#include "levelone.h"
#include "system.h"
#include "timer.h"
#include "window.h"

using namespace input;
using namespace timer;

class Game : public InputHandler
{
public:
    Game();
    ~Game();

    void init();
    void run();
    void shutdown();
    
    bool handle(SDL_Event &event);

private:
    bool m_exitstate[2];

    FrontEnd* m_frontEnd;

    MainMenu* m_mainMenu;

    LevelOne* m_levelOne;

    ImageLoad* imageLoad;
    System *m_system;
    Window *m_window;
};

#endif // GAME_H
