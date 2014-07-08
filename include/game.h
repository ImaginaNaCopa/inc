#ifndef GAME_H
#define GAME_H

#include "configurationmenu.h"
#include "controls.h"
#include "frontend.h"
#include "imageload.h"
#include "mainmenu.h"
#include "levelone.h"
#include "leveltwo.h"
#include "system.h"
#include "timer.h"
#include "window.h"

using namespace controls;
using namespace timer;
using namespace imageLoad;

class Game
{
public:
	Game();
	~Game();

	void run();
	void shutdown();
	
private:
	FrontEnd* m_frontEnd;

	MainMenu* m_mainMenu;

	ConfigurationMenu* m_configurationMenu;

	LevelOne* m_levelOne;
	LevelTwo* m_levelTwo;

	System* m_system;
	Window* m_window;
};

#endif // GAME_H
