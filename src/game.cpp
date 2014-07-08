#include "game.h"

using namespace std;

Game::Game()
{
	step("[Game] Constructing.");
	m_system = new System();
	m_window = new Window();
	setRenderer(m_window->renderer());

	m_frontEnd=NULL;
	m_mainMenu=NULL;
	m_configurationMenu=NULL;
	m_levelTwo=NULL;
}

Game::~Game()
{
	step("[Game] Destroying.");
	shutdown();
}

void
Game::shutdown()
{
	step("[Game] Using Shutdown Method.");
	if(m_levelTwo!=NULL)
		delete m_levelTwo;
	if(m_configurationMenu!=NULL)
		delete m_configurationMenu;
	if(m_mainMenu!=NULL)
		delete m_mainMenu;
	if(m_frontEnd!=NULL)
		delete m_frontEnd;

	freeRenderer();
	delete m_window;
	delete m_system;
}

void
Game::run()
{
	// TODO: apagar a linha abaixo
	setTimelineEvent(FRONTEND);

	step("[Game] Using Run Method.");
	while (!onQuit())
	{
		if(isCExit())
			iWantToQuit();
		else
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
						if(!isStarted())
						{
							m_frontEnd = new FrontEnd();
							m_frontEnd->init();
							setOver(false);
						}
						if(!isOver())
							m_frontEnd->update();
						else
							delete m_frontEnd;
					break;

					case MAINMENU:
						if(!isStarted())
						{
							m_mainMenu = new MainMenu();
							m_mainMenu->init();
							setOver(false);
						}
						if(!isOver())
							m_mainMenu->update();
						else
							delete m_mainMenu;
					break;

					case PROGRESSIONMENU:
						if(!isStarted())
						{
							//m_progressionMenu = new ProgressionMenu();
							//m_progressionMenu->init();
							setOver(true);
						}
							setTimelineEvent(LEVELONE);
					break;

					case CONFIGURATIONMENU:
						if(!isStarted())
						{
							m_configurationMenu = new ConfigurationMenu();
							m_configurationMenu->init();
							setOver(false);	
						}
						if(!isOver())
							m_configurationMenu->update();
						else
							delete m_configurationMenu;
					break;

					case CREDITS:
						if(!isStarted())
						{
							//m_credits = new Credits();
							//m_credits->init();
							setOver(true);
						}
						setTimelineEvent(LEVELONE);
					break;

					case LEVELONE:
						if(!isStarted())
						{
							m_levelOne = new LevelOne();
							m_levelOne->init();
							setOver(false);	
						}
						if(!isOver())
						{
							m_levelOne->update();
							m_levelOne->draw();
						}
						if(isOver())
						{
							delete m_levelOne;
							if(m_levelOne->isFinished())
								setTimelineEvent(LEVELTWO);
							if(m_levelOne->gameOver())
								setTimelineEvent(LEVELONE);
						}
					break;

					case LEVELTWO:
						if(!isStarted())
						{
							m_levelTwo = new LevelTwo();
							m_levelTwo->init();
							setOver(false);	
						}
						if(!isOver())
						{
							m_levelTwo->update();
							m_levelTwo->draw();
						}
						if(isOver())
						{
							delete m_levelTwo;
							if(m_levelTwo->isFinished())
								setTimelineEvent(MAINMENU);
							if(m_levelTwo->gameOver())
								setTimelineEvent(LEVELTWO);
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
}