#include "civil.h"
#include <iostream>

using namespace std;

Civil::Civil(int item, int tipo, int earlyPosition) : ImageEffect()
{
	step("[Civil] Constructing.");
	imagePath.assign("res/images/s_civil.png"); 
	m_tipo = tipo;
	switch(m_tipo)
	{
		case 0:
			generatePosition(earlyPosition,(getPlatformH()-45),54,45);
			generateClips();
		break;
		case 1:
			generatePosition(earlyPosition,(getPlatformH()-35),64,50);
			generateClips();
		break;
		case 2:
			generatePosition(earlyPosition,(getPlatformH()-40),66,53);
			generateClips();
		break;
		case 3:
			generatePosition(earlyPosition,(getPlatformH()-30),64,52);
			generateClips();
		break;
		case 4:
			generatePosition(earlyPosition,(getPlatformH()-45),46,55);
			generateClips();
		break;
		case 5:
			generatePosition(earlyPosition,(getPlatformH()-28),62,48);
			generateClips();
		break;
		default:
		break;
	}
	gotUp = false;
	m_item = item;
	m_safe = false;
	m_runned = false;
	m_state = GROUNDED;
	m_times = 0;
}

Civil::~Civil()
{
	step("[Civil] Destroying.");
}

void
Civil::generateClips()
{
	switch (m_tipo)
	{
		case 0:
			step("[Civil] Adding Clips.");
			addClip(0,0,54,45);//0civil um caido
			addClip(54,0,52,51);//levantando
			addClip(106,0,45,55);
			addClip(151,0,45,57);
			addClip(196,0,45,57);
			addClip(241,0,45,56);//5
			setClipNumber(0);
		break;
		case 1:
			step("[Civil] Adding Clips.");
			addClip(286,0,64,50);//6 civil 2
			addClip(350,0,48,66);
			setClipNumber(0);
		break;
		case 2:
			step("[Civil] Adding Clips.");
			addClip(0,80,66,53);//8caido
			addClip(66,80,52,62);//caido
			addClip(118,80,52,64);//corre
			addClip(170,80,52,66);
			addClip(222,80,52,65);
			addClip(274,80,52,66);//13
			setClipNumber(0);
		break;
		case 3:
			step("[Civil] Adding Clips.");
			addClip(0,160,64,52);//14caido
			addClip(64,160,58,63);//levanta
			addClip(122,160,56,64);//parado
			addClip(178,160,50,69);//olhapra cima
			addClip(228,160,56,64);//18costas
			setClipNumber(0);
		break;
		case 4:
			step("[Civil] Adding Clips.");
			addClip(0,240,46,55);//19
			addClip(46,240,46,55);
			addClip(92,240,46,58);
			addClip(138,240,45,57);
			addClip(183,240,45,56);//23
			setClipNumber(0);
		break;
		case 5:
			step("[Civil] Adding Clips.");
			addClip(0,320,62,48);//24caido
			addClip(62,320,49,60);//levantado
			addClip(111,320,50,62);//26correndo
			addClip(161,320,50,64);//correndo
			addClip(211,320,51,65);//correndo
			addClip(262,320,51,64);//29tropeça
			addClip(313,320,64,51);//tropeça
			addClip(377,320,56,39);//31tropeça
			setClipNumber(0);
		break;
		default:
		break;
	}
}

int
Civil::calculatePosition(int direction)
{
	loop("[Civil] Updating Position in Horizontal axis.");
	return round(((100*getDelta())/1000.0)*direction);
}

void
Civil::update()
{
	loop("[Civil] Updating State.");
	switch (m_state)
	{
		case GROUNDED:
			grounded();
		break;
		case MOVING:
			moving();
		break;
		case STOPED:
			stoped();
		break;
	}
}

void
Civil::grounded()
{
	loop("[Civil] Updating Position.");
	if (isSafe())
	{
		if (isSafe() && !gotUp)
		{
			setClipNumber(1);
			gotUp = true;
			m_state = MOVING;
			if (m_tipo == 1)
				m_position.y -= 15;
			if (m_tipo == 2)
				m_position.y -= 13;
			if (m_tipo == 3)
				m_position.y -= 22;
			if (m_tipo == 4)
				m_position.y -= 10;
			if (m_tipo == 5)
				m_position.y -= 20;
		}
	}
}

