#include "caio.h"

#include <iostream>
using namespace std;

Caio::Caio() : ImageEffect()
{
	step("[Caio] Constructing.");
	imagePath.assign("res/images/s_caio.png");
	generatePosition(round(getWindowW()/16),getPlatformH(),48,55);
	generateClips();

	m_dx = 0;
	m_speed = haveQuicklySpeed();
	m_jumpspeed = 10;
	m_health = 3;
	m_maxHealth = 3;
	m_dead = false;
	m_imune = false;

	m_state = STANDING;
	m_looking = FORWARD;
	m_clipOffset = 0;

	m_aPressed = false;
	m_sPressed = false;
	m_dPressed = false;
	m_spacePressed = false;

	m_onePressed = false;
	m_twoPressed = false;
	m_threePressed = false;
	m_fivePressed = false;
	m_sixPressed = false;

	m_itemUsed = 0;
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
Caio::update()
{
	loop("[Caio] Updating.");

	switch (m_state)
	{
		case STANDING:
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
				m_position.y = getPlatformH() - m_clips.at(m_clipNumber).h;
				m_jumpspeed = 10;
			}
		break;

		case MOVING:
			if (m_sPressed)
			{
				m_aPressed = m_dPressed = false;
				moveCrouch();
			}
			else if (m_spacePressed)
				moveJump();
			else
				move();
		break;
	
		case JUMPING:
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
			jump();
		break;

	case CROUCHING:
		if (m_aPressed)
		{
			m_sPressed = false;
			moveBackward();
		} else if (m_dPressed)
		{
			m_sPressed = false;
			moveForward();
		} else if (m_spacePressed)
			moveJump();
		else if (m_sPressed == false)
		{
			if (m_looking == FORWARD)
				standForward();
			else
				standBackward();
		} else
		{
			m_clipNumber++;

			if (m_clipNumber > 19)
				m_clipNumber = 19;
		}
	break;	
	}
	if(m_position.y > getPlatformH() - m_clips.at(m_clipNumber).h)
		m_position.y = getPlatformH() - m_clips.at(m_clipNumber).h;
	m_position.w = m_clips.at(m_clipNumber).w;
	m_position.h = m_clips.at(m_clipNumber).h;

	if (m_onePressed)
	{
		m_itemUsed = 1;
		m_onePressed = false;
	}
	else if (m_twoPressed)
	{
		m_itemUsed = 2;
		m_twoPressed = false;
	}
	else if (m_threePressed)
	{
		m_itemUsed = 3;
		m_threePressed = false;
	}
	else if (m_fivePressed)
	{
		m_itemUsed = 5;
		m_fivePressed = false;
	}
	else if (m_sixPressed)
	{
		m_itemUsed = 6;
		m_sixPressed = false;
	}
	else
		m_itemUsed = 0;	
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
			m_onePressed = type == SDL_KEYUP ? true : false;
		break;

		case SDLK_2:
			m_twoPressed = type == SDL_KEYUP ? true : false;
		break; 

		case SDLK_3:
			m_threePressed = type == SDL_KEYUP ? true : false;
		break;

		case SDLK_5:
			m_fivePressed = type == SDL_KEYUP ? true : false;
		break;

		case SDLK_6:
			m_sixPressed = type == SDL_KEYUP ? true : false;
		break;

		default:
			return false;
		break;
	}
	return true;	
}

void
Caio::moveBackward()
{
	action(0,"[Caio] Moving Backward.");
	m_state = MOVING;
	m_looking = BACKWARD;
	m_dx = -1;
	m_clipNumber = 7;
	m_clipOffset = 4;
}

void 
Caio::standForward()
{
	action(0,"[Caio] Standing forward.");
	m_state = STANDING;
	m_dx = 0;
	m_clipNumber = 0;
}

void 
Caio::standBackward()
{
	action(0,"[Caio] Standing backward.");
	m_state = STANDING;
	m_dx = 0;
	m_clipNumber = 4;
}
void
Caio::moveCrouch()
{
	action(0,"[Caio] Crouching.");
	m_state = CROUCHING;
	m_dx = 0;
	m_clipNumber = 15;
	m_clipOffset = 0;
}

void
Caio::moveForward()
{
	action(0,"[Caio] Moving Forward.");
	m_state = MOVING;
	m_looking = FORWARD;
	m_dx = 1;
	m_clipNumber = 3;
	m_clipOffset = 0;
}

void
Caio::moveJump()
{
	action(0,"[Caio] Jumping.");
	m_state = JUMPING;
	m_clipNumber = 11;
	m_clipOffset = 8;
}

void
Caio::move()
{
	if (m_aPressed == false && m_dPressed == false)
	{
		if (m_looking == FORWARD)
			return standForward();
		else
			return standBackward();
	} 
	else if (m_aPressed)
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

	if (m_looking == FORWARD)
		m_clipOffset = 0;
	else
		m_clipOffset = 4;

	m_clipNumber = ((m_clipNumber + 1) % 4) + m_clipOffset;
}

void
Caio::jump()
{
	m_position.y -= m_jumpspeed;
	m_jumpspeed -= 0.4f;

	if(m_looking == FORWARD)
	{
		if (m_jumpspeed > 9.0)
			m_clipNumber = 9;
		if (m_jumpspeed > 5.0)
			m_clipNumber = 10;
		else if (m_jumpspeed < 1.0)
			m_clipNumber = 11;
		else
			m_clipNumber = 8;
	}
	else if(m_looking == BACKWARD)
	{
		if (m_jumpspeed > 9.0)
			m_clipNumber = 13;
		if (m_jumpspeed > 5.0)
			m_clipNumber = 14;
		else if (m_jumpspeed < 1.0)
			m_clipNumber = 15;
		else
			m_clipNumber = 12;
	}
		
	if ((m_position.y+m_position.h) >= getPlatformH())
	{
		m_position.y = getPlatformH() - m_clips.at(m_clipNumber).h;

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
Caio::setSpeed(int speed)
{
	loop("[Caio] Setting a New Speed.");
	m_speed = speed;
}

void
Caio::setDead(bool dead)
{
	loop("[Caio] Setting a New Speed.");
	m_dead = dead;
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