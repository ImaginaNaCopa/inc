#include <iostream>
#include "../include/game.h"
#include "../include/systemlogger.h"

using namespace systemLogger;

int main()
{
	setVerbosity(0,0,0,0,0,1);
	try 
	{
		//step("[Main] Trying to Initialize Game.");
		Game* game = new Game();
		
		game->run();
		game->shutdown();
	} 
	catch (const string& e) 
	{
		error(e);
		return -1;
	}
	//step("[Main] Exiting.");
	return 0;
}