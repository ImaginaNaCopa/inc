#ifndef CAIO_H
#define CAIO_H

#include "behaviour.h"
#include "inputhandler.h"
#include "imageeffect.h"

using namespace behaviour;

class Caio : public InputHandler, public ImageEffect
{

public:
	Caio();
	~Caio();

	void update();

	bool overEnemy(SDL_Rect rect);
	bool overItem(SDL_Rect rect);

	bool handle(SDL_Event& event);

	bool isCrouching();
	bool isJumping();
	bool isMoving();
	bool isDead();
	bool isImune();

	float getJumpspeed();
	int getDirection();
	int getSpeed();
	int getHealth();
	int getMaxHealth();
	int getItemUsed();

	void setDead(bool dead);
	void setSpeed(int speed);
	void setHealth(int health);
	void setMaxHealth(int quantity);
	void setImune(int imune);

private:
	typedef enum {STANDING, JUMPING, CROUCHING, MOVING} State;
	typedef enum {FORWARD, BACKWARD} Looking;
	typedef enum {ENERGYTONIC, ALTEREDTONIC, ANTIALL, FREEBOIMEAT, IMAGINANACOPA, NOUSE} UseItem;

	bool m_dead;
	bool m_imune;

	int m_itemUsed;
	bool m_use;
	bool m_keyItemUnpressed;

	bool m_aPressed;
	bool m_sPressed;
	bool m_dPressed;
	bool m_spacePressed;
	
	bool m_onePressed;
	bool m_twoPressed;
	bool m_threePressed;
	bool m_fivePressed;
	bool m_sixPressed;

	float m_jumpspeed;

	int m_dx;
	int m_speed;
	int m_health;
	int m_maxHealth;

	Looking m_looking;
	State m_state;
	UseItem m_useItem;

	void generateClips();
	void generateDefaultStats();

	void handleItens();
	
	void stand();
	void standForward();
	void standBackward();

	void crouch();
	void moveCrouch();

	void jump();
	void moveJump();
	
	void move();
	void moveForward();
	void moveBackward();

};

#endif // CAIO_H
