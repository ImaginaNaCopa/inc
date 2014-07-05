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

	void generateClips();
	void update();

	bool overEnemy(SDL_Rect rect);
	bool overItem(SDL_Rect rect);

	bool handle(SDL_Event& event);
	void useItem(int option);
	void moveBackward();
	void moveCrouch();
	void moveForward();
	void moveJump();
	void standForward();
	void standBackward();

	bool isCrouching();
	bool isJumping();
	bool isMoving();
	bool isDead();
	bool isImune();
	float getJumpspeed();
	int getDirection();
	int getSpeed();
	int getHealth();

	void setDead(bool dead);
	void setSpeed(int speed);
	void setHealth(int health);
	void setImune(int imune);

private:
	typedef enum {STANDING, JUMPING, CROUCHING, MOVING} State;
	typedef enum {FORWARD, BACKWARD} Looking;

	float m_jumpspeed;
	int m_dx;
	int m_speed;
	int m_health;
	bool m_dead;
	bool m_imune;

	State m_state;
	Looking m_looking;
	int m_clipOffset;

	bool m_aPressed;
	bool m_sPressed;
	bool m_dPressed;
	bool m_spacePressed;
};

#endif // CAIO_H
