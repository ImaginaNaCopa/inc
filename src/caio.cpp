#include "caio.h"

#include <iostream>
using namespace std;

Caio::Caio() : ImageEffect()
{
    step("[Caio] Constructing.");

    imagePath.assign("res/images/s_caio.png");
    generatePosition(round(getWindowW()/16),getPlatformH(),70,70);
    generateClips();

    m_dx = 0;
    m_speed = haveQuicklySpeed();
    m_jumpspeed = 10;
    m_health = 3;
    m_dead = false;
    m_imune = false;

	m_state = STANDING;
	m_looking = FORWARD;
	m_clipOffset = 0;

	m_aPressed = false;
	m_sPressed = false;
	m_dPressed = false;
	m_spacePressed = false;
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
    addClip(0,0,m_position.w,m_position.h);
    addClip(m_position.w,0,m_position.w,m_position.h);
    addClip(m_position.w*2,0,m_position.w,m_position.h);
    addClip(m_position.w*3,0,m_position.w,m_position.h);

    addClip(0,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w*2,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w*3,m_position.h,m_position.w,m_position.h);

    addClip(0,m_position.h*2,m_position.w,m_position.h);
    addClip(m_position.w,m_position.h*2,m_position.w,m_position.h);
    addClip(m_position.w*2,m_position.h*2,m_position.w,m_position.h);
    addClip(m_position.w*3,m_position.h*2,m_position.w,m_position.h);

    addClip(0,m_position.h*3,m_position.w,m_position.h);
    addClip(m_position.w,m_position.h*3,m_position.w,m_position.h);
    addClip(m_position.w*2,m_position.h*3,m_position.w,m_position.h);
    addClip(m_position.w*3,m_position.h*3,m_position.w,m_position.h);
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
        	m_position.y = getPlatformH() - m_position.h;
			m_jumpspeed = 10;
		}
	break;

	case MOVING:
		if (m_sPressed)
		{
			m_aPressed = m_dPressed = false;
			moveCrouch();
		} else if (m_spacePressed)
			moveJump();
		else
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
        m_position.y -= m_jumpspeed;
        m_jumpspeed -= 0.4f;

		if (m_jumpspeed > 9.0)
			m_clipNumber = 9;
		if (m_jumpspeed > 5.0)
			m_clipNumber = 10;
		else if (m_jumpspeed < 1.0)
			m_clipNumber = 11;
		else
			m_clipNumber = 8;

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

			if (m_clipNumber > 15)
				m_clipNumber = 15;
		}
	break;	
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

	default:
		return false;
	}
		
	return true;	
}

/*           		{
                	case SDLK_a:
                   		controls(1,"[Caio] Button a Down.");
	                    moveBackward();
                    	processed = true;

	                break;
                case SDLK_d:
                    controls(1,"[Caio] Button d Down.");
                    processed = true;
					if (m_state != JUMPING)
                    	moveForward();
					else
						m_dx = 1;
                break;
                case SDLK_s:
                    controls(1,"[Caio] Button s Down.");
                    processed = true;
                    moveCrouch();
                break;
                case SDLK_SPACE:
                    controls(1,"[Caio] Button SPACE Down.");
                    processed = true;
                    moveJump();                
                break;  
                case SDLK_1:
                    controls(1,"[Caio] Button 1 Down.");
                    processed = true;
                    useItem(1);                
                break;  
                case SDLK_2:
                    controls(1,"[Caio] Button 2 Down.");
                    processed = true;
                    useItem(2);                
                break;  
                case SDLK_3:
                    controls(1,"[Caio] Button 3 Down.");
                    processed = true;
                    useItem(3);                
                break;  
                case SDLK_4:
                    controls(1,"[Caio] Button 4 Down.");
                    processed = true;
                    useItem(4);                
                break;  
                case SDLK_5:
                    controls(1,"[Caio] Button 5 Down.");
                    processed = true;
                    useItem(5);                
                break;  
                case SDLK_6:
                    controls(1,"[Caio] Button 6 Down.");
                    processed = true;
                    useItem(6);                
                break;
                default:
                break;
            }
        break;

        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
                    controls(1,"[Caio] Button a Up.");
					if (m_state != JUMPING)
						standBackward();
					else
						m_dx = 0;
                break;
                case SDLK_d:
                    controls(1,"[Caio] Button d Up.");
					if (m_state != JUMPING)
						standForward();
					else
						m_dx = 0;
                break;
                case SDLK_s:
                    controls(1,"[Caio] Button s Up.");
                    processed = true;
					standForward();
                break;              
                case SDLK_SPACE:
                    controls(1,"[Caio] Button SPACE Up.");
                    processed = true;
                break;
                case SDLK_1:
                    controls(1,"[Caio] Button 1 Up.");
                    processed = true;
                break;  
                case SDLK_2:
                    controls(1,"[Caio] Button 2 Up.");
                    processed = true;
                break;  
                case SDLK_3:
                    controls(1,"[Caio] Button 3 Up.");
                    processed = true;
                break;  
                case SDLK_4:
                    controls(1,"[Caio] Button 4 Up.");
                    processed = true;
                break;  
                case SDLK_5:
                    controls(1,"[Caio] Button 5 Up.");
                    processed = true;
                break;  
                case SDLK_6:
                    controls(1,"[Caio] Button 6 Up.");
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
*/
void
Caio::useItem(int option)
{
    action(0,"[Caio] Using Item.");
    
    switch (option)
    {
        case 1:
            action(0,"[Caio] Used Item 1.");        
        break;
        case 2:
            action(0,"[Caio] Used Item 2.");        
        break;
        case 3:
            action(0,"[Caio] Used Item 3.");        
        break;
        case 4:
            action(0,"[Caio] Used Item 4.");        
        break;
        case 5:
            action(0,"[Caio] Used Item 5.");        
        break;
        case 6:
            action(0,"[Caio] Used Item 6.");        
        break;
        default:
        break;
    }
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
	m_clipNumber = 11;
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
Caio::setImune(int imune)
{
    m_imune = imune;
}
