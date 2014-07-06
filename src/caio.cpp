#include "caio.h"

#include <iostream>
using namespace std;

Caio::Caio() : ImageEffect()
{
	step("[Caio] Constructing.");

	imagePath.assign("res/images/s_caio.png");
	generatePosition(round(getWindowW()/16),getPlatformH(),48,55);
	generateClips();
	generateDefaultStats();
	newVariousIdleTimes(2);
}

Caio::~Caio()
{
	step("[Caio] Destroying.");
	release();
}

void
Caio::generateClips()
{
	step("[Caio] Generating Sprite Clips.");
	addClip(0,0,48,55);
	addClip(48,0,48,57);
	addClip(96,0,48,56);
	addClip(144,0,48,57);

	addClip(0,60,48,55);
	addClip(48,60,48,57);
	addClip(96,60,48,56);
	addClip(144,60,48,57);

	addClip(0,120,48,55);
	addClip(48,120,48,58);
	addClip(96,120,48,58);
	addClip(144,120,48,63);

	addClip(0,185,48,55);
	addClip(48,185,48,58);
	addClip(96,185,48,58);
	addClip(144,185,48,63);

	addClip(0,250,48,55);
	addClip(48,250,51,51);
	addClip(99,250,53,36);
	addClip(152,250,50,31);

	addClip(0,310,48,55);
	addClip(48,310,51,51);
	addClip(99,310,53,36);
	addClip(152,310,50,31);
}

void
Caio::generateDefaultStats()
{
	m_dx = 0;
	m_speed = haveQuicklySpeed();
	m_jumpspeed = 10;

	m_health = 3;
	m_maxHealth = 3;
	m_dead = false;
	m_imune = false;

	m_state = STANDING;
	m_looking = FORWARD;
	m_useItem = NOUSE;

	m_aPressed = false;
	m_sPressed = false;
	m_dPressed = false;
	m_spacePressed = false;

	m_itemUsed = 0;
	m_keyItemUnpressed = false;
	m_use = true;

	m_onePressed = false;
	m_twoPressed = false;
	m_threePressed = false;
	m_fivePressed = false;
	m_sixPressed = false;
}

void
Caio::update()
{
	loop("[Caio] Updating.");

	switch (m_state)
	{
		case STANDING:
			stand();
		break;

		case MOVING:
			move();
		break;
	
		case JUMPING:
			jump();
		break;

		case CROUCHING:
			crouch();
		break;
	}

	if(m_position.y > getPlatformH() - m_position.h)
		m_position.y = getPlatformH() - m_position.h;

	handleItens();
}

bool
Caio::overEnemy(SDL_Rect rect)
{
	loop("[Caio] Checking if Collided with a Rectangle.");
	if(ifCollided(1,getPosition(),rect))
	{
		condition("[Caio] Collided on left side.");
		m_position.x -= 10;
		return true;
	}
	else if(ifCollided(2,getPosition(),rect))
	{
		condition("[Caio] Collided on right side.");
		m_position.x += 10;
		return true;
	}
	return false;
}

bool
Caio::overItem(SDL_Rect rect)
{
	loop("[Caio] Checking if Collided with an Item Rectangle.");
	if(ifCollided(1,getPosition(),rect))
	{
		condition("[Caio] Collided on left side.");
		return true;
	}
	else if(ifCollided(2,getPosition(),rect))
	{
		condition("[Caio] Collided on right side.");
		return true;
	}
	return false;
}

bool 
Caio::handle(SDL_Event& event)
{
	loop("[Caio] Handling Events.");
	int type = event.type;

	if (type != SDL_KEYDOWN && type != SDL_KEYUP)
		return false;

	SDL_Keycode sym = event.key.keysym.sym;

	switch (sym)
	{
		case SDLK_a:
			m_aPressed = type == SDL_KEYDOWN ? true : false;
		break;

		case SDLK_s:
			m_sPressed = type == SDL_KEYDOWN ? true : false;
		break;

		case SDLK_d:
			m_dPressed = type == SDL_KEYDOWN ? true : false;
		break;

		case SDLK_SPACE:
			m_spacePressed = type == SDL_KEYDOWN ? true : false;
		break;

		case SDLK_1:
			m_onePressed = type == SDL_KEYDOWN ? true : false;
			m_keyItemUnpressed = type == SDL_KEYUP ? true : false;
		break;

		case SDLK_2:
			m_twoPressed = type == SDL_KEYDOWN ? true : false;
			m_keyItemUnpressed = type == SDL_KEYUP ? true : false;
		break; 

		case SDLK_3:
			m_threePressed = type == SDL_KEYDOWN ? true : false;
			m_keyItemUnpressed = type == SDL_KEYUP ? true : false;
		break;

		case SDLK_5:
			m_fivePressed = type == SDL_KEYDOWN ? true : false;
			m_keyItemUnpressed = type == SDL_KEYUP ? true : false;
		break;

		case SDLK_6:
			m_sixPressed = type == SDL_KEYDOWN ? true : false;
			m_keyItemUnpressed = type == SDL_KEYUP ? true : false;
		break;

		default:
			return false;
		break;
	}
	return true;	
}