void
Civil::moving()
{
	m_safe = true;
	switch(m_tipo)
	{
		case 0:
			civilOneMove();
		break;
		case 1:
			civilTwoMove();
		break;
		case 2:
			civilThreeMove();
		break;
		case 3:
			civilFourMove();
		break;
		case 4:
			civilFiveMove();
		break;
		case 5:
			civilSixMove();
		break;
		default:
		break;
	}
}

void
Civil::civilOneMove()
{
	if(getCurrentIdleTime() == 3)
	{		
		if(m_clipNumber==2)
			setClipNumber(3);
		else if(m_clipNumber==3)
			setClipNumber(4);
		else if(m_clipNumber==4)
			setClipNumber(5);
		else
			setClipNumber(2);

		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);

	m_position.x += calculatePosition(-1);

	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

void
Civil::civilTwoMove()
{
	if(getCurrentIdleTime() == 3)
	{		
		if(getCurrentIdleTime()%2 == 0)
			m_position.y += 5;
		else if(getCurrentIdleTime()%2 == 1)
			m_position.y -= 5;

		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);

	m_position.x += calculatePosition(-1);

	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

void
Civil::civilThreeMove()
{
	if(getCurrentIdleTime() == 3)
	{		
		if(m_clipNumber==2)
			setClipNumber(3);
		else if(m_clipNumber==3)
			setClipNumber(4);
		else if(m_clipNumber==4)
			setClipNumber(5);
		else
			setClipNumber(2);

		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);

	m_position.x += calculatePosition(-1);

	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

void
Civil::civilFourMove()
{
	if(getCurrentIdleTime() == 20)
	{		
		setClipNumber(2);
		m_state = STOPED;
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);


	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

void
Civil::civilFiveMove()
{
	if(getCurrentIdleTime() == 3)
	{		
		if(m_clipNumber==2)
			setClipNumber(3);
		else if(m_clipNumber==3)
			setClipNumber(4);
		else
			setClipNumber(2);

		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);

	m_position.x += calculatePosition(-1);

	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

void
Civil::civilSixMove()
{
	defineCurrentIdleTime(0);
	if(getCurrentIdleTime() == 3)
	{		
		if(m_clipNumber==2)
			setClipNumber(3);
		else if(m_clipNumber==3)
			setClipNumber(4);
		else
			setClipNumber(2);
	
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);

	if (m_clipNumber == 4)
		m_state = STOPED;

	m_position.x += calculatePosition(1);

	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

void
Civil::stoped()
{
	if (m_tipo == 3)
		stopedCivilFour();
	if (m_tipo == 5)
		stopedCivilSix();
}

void
Civil::stopedCivilFour()
{
	if(getCurrentIdleTime() == 100)
	{	
		if (m_clipNumber == 2)
		{	
			m_position.x -= 10;
			setClipNumber(3);
		}
		else if (m_clipNumber == 3)
		{
			m_position.x += 8;
			setClipNumber(4);
		}
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);

	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

void
Civil::stopedCivilSix()
{
	if(getCurrentIdleTime() == 3 && m_clipNumber != 7)
	{	
		if(m_clipNumber==2)
			setClipNumber(3);
		else if(m_clipNumber==3)
			setClipNumber(4);
		else if(m_clipNumber==4)
			setClipNumber(5);	
		else if(m_clipNumber==5)
			setClipNumber(6);
		else if(m_clipNumber==6)
			setClipNumber(7);
		else
			setClipNumber(2);

		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
		
	if (m_clipNumber != 7)
		m_position.x += calculatePosition(1);

	if(!ifCollided(0, getPosition(), getCameraRange()))
		m_runned = true;
}

int
Civil::getItem()
{
	return m_item;
}

bool
Civil::isSafe()
{
	return m_safe;
}

void
Civil::saved()
{
	m_safe = true;
}

bool
Civil::isRunned()
{
	return m_runned;
}

int
Civil::getTipo()
{
	return m_tipo;
}