#include "mainmenu.h"

MainMenu::MainMenu() : Menu("res/images/s_mainmenu.png")
{
	step("[MainMenu] Constructing.");
	m_background = new Background("res/images/s_mainmenu.png");
	generateClips();
	addHandler(this);
	m_background->init();
}

MainMenu::~MainMenu()
{
	step("[MainMenu] Destroying.");
	release();
	delete m_background;
}

void
MainMenu::generateClips()
{
	step("[MainMenu] Generating Sprite Clips.");

	addClip(350,650,230,20);
	addClip(350,670,260,35);
	addClip(350,705,160,30);
	addClip(350,735,230,20);

	addClip(0,600,350,350);

	addClip(350,600,50,50);

	m_background->addClip(0,0,800,600);
}

void
MainMenu::update()
{
	loop("[MainMenu] Updating and Drawing.");
	m_background->setClipNumber(0);
	m_background->draw();

	m_clipNumber = 4;
	generatePosition(400,50,350,350);
	draw();

	m_clipNumber = 0;
	generatePosition(100,100,230,20);
	m_mouseCollision = checkCollision(0,getPosition());
	draw();

	m_clipNumber = 1;
	generatePosition(100,200,260,35);
	if(!m_mouseCollision)
		m_mouseCollision = checkCollision(1,getPosition());
	draw();

	m_clipNumber = 2;
	generatePosition(100,300,160,30);
	if(!m_mouseCollision)
		m_mouseCollision = checkCollision(2,getPosition());
	draw();

	m_clipNumber = 3;
	generatePosition(100,400,230,20);
	if(!m_mouseCollision)
		m_mouseCollision = checkCollision(3,getPosition());
	draw();

	if(isSelected())
	{
		step("[MainMenu] If selected an option, remove the InputHandler.");
		SDL_ShowCursor(0);
		removeHandler(this);
		setOver(true);
		switch(m_selection)
		{
			case 0:
				step("[MainMenu] Transitioning: Main Menu >>> Progression Menu.");
				setTimelineEvent(2);
			break;

			case 1:
				step("[MainMenu] Transitioning: Main Menu >>> Configuration Menu.");
				setTimelineEvent(10);
			break;

			case 2:
				step("[MainMenu] Transitioning: Main Menu >>> Credits.");
				setTimelineEvent(20);
			break;

			case 3:
				step("[MainMenu] Transitioning: Main Menu >>> Exiting The Game.");
				iWantToQuit();
			break;

			default:
				step("[MainMenu] Transitioning: Main Menu >>> Progression Menu.");
				setTimelineEvent(2);
			break;
		}
	}
	else
	{
		loop("[MainMenu] If not selected an option, generate the Fleur-de-Lis.");
		m_clipNumber = 5;
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

bool 
MainMenu::handle(SDL_Event& event)
{
	loop("[MainMenu] Handling Events.");
	bool processed = false;
	switch (event.type)
	{

		case SDL_MOUSEMOTION:
			controls(0,"[MainMenu] MouseMotion.");
			m_mouse.x = event.motion.x;
			m_mouse.y = event.motion.y;
			processed = true;
		break;

		case SDL_MOUSEBUTTONDOWN:
			controls(0,"[MainMenu] MouseButtonDown.");
		   	m_mouseSelect = true;
			processed = true;
		break;

		case SDL_MOUSEBUTTONUP:
			controls(0,"[MainMenu] MouseButtonUp.");
			processed = true;
		break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					controls(1,"[MainMenu] Button a Down.");
					processed = true;
					if(m_selection > 0)
						m_selection--;
					else
						m_selection = 3;
				break;
				case SDLK_d:
					controls(1,"[MainMenu] Button d Down.");
					processed = true;
					if(m_selection<3)
						m_selection++;
					else
						m_selection = 0;
				break;
				case SDLK_SPACE:
					controls(1,"[MainMenu] Button SPACE Down.");
					m_select = true;				
					processed = true;
				break;				
				default:
				break;
			}
		break;

		case SDL_KEYUP:
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					controls(1,"[MainMenu] Button a Up.");
					processed = true;
				break;
				case SDLK_d:
					controls(1,"[MainMenu] Button d Up.");
					processed = true;
				break;		   
				case SDLK_SPACE:
					controls(1,"[MainMenu] Button SPACE Up.");
					processed = true;
				break;
				default:
				break;
			}
		break;

		default:
		break;
	}
	return processed;
}