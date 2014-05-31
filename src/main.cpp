#include <iostream>
#include "game.h"
#include "systemlogger.h"

using namespace systemLogger;

int main()
{
    setVerbosity(false,false,false,false,true);
    try 
    {
        step("[Main] Trying to Initialize Game.");
        Game* game = new Game();
        
        game->init();
        game->run();
        game->shutdown();
    } 
    catch (const string& e) 
    {
        error(e);
        return -1;
    }
    step("[Main] Exiting.");
	return 0;
}
