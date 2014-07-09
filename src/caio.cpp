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
	newVariousIdleTimes(4);
	m_firstAidCountdown = new Text(getFontNulshock(),getFontSize(3));
	m_firstAidCountdown->addText("5");
	m_firstAidCountdown->addText("4");
	m_firstAidCountdown->addText("3");
	m_firstAidCountdown->addText("2");
	m_firstAidCountdown->addText("1");
	m_firstAidCountdown->addPosition(0,0);
	m_firstAidCountdown->setColor(0,0,0,255);
}

Caio::~Caio()
{
	step("[Caio] Destroying.");
	delete m_firstAidCountdown;
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

	m_itemUsed = 0;
	m_use = true;

	m_nearCivilian = false;
	m_firstAid = false;
	m_successfulFirstAid = false;
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

		case FIRSTAID:
			firstAid();
		break;
	}

	if(m_position.y > getPlatformH() - m_position.h)
		m_position.y = getPlatformH() - m_position.h;
	if(m_position.x <= 0)
		m_position.x = 0;
	else if(m_position.x >= getLevelW() - m_position.w)
		m_position.x = getLevelW() - m_position.w;

	handleItens();
}

void
Caio::drawTexts()
{
	if(m_firstAid)
	{
		m_firstAidCountdown->setPosition(m_position.x+10, m_position.y-50);
		m_firstAidCountdown->drawTextRelative();
	}
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
Caio::nearCivilian(SDL_Rect rect)
{
	loop("[Caio] Checking if Collided with a Rectangle.");
	SDL_Rect civilian = rect;
	civilian.x -= 25;
	civilian.w += 50;
	if(ifCollided(1,getPosition(),civilian))
	{
		condition("[Caio] Collided on left side.");
		m_nearCivilian = true;
		m_nearOnLeftSide = true;
		return true;
	}
	else if(ifCollided(2,getPosition(),civilian))
	{
		condition("[Caio] Collided on right side.");
		m_nearCivilian = true;
		m_nearOnLeftSide = false;
		return true;
	}
	m_nearCivilian = false;
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

void
Caio::handleItens()
{

	if(m_use)
	{
		if(isCItemOne())
			m_useItem = ENERGYTONIC;
		else if(isCItemTwo())
			m_useItem = ALTEREDTONIC;
		else if(isCItemThree())
			m_useItem = ANTIALL;
		else if(isCItemFive())
			m_useItem = FREEBOIMEAT;
		else if(isCItemSix())
			m_useItem = IMAGINANACOPA;
		else
			m_useItem = NOUSE;		
	}

	if(!isCKeyUp())
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
	{
		falseCItemOne();
		falseCItemTwo();
		falseCItemThree();
		falseCItemFour();
		falseCItemFive();
		falseCItemSix();
		m_use = true;
	}
}

void
Caio::stand()
{
	if(isCActioned() && m_nearCivilian)
		moveFirstAid();
	else if (isCBackwarded())
		moveBackward();
	else if (isCForwarded())
		moveForward();
	else if (isCCrouched())
		moveCrouch();
	else if (isCJumped())
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
	if (isCCrouched())
	{
		falseCForward();
		falseCBackward();
		moveCrouch();
	}
	else if (isCJumped())
		moveJump();
	else
	{
		if(!isCBackwarded() && !isCForwarded())
		{
			if (m_looking == FORWARD)
				return standForward();
			else
				return standBackward();
		} 
		else if(isCBackwarded())
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
	if (!isCBackwarded() && !isCForwarded())
	{
		m_dx = 0;
	} 
	else if (isCBackwarded())
	{
		m_dx = -1;
		m_looking = BACKWARD;
	}
	else if (isCForwarded())
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
	if(isCBackwarded())
	{
		falseCCrouch();
		moveBackward();
	}
	else if(isCForwarded())
	{
		falseCCrouch();
		moveForward();
	}
	else if(isCJumped())
		moveJump();
	else if(!isCCrouched())
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

void
Caio::firstAid()
{
	if (isCBackwarded())
	{
		resetFirstAid();
		moveBackward();
	}
	else if (isCForwarded())
	{
		resetFirstAid();
		moveForward();
	}
	else if (isCCrouched())
	{
		resetFirstAid();
		moveCrouch();
	}
	else if (isCJumped())
	{
		resetFirstAid();
		moveJump();
	}
	else if(!m_firstAid || m_successfulFirstAid)
	{
		resetFirstAid();
		if(m_looking == FORWARD)
			standForward();
		else
			standBackward();
	}
	else
	{
		defineCurrentIdleTime(3);
		if(getCurrentIdleTime() == 40)
		{
			setCurrentIdleTime(0);
			tickFACountdown();
			defineCurrentIdleTime(3);
		}
		else
			setCurrentIdleTime(getCurrentIdleTime()+1);
	}
}

void
Caio::moveFirstAid()
{
	action(0,"[Caio] First Aid.");
	m_firstAid = true;
	m_state = FIRSTAID;
	m_dx = 0;
	if(m_nearOnLeftSide)
	{
		setClipNumber(17);
		m_looking = FORWARD;
	}
	else
	{
		setClipNumber(21);	
		m_looking = BACKWARD;
	}
}

void
Caio::tickFACountdown()
{
	defineCurrentIdleTime(4);
	if(getCurrentIdleTime() == 4)
	{
		setCurrentIdleTime(0);
		m_successfulFirstAid = true;
	}
	else
	{
		setCurrentIdleTime(getCurrentIdleTime()+1);
		m_firstAidCountdown->setTextNumber(getCurrentIdleTime());
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

void
Caio::resetFirstAid()
{
	m_firstAid = false;
	m_successfulFirstAid = false;
	defineCurrentIdleTime(4);
	setCurrentIdleTime(0);
	defineCurrentIdleTime(3);
	setCurrentIdleTime(0);
	m_firstAidCountdown->setTextNumber(0);
}

bool
Caio::successfulFirstAid()
{
	return m_successfulFirstAid;
}