#include "theend.h"

TheEnd::TheEnd() : ImageEffect()
{
	step("[TheEnd] Constructing.");
	imagePath.assign("res/images/s_mainmenu.png");
	generatePosition(225,50,350,350);
	m_background = new Background("res/images/s_frontend.png");
	m_titulo = new Background("res/images/s_theend.png");
	m_nome = new Background("res/images/s_theend.png");
	m_background->init();
	m_titulo->init();
	m_nome->init();
	generateClips();

	m_use = false;
	m_return = false;
	m_skip = false;
	m_steps = TRYFORCE;
	m_stepsN = IAGO;
}

TheEnd::~TheEnd()
{
	step("[TheEnd] Destroying.");
	delete m_background;
	release();
}

void
TheEnd::generateClips()
{
	step("[TheEnd] Generating Sprite Clips.");
	addClip(0, 610, 350, 350);

	m_background->addClip(252,702,34,24);
	m_background->addClip(302,702,34,24);
	m_background->addClip(352,702,34,24);
	m_background->setOnlyClipNumber(1);

	m_titulo->addClip(0,0,195,21);
	m_titulo->addClip(220,0,60,22);
	m_titulo->addClip(300,0,144,22);
	m_titulo->addClip(450,0,63,22);
	m_titulo->addClip(520,0,60,22);
	m_titulo->addClip(590,0,137,22);
	m_titulo->addClip(0,250,42,26);
	m_titulo->addClip(50,250,300,26);

	m_nome->addClip(0,50,121,17);//iago
	m_nome->addClip(130,50,163,17);//jonathan
	m_nome->addClip(300,50,243,17);//luciano

	m_nome->addClip(270,100,75,17);//átilla
	m_nome->addClip(0,100,132,17);//Inara
	m_nome->addClip(150,100,95,17);//renata

	m_nome->addClip(0,150,91,17);//lucian

	m_nome->addClip(0,200,149,17);//carla
	m_nome->addClip(160,200,80,17);//edson
	m_nome->addClip(260,200,97,17);//renan
	m_nome->addClip(380,200,82,17);//tiago

	m_titulo->newFade();
}