void
Caio::handleItens()
{

	if(m_use)
	{
		if(m_onePressed)
			m_useItem = ENERGYTONIC;
		else if(m_twoPressed)
			m_useItem = ALTEREDTONIC;
		else if(m_threePressed)
			m_useItem = ANTIALL;
		else if(m_fivePressed)
			m_useItem = FREEBOIMEAT;
		else if(m_sixPressed)
			m_useItem = IMAGINANACOPA;
		else
			m_useItem = NOUSE;		
	}

	if(!m_keyItemUnpressed)
	{
		switch(m_useItem)
		{
			case ENERGYTONIC:
				m_itemUsed = 1;
				m_useItem = NOUSE;
				m_use = false;
			break;

			case ALTEREDTONIC:
				m_itemUsed = 2;
				m_useItem = NOUSE;
				m_use = false;
			break;

			case ANTIALL:
				m_itemUsed = 3;
				m_useItem = NOUSE;
				m_use = false;
			break;

			case FREEBOIMEAT:
				m_itemUsed = 5;
				m_useItem = NOUSE;
				m_use = false;
			break;

			case IMAGINANACOPA:
				m_itemUsed = 6;
				m_useItem = NOUSE;
				m_use = false;
			break;

			default:
				m_itemUsed = 0;
				m_useItem = NOUSE;
			break;
		}
	}
	else
		m_use = true;
}

void
Caio::stand()
{
	if (m_aPressed)
		moveBackward();
	else if (m_dPressed)
		moveForward();
	else if (m_sPressed)
		moveCrouch();
	else if (m_spacePressed)
		moveJump();
	else 
	{	
		m_position.y = getPlatformH() - m_position.h;
		m_jumpspeed = 10;
	}
}

void 
Caio::standForward()
{
	action(0,"[Caio] Standing forward.");
	m_state = STANDING;
	m_dx = 0;
	setClipNumber(0);
}

void 
Caio::standBackward()
{
	action(0,"[Caio] Standing backward.");
	m_state = STANDING;
	m_dx = 0;
	setClipNumber(4);
}

void
Caio::move()
{
	defineCurrentIdleTime(1);
	if (m_sPressed)
	{
		m_aPressed = m_dPressed = false;
		moveCrouch();
	}
	else if (m_spacePressed)
		moveJump();
	else
	{
		if(m_aPressed == false && m_dPressed == false)
		{
			if (m_looking == FORWARD)
				return standForward();
			else
				return standBackward();
		} 
		else if(m_aPressed)
		{
			m_dx = -1;
			m_looking = BACKWARD;
		} 
		else 
		{
			m_dx = 1;
			m_looking = FORWARD;
		}

		m_position.x += round(((m_speed*getDelta())/1000.0)*m_dx);

		if(getCurrentIdleTime() == 4)
		{
			if(m_looking == FORWARD)
			{
				if(m_clipNumber==0)
					setClipNumber(1);
				else if(m_clipNumber==1)
					setClipNumber(2);
				else if(m_clipNumber==2)
					setClipNumber(3);
				else
					setClipNumber(0);
			}
			else
			{
				if(m_clipNumber==4)
					setClipNumber(5);
				else if(m_clipNumber==5)
					setClipNumber(6);
				else if(m_clipNumber==6)
					setClipNumber(7);
				else
					setClipNumber(4);			
			}
			setCurrentIdleTime(0);
		}
		else
			setCurrentIdleTime(getCurrentIdleTime()+1);
	}
}

void
Caio::moveForward()
{
	action(0,"[Caio] Moving Forward.");
	m_state = MOVING;
	m_looking = FORWARD;
	m_dx = 1;
	setClipNumber(0);
}

void
Caio::moveBackward()
{
	action(0,"[Caio] Moving Backward.");
	m_state = MOVING;
	m_looking = BACKWARD;
	m_dx = -1;
	setClipNumber(4);
}

