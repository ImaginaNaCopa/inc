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
	m_levelOne=NULL;
	m_levelTwo=NULL;
	m_levelThree=NULL;
	m_levelFour=NULL;
	m_levelFive=NULL;
	m_theEnd = NULL;
	m_gameOver = NULL;
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
	if(m_levelFive!=NULL)
		delete m_levelFive;
	if(m_levelFour!=NULL)
		delete m_levelFour;
	if(m_levelThree!=NULL)
		delete m_levelThree;
	if(m_levelTwo!=NULL)
		delete m_levelTwo;
	if(m_levelOne!=NULL)
		delete m_levelOne;
	if(m_configurationMenu!=NULL)
		delete m_configurationMenu;
	if(m_mainMenu!=NULL)
		delete m_mainMenu;
	if(m_frontEnd!=NULL)
		delete m_frontEnd;
	if(m_theEnd!=NULL)
		delete m_theEnd;
	if(m_gameOver!=NULL)
		delete m_gameOver;

	freeRenderer();
	delete m_window;
	delete m_system;
}

void
Game::run()
{
	// TODO: apagar a linha abaixo
	setTimelineEvent(LEVELFOUR);

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
							m_theEnd = new TheEnd();
							m_theEnd->init();
							setOver(false);
						}
						if(!isOver())
						{
							m_theEnd->update();
							m_theEnd->draw();
						}
						else
						{
							setTimelineEvent(LEVELONE);
							delete m_theEnd;
						}
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
							if(m_levelOne->isFinished())
								setTimelineEvent(LEVELTWO);
							if(m_levelOne->gameOver())
								setTimelineEvent(GAMEOVER);
							delete m_levelOne;
							m_levelOne = NULL;
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
							if(m_levelTwo->isFinished())
								setTimelineEvent(LEVELTHREE);
							if(m_levelTwo->gameOver())
								setTimelineEvent(GAMEOVER);
							delete m_levelTwo;
							m_levelTwo = NULL;
						}
					break;

					case LEVELTHREE:
						if(!isStarted())
						{
							m_levelThree = new LevelThree();
							m_levelThree->init();
							setOver(false);	
						}
						if(!isOver())
						{
							m_levelThree->update();
							m_levelThree->draw();
						}
						if(isOver())
						{
							if(m_levelThree->isFinished())
								setTimelineEvent(LEVELFOUR);
							if(m_levelThree->gameOver())
								setTimelineEvent(GAMEOVER);
							delete m_levelThree;
							m_levelThree = NULL;
						}
					break;

					case LEVELFOUR:
						if(!isStarted())
						{
							m_levelFour = new LevelFour();
							m_levelFour->init();
							setOver(false);	
						}
						if(!isOver())
						{
							m_levelFour->update();
							m_levelFour->draw();
							m_levelFour->drawExceptionalRelativeImages();
							m_levelFour->drawShadow();
							m_levelFour->drawHud();
						}
						if(isOver())
						{
							if(m_levelFour->isFinished())
								setTimelineEvent(LEVELFIVE);
							if(m_levelFour->gameOver())
								setTimelineEvent(GAMEOVER);
							delete m_levelFour;
							m_levelFour = NULL;
						}
					break;

					case LEVELFIVE:
						if(!isStarted())
						{
							m_levelFive = new LevelFive();
							m_levelFive->init();
							setOver(false);	
						}
						if(!isOver())
						{
							m_levelFive->update();
							m_levelFive->draw();
						}
						if(isOver())
						{
							if(m_levelFive->isFinished())
								setTimelineEvent(THEEND);
							if(m_levelFive->gameOver())
								setTimelineEvent(THEEND);
							delete m_levelFive;
							m_levelFive = NULL;
						}
					break;

					case THEEND:
						if(!isStarted())
						{
							m_theEnd = new TheEnd();
							m_theEnd->init();
							setOver(false);	
						}
						if(!isOver())
						{
							m_theEnd->update();
							m_theEnd->draw();
						}
						else
							delete m_frontEnd;
					break;

					case GAMEOVER:
						if(!isStarted())
						{
							m_gameOver = new GameOver();
							m_gameOver->init();
							setOver(false);
						}
						if(!isOver())
						{
							m_gameOver->update();
						}
						if(isOver())
						{
							setTimelineEvent(getLastTimelineEvent());
							delete m_gameOver;
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
	if(areTwoJoysticks())
		releaseJoystickTwo();
	if(isOneJoystick())
		releaseJoystickOne();
}