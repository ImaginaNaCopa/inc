#include "mainmenu.h"

MainMenu::MainMenu() : Menu("res/images/s_mainmenu.png")
{
	step("[MainMenu] Constructing.");
	m_background = new Background("res/images/s_mainmenu.png");
	generateClips();
	m_background->init();
}

MainMenu::~MainMenu()
{
	step("[MainMenu] Destroying.");
	delete m_background;
}

void
MainMenu::generateClips()
{
	step("[MainMenu] Generating Sprite Clips.");

	//addClip(350,650,230,20);
	//addClip(350,670,260,35);
	//addClip(350,705,160,30);
	//addClip(350,735,230,20);

	addClip(0,610,350,350);

	addClip(360,610,55,55);

	m_background->addClip(0,0,800,600);
	m_background->setClipNumber(0);
}

void
MainMenu::update()
{
	updateMouseMotion(m_mouse);
	m_mouseSelect = isCShooted();
	if(isCBackwarded())
	{
		falseCBackward();
		if(m_selection > 0)
			m_selection--;
		else
			m_selection = 3;
	}
	else if(isCForwarded())
	{
		falseCForward();
		if(m_selection < 3)
			m_selection++;
		else
			m_selection = 0;
	}
	else if(isCJumped())
	{
		falseCJump();
		m_select = true;
	}

	loop("[MainMenu] Updating and Drawing.");
	m_background->draw();

	m_clipNumber = 0;
	generatePosition(400,50,350,350);
	draw();

	/*m_clipNumber = 0;
	generatePosition(100,100,230,20);
	m_mouseCollision = checkCollision(0,getPosition());
	draw();*/

	/*m_clipNumber = 1;
	generatePosition(100,200,260,35);
	if(!m_mouseCollision)
		m_mouseCollision = checkCollision(1,getPosition());
	draw();*/

	/*m_clipNumber = 2;
	generatePosition(100,300,160,30);
	if(!m_mouseCollision)
		m_mouseCollision = checkCollision(2,getPosition());
	draw();*/

	/*m_clipNumber = 3;
	generatePosition(100,400,230,20);
	if(!m_mouseCollision)
		m_mouseCollision = checkCollision(3,getPosition());
	draw();*/

	if(isSelected())
	{
		step("[MainMenu] If selected an option, remove the InputHandler.");
		SDL_ShowCursor(0);
		setOver(true);
		switch(m_selection)
		{
			case 0:
				step("[MainMenu] Transitioning: Main Menu >>> Progression Menu.");
				setTimelineEvent(PROGRESSIONMENU);
			break;

			case 1:
				step("[MainMenu] Transitioning: Main Menu >>> Configuration Menu.");
				setTimelineEvent(CONFIGURATIONMENU);
			break;

			case 2:
				step("[MainMenu] Transitioning: Main Menu >>> Credits.");
				setTimelineEvent(CREDITS);
			break;

			case 3:
				step("[MainMenu] Transitioning: Main Menu >>> Exiting The Game.");
				iWantToQuit();
			break;

			default:
				step("[MainMenu] Transitioning: Main Menu >>> Progression Menu.");
				setTimelineEvent(PROGRESSIONMENU);
			break;
		}
	}
	else
	{
		loop("[MainMenu] If not selected an option, generate the Fleur-de-Lis.");
		m_clipNumber = 1;
		switch(m_selection)
		{
			case 0:
				generatePosition(40,80,50,50);
			break;

			case 1:
				generatePosition(40,190,50,50);
			break;

			case 2:
				generatePosition(40,290,50,50);
			break;

			case 3:
				generatePosition(40,380,50,50);
			break;

			default:
				generatePosition(40,80,50,50);
			break;
		}
		draw();
	}
}