void
Caio::jump()
{
	if (m_aPressed == false && m_dPressed == false)
	{
		m_dx = 0;
	} 
	else if (m_aPressed)
	{
		m_dx = -1;
		m_looking = BACKWARD;
	}
	else if (m_dPressed)
	{
		m_dx = 1;
		m_looking = FORWARD;
	}

	m_position.x += round(((m_speed*getDelta())/1000.0)*m_dx);	
	m_position.y -= m_jumpspeed;
	m_jumpspeed -= 0.4f;

	if(m_looking == FORWARD)
	{
		if (m_jumpspeed > 9.0)
			setClipNumber(9);
		if (m_jumpspeed > 5.0)
			setClipNumber(10);
		else if (m_jumpspeed < 1.0)
			setClipNumber(11);
		else
			setClipNumber(8);
	}
	else if(m_looking == BACKWARD)
	{
		if (m_jumpspeed > 9.0)
			setClipNumber(13);
		if (m_jumpspeed > 5.0)
			setClipNumber(14);
		else if (m_jumpspeed < 1.0)
			setClipNumber(15);
		else
			setClipNumber(12);
	}
		
	if ((m_position.y+m_position.h) >= getPlatformH())
	{
		m_position.y = getPlatformH() - m_position.h;

		m_jumpspeed = 10;

		if (m_dx == 0)
		{
			if (m_looking == FORWARD)
				standForward();
			else 
				standBackward();
		}
		else	
		{
			if (m_looking == FORWARD)
				moveForward();
			else 
				moveBackward();
		}
	}
}

void
Caio::moveJump()
{
	action(0,"[Caio] Jumping.");
	m_state = JUMPING;
	if(m_looking == FORWARD)
		setClipNumber(8);
	else
		setClipNumber(12);
}

void
Caio::crouch()
{
	defineCurrentIdleTime(1);
	if(m_aPressed)
	{
		m_sPressed = false;
		moveBackward();
	}
	else if(m_dPressed)
	{
		m_sPressed = false;
		moveForward();
	}
	else if(m_spacePressed)
		moveJump();
	else if(m_sPressed == false)
	{
		if(m_looking == FORWARD)
			standForward();
		else
			standBackward();
	}
	else if(getCurrentIdleTime() == 4)
	{
		if(m_looking == FORWARD)
		{
			if(m_clipNumber==15)
				setClipNumber(16);
			else if(m_clipNumber==16)
				setClipNumber(17);
			else if(m_clipNumber==17)
				setClipNumber(18);
			else if(m_clipNumber==18)
				setClipNumber(19);
			else
				setClipNumber(19);
		}
		else
		{
			if(m_clipNumber==20)
				setClipNumber(21);
			else if(m_clipNumber==21)
				setClipNumber(22);
			else if(m_clipNumber==22)
				setClipNumber(23);
			else
				setClipNumber(23);
		}
		setCurrentIdleTime(0);
	}
	else
		setCurrentIdleTime(getCurrentIdleTime()+1);
}

void
Caio::moveCrouch()
{
	action(0,"[Caio] Crouching.");
	m_state = CROUCHING;
	m_dx = 0;
	if(m_looking == FORWARD)
		setClipNumber(16);
	else
		setClipNumber(20);
}

bool
Caio::isDead()
{
	loop("[Caio] Verifying if Caio is Dead.");
	return m_dead;
}

bool
Caio::isImune()
{
	loop("[Caio] Verifying if Caio is Imune.");
	return m_imune;
}

float
Caio::getJumpspeed()
{
	loop("[Caio] Getting Jump Speed.");
	return m_jumpspeed;
}

int
Caio::getDirection()
{
	loop("[Caio] Getting Direction.");
	return m_dx;
}

int
Caio::getSpeed()
{
	loop("[Caio] Getting Speed.");
	return m_speed;
}

int
Caio::getHealth()
{
	loop("[Caio] Getting Health.");
	return m_health;
}

int
Caio::getMaxHealth()
{
	loop("[Caio] Getting Maximum Health.");
	return m_maxHealth;
}

int
Caio::getItemUsed()
{
	return m_itemUsed;
}

void
Caio::setDead(bool dead)
{
	loop("[Caio] Setting a New Speed.");
	m_dead = dead;
}

void
Caio::setSpeed(int speed)
{
	loop("[Caio] Setting a New Speed.");
	m_speed = speed;
}

void 
Caio::setHealth(int health)
{
	if (m_health <= 0)
		setDead(true);
	else if (m_health < 10)
		m_health += health;
}

void 
Caio::setMaxHealth(int quantity)
{
	if (m_maxHealth < 6)
		m_maxHealth += quantity;
}

void 
Caio::setImune(int imune)
{
	m_imune = imune;
}