void
TheEnd::update()
{
	loop("[TheEnd] Drawing if is not Over.");

	if(isCOpenedMenu())
	{
		if(!m_use)
		{
			m_use = true;
			m_skip = true;
			falseCOpenMenu();
		}
	}
	else
		m_use = false;

	switch(m_steps)
	{
		case TRYFORCE:
			loop("[TheEnd] Rendering Text for Tryforce.");
			m_background->draw();
			m_titulo->generatePosition(302,425,195,21);
			m_titulo->fade(15,120);
			m_titulo->draw();
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				m_titulo->setOnlyClipNumber(1);
				m_titulo->generatePosition(370,425,60,22);
				m_titulo->newFade();
				m_steps = EQUIPE;
			}
		break;
		case EQUIPE:
			loop("[TheEnd] Rendering Text for Equipe.");
			m_background->draw();
			m_titulo->fade(15,80);
			m_titulo->draw();
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				m_background->setOnlyClipNumber(2);
				m_titulo->setOnlyClipNumber(2);
				m_titulo->generatePosition(328,425,144,22);
				m_titulo->newFade();
				m_nome->generatePosition(340,500,121,17);
				m_nome->newFade();
				m_steps = PROGRAMADORES;
			}
		break;
		case PROGRAMADORES:
			loop("[TheEnd] Rendering Text for Programadores.");
			m_background->draw();
			m_titulo->fade(15,340);
			m_titulo->draw();
			m_nome->fade(15,80);
			m_nome->draw();
			if(m_nome->isFadeEnded() || m_skip)
			{	
				switch(m_stepsN)
				{
					case IAGO:
						m_nome->newFade();
						m_nome->setOnlyClipNumber(1);
						m_nome->generatePosition(319,500,163,17);
						m_stepsN = ARKYE;
						m_skip = false;
					break;

					case ARKYE:
						m_nome->newFade();
						m_nome->setOnlyClipNumber(2);
						m_nome->generatePosition(279,500,243,17);
						m_stepsN = LUCIANO;
						m_skip = false;
					break;
				}
			}
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				m_background->setOnlyClipNumber(0);
				m_titulo->setOnlyClipNumber(3);
				m_titulo->generatePosition(369,425,63,22);
				m_titulo->newFade();
				m_nome->newFade();
				m_nome->setOnlyClipNumber(3);
				m_nome->generatePosition(363,500,75,17);
				m_stepsN = ATILLA;
				m_steps = ARTISTAS;
			}
		break;
		case ARTISTAS:
			loop("[TheEnd] Rendering Text for Artistas.");
			m_background->draw();
			m_titulo->fade(15,340);
			m_titulo->draw();
			m_nome->fade(15,80);
			m_nome->draw();
			if(m_nome->isFadeEnded() || m_skip)
			{
				switch(m_stepsN)
				{
					case ATILLA:
						m_nome->newFade();
						m_nome->setOnlyClipNumber(4);
						m_nome->generatePosition(334,500,132,17);
						m_stepsN = INARA;
						m_skip = false;
					break;

					case INARA:
						m_nome->newFade();
						m_nome->setOnlyClipNumber(5);
						m_nome->generatePosition(353,500,95,17);
						m_stepsN = RENATA;
						m_skip = false;
					break;
				}
			}
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				m_background->setOnlyClipNumber(1);
				m_titulo->setOnlyClipNumber(4);
				m_titulo->generatePosition(370,425,60,22);
				m_titulo->newFade();
				m_nome->newFade();
				m_nome->setOnlyClipNumber(6);
				m_nome->generatePosition(353,500,95,17);
				m_stepsN = LUCIAN;
				m_steps = MUSICO;
			}
		break;
		case MUSICO:
			loop("[TheEnd] Rendering Text for Musicos.");
			m_background->draw();
			m_titulo->fade(15,80);
			m_titulo->draw();
			m_nome->fade(15,80);
			m_nome->draw();
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				m_background->setOnlyClipNumber(2);
				m_titulo->setOnlyClipNumber(5);
				m_titulo->generatePosition(332,425,137,22);
				m_titulo->newFade();
				m_nome->setOnlyClipNumber(7);
				m_nome->generatePosition(326,500,149,17);
				m_nome->newFade();
				m_stepsN = CARLA;
				m_steps = AGRADECIMENTOS;
			}
		break;
		case AGRADECIMENTOS:
			loop("[TheEnd] Rendering Text for Agradecimentos.");
			m_background->draw();
			m_titulo->fade(15,400);
			m_titulo->draw();
			m_nome->fade(15,80);
			m_nome->draw();
			if(m_nome->isFadeEnded() || m_skip)
			{
				switch(m_stepsN)
				{
					case CARLA:
						m_nome->newFade();
						m_nome->setOnlyClipNumber(8);
						m_nome->generatePosition(360,500,80,17);
						m_stepsN = EDSON;
						m_skip = false;
					break;

					case EDSON:
						m_nome->newFade();
						m_nome->setOnlyClipNumber(9);
						m_nome->generatePosition(352,500,97,17);
						m_stepsN = RENAN;
						m_skip = false;
					break;

					case RENAN:
						m_nome->newFade();
						m_nome->setOnlyClipNumber(10);
						m_nome->generatePosition(359,500,82,17);
						m_stepsN = TIAGO;
						m_skip = false;
					break;
				}
			}
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				m_background->setOnlyClipNumber(1);
				m_titulo->setOnlyClipNumber(6);
				m_titulo->generatePosition(379,425,42,26);
				m_titulo->newFade();
				m_steps = FIMDEJOGO;
			}
		break;
		
		case FIMDEJOGO:
			loop("[TheEnd] Rendering Text for FimDeJogo.");
			m_background->draw();
			m_titulo->fade(15,200);
			m_titulo->draw();
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				m_titulo->setOnlyClipNumber(7);
				m_titulo->generatePosition(250,425,300,26);
				m_titulo->newFade();
				m_steps = INIMIGOEOUTRO;
			}
		break;
		case INIMIGOEOUTRO:
			loop("[TheEnd] Rendering Text for FimDeJogo.");
			m_background->draw();
			m_titulo->fade(15,120);
			m_titulo->draw();
			if(m_titulo->isFadeEnded() || m_skip)
			{
				m_skip = false;
				setOver(true);
				setTimelineEvent(MAINMENU);
			}
		break;
		default:
		break;			
	}
}