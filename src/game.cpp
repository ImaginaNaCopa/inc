#include "game.h"

using namespace std;

Game::Game()
{
	step("[Game] Constructing.");
	m_system = new System();

	m_window = new Window();
	setRenderer(m_window->renderer());

	m_frontEnd = new FrontEnd();

	m_mainMenu = new MainMenu();

	m_configurationMenu = new ConfigurationMenu();

	m_levelOne = new LevelOne();

	m_exitstate[0] = false;
	m_exitstate[1] = false;
	released = false;

	addHandler(this);
}

Game::~Game()
{
	step("[Game] Destroying.");
	shutdown();
}

void
Game::init()
{
	step("[Game] Using Init Method.");
	m_frontEnd->init();

	m_mainMenu->init();

	//m_configurationMenu->init();

	m_levelOne->init();
}

void
Game::shutdown()
{
	step("[Game] Using Shutdown Method.");
	delete m_levelOne;

	delete m_configurationMenu;

	delete m_mainMenu;

	delete m_frontEnd;

	freeRenderer();
	delete m_window;
	delete m_system;
}

void
Game::run()
{
	// TODO: apagar a linha abaixo
	setTimelineEvent(MAINMENU);

	step("[Game] Using Run Method.");
	while ( !onQuit() )
	{
		loop("[Game] Starting a New Loop");
		tick();
		eventLoop();

		if(isBeyondLimitsOfFPS())
		{
			loop("[Game] Plot of Events.");
			switch(getTimelineEvent())
			{
				case FRONTEND:
					m_frontEnd->update();
				break;

				case MAINMENU:
					m_mainMenu->update();
				break;

				case PROGRESSIONMENU:
					setTimelineEvent(LEVELONE);
				break;

				case CONFIGURATIONMENU:
					m_configurationMenu->update();
				break;

				case CREDITS:
					setTimelineEvent(LEVELONE);
				break;

				case LEVELONE:
					m_levelOne->update();
					m_levelOne->draw();
					if (m_levelOne->isFinished())
					{
						delete m_mainMenu;
						m_mainMenu = new MainMenu();
						m_mainMenu->init();
						delete m_levelOne;
						m_levelOne = new LevelOne();
						m_levelOne->init();		
						setTimelineEvent(MAINMENU);
					} 
					else if (m_levelOne->gameOver())
					{
						setOver(false);
						delete m_levelOne;
						m_levelOne = new LevelOne();
						m_levelOne->init();
					}
				break;					

				default:
				break;				
			}
			if(!isOver())
				render();
			setLastToNow();
		}
	}
}

bool 
Game::handle(SDL_Event &event)
{
	loop("[Game] Handling Events.");
	bool processed = false;	
	if (event.type == SDL_QUIT)
	{
		iWantToQuit();
	}
	switch (event.type)
	{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_LALT:
					controls(1,"[Game] Button Left ALT Down.");
					m_exitstate[0] = true;
					processed = true;
				break;
				case SDLK_q:
					controls(1,"[Game] Button q Down.");
					m_exitstate[1] = true;
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
					controls(1,"[Game] Button Left ALT Up.");
					m_exitstate[0] = false;
					processed = true;
				break;
				case SDLK_q:
					controls(1,"[Game] Button q Up.");
					m_exitstate[1] = false;
					processed = true;
				break;
				default:
				break;
			}
		break;

		default:
		break;
	}
	
	if (m_exitstate[0] == true && m_exitstate[1] == true)
	{
		step("[Game] Player used the Secret Code to Quit the Game.");
		iWantToQuit();
	}

	return processed;
}
