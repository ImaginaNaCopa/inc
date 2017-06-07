#ifndef GAME_H
#define GAME_H

#include "../include/configurationmenu.h"
#include "../include/audiohandler.h"
#include "../include/controls.h"
#include "../include/frontend.h"
#include "../include/imageload.h"
#include "../include/mainmenu.h"
#include "../include/levelone.h"
#include "../include/leveltwo.h"
#include "../include/levelthree.h"
#include "../include/levelfour.h"
#include "../include/levelfive.h"
#include "../include/theend.h"
#include "../include/gameover.h"
#include "../include/system.h"
#include "../include/timer.h"
#include "../include/window.h"

using namespace controls;
using namespace timer;
using namespace imageLoad;
using namespace audioHandler;

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
	LevelThree* m_levelThree;
	LevelFour* m_levelFour;
	LevelFive* m_levelFive;
	TheEnd* m_theEnd;
	GameOver* m_gameOver;

	System* m_system;
	Window* m_window;
};

#endif // GAME_H
