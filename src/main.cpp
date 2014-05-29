#include <iostream>
#include "game.h"
#include "systemlogger.h"

using namespace std;

int main()
{
    SystemLogger::isStepVerbose = true;
    try 
    {
        SystemLogger::step("[Main] Trying to Initialize Game.");
        Game* game = new Game();
        
        game->init();
        game->run();
        game->shutdown();
    } 
    catch (const string& e) 
    {
        SystemLogger::error(e);
        return -1;
    }
    SystemLogger::step("[Main] Exiting.");
	return 0;
}
