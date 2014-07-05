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
//		setTimelineEvent(3);

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
				case 0:
					if(!isOver())
					{
						loop("[Game] Its on Front End, ladies and gentlemans!");
						m_frontEnd->update();
					}
					else
					{
						step("[Game] Transitioning: Front End >>> Main Menu.");
						setTimelineEvent(1);						
					}
				break;
				case 1:
					loop("[Game] Its on Main Menu, ladies and gentlemans!");
					m_mainMenu->update();
				break;

				case 2:
					loop("[Game] Its on Progression Menu, ladies and gentlemans!");
					step("[Game] Transitioning: Progression Menu >>> Level One.");
					setTimelineEvent(3);
				break;

				case 3:
					if(!isOver())
					{
						loop("[Game] Its on #VAMO PRA RUA, ladies and gentlemans!");
						m_levelOne->update();
						m_levelOne->draw();
					}
					else
					{
						if (m_levelOne->isFinished())
						{
							cout << "mudando de fase" << endl;
							setOver(false);
							setTimelineEvent(1);					
							delete m_mainMenu;
							m_mainMenu = new MainMenu();
							m_mainMenu->init();
							delete m_levelOne;
							m_levelOne = new LevelOne();
							m_levelOne->init();		
						} 
						else if (m_levelOne->gameOver())
						{
							delete m_levelOne;
							m_levelOne = new LevelOne();
							m_levelOne->init();
							setOver(false);
						}
					}
				break;

				case 10:
					loop("[Game] Its on Configuration Menu, ladies and gentlemans!");
					m_configurationMenu->update();
				break;

				case 20:
					loop("[Game] Its on Credits, ladies and gentlemans!");
						step("[Game] Transitioning: Credits >>> Level One.");
					setTimelineEvent(3);
				break;									

				default:
				break;				
			}
			loop("[Game] Rendering Everything.");
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
