#include "theend.h"

TheEnd::TheEnd() : ImageEffect()
{
	step("[TheEnd] Constructing.");
	background = new Background("res/images/s_mainmenu.png");
	imagePath.assign("res/images/s_theend.png");
	//generatePosition(0,0,195,21);
	generateClips();
	background->init();
	background->generatePosition(225, 50, 350, 350);
	background->addClip(0, 610, 350, 350);
	m_use = false;
	m_return = false;
	m_steps = TRYFORCE;
	m_skip = false;
}

TheEnd::~TheEnd()
{
	step("[TheEnd] Destroying.");
	delete background;
	release();
}

void
TheEnd::generateClips()
{
	step("[TheEnd] Generating Sprite Clips.");
	addClip(0,0,195,21);
	addClip(220,0,60,22);
	addClip(300,0,144,22);
	addClip(450,0,63,22);
	addClip(520,0,60,22);
	addClip(590,0,137,22);
	addClip(0,250,42,26);
	addClip(50,250,300,26);

	addClip(0,50,121,17);//iago
	this->generatePosition(340,500,121,17);
	addClip(130,50,163,17);//jonathan
	this->generatePosition(370,425,60,22);
	addClip(300,50,243,17);//luciano
	this->generatePosition(370,425,60,22);

	addClip(270,100,75,17);//átilla
	this->generatePosition(370,425,60,22);
	addClip(100,100,132,17);//Inara
	this->generatePosition(370,425,60,22);
	addClip(150,100,95,17);//renata
	this->generatePosition(370,425,60,22);

	addClip(0,150,91,17);//lucian
	this->generatePosition(370,425,60,22);

	addClip(0,200,149,17);//carla
	this->generatePosition(370,425,60,22);
	addClip(160,200,80,17);//edson
	this->generatePosition(370,425,60,22);
	addClip(260,200,97,17);//renan
	this->generatePosition(370,425,60,22);
	addClip(380,200,82,17);//tiago
	this->generatePosition(370,425,60,22);

	this->newFade();
}

void
TheEnd::update()
{
	loop("[TheEnd] Drawing if is not Over.");
	background->draw();

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
			this->generatePosition(302,425,195,21);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(1);
				this->generatePosition(370,425,60,22);
				this->fade(15,80);
				m_steps = EQUIPE;
			}
		break;
		case EQUIPE:
			loop("[TheEnd] Rendering Text for Equipe.");
			this->generatePosition(370,425,60,22);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(2);
				this->generatePosition(328,425,144,22);
				this->fade(15,80);
				m_steps = PROGRAMADORES;
			}
		break;
		case PROGRAMADORES:
			loop("[TheEnd] Rendering Text for Programadores.");
			this->generatePosition(328,425,144,22);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(3);
				this->generatePosition(369,425,63,22);
				this->fade(15,80);
				m_steps = ARTISTAS;
			}
		break;
		case ARTISTAS:
			loop("[TheEnd] Rendering Text for Artistas.");
			this->generatePosition(369,425,63,22);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(4);
				this->generatePosition(370,425,60,22);
				this->fade(15,80);
				m_steps = MUSICO;
			}
		break;
		case MUSICO:
			loop("[TheEnd] Rendering Text for Musicos.");
			this->generatePosition(370,425,60,22);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(5);
				this->generatePosition(332,425,137,22);
				this->fade(15,80);
				m_steps = AGRADECIMENTOS;
			}
		break;
		case AGRADECIMENTOS:
			loop("[TheEnd] Rendering Text for Agradecimentos.");
			this->generatePosition(332,425,137,22);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(6);
				this->generatePosition(379,425,42,26);
				this->fade(15,80);
				m_steps = FIMDEJOGO;
			}
		break;
		
		case FIMDEJOGO:
			loop("[TheEnd] Rendering Text for FimDeJogo.");
			this->generatePosition(379,425,42,26);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(7);
				this->generatePosition(250,425,300,26);
				this->fade(15,80);
				m_steps = INIMIGOEOUTRO;
			}
		break;
		case INIMIGOEOUTRO:
			loop("[TheEnd] Rendering Text for FimDeJogo.");
			this->generatePosition(250,425,300,26);
			this->fade(15, 80);
			if(isFadeEnded() || m_skip)
			{
				m_skip = false;
				falseCOpenMenu();
				this->newFade();
				this->setOnlyClipNumber(0);
				this->generatePosition(370,425,60,22);
				this->fade(15,80);
				setTimelineEvent(MAINMENU);
			}
		break;
		default:
		break;			
	}
}