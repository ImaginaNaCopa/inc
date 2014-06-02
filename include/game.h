#ifndef GAME_H
#define GAME_H

#include "frontend.h"
#include "imageload.h"
#include "input.h"
#include "levelone.h"
#include "system.h"
#include "window.h"
#include "timer.h"

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
    LevelOne* levelOne;
    FrontEnd* m_frontEnd;
    ImageLoad* imageLoad;

    System *m_system;
    Window *m_window;

    bool exitstate[2];

    bool m_quit;
};

#endif // GAME_H
