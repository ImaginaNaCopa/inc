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
	//Caio(int x);
	~Caio();

	void generateClips();
	void update();

	bool overEnemy(SDL_Rect rect);

	bool handle(SDL_Event& event);
	void moveBackward();
	void moveCrouch();
	void moveForward();
	void moveJump();

	bool isCrouching();
	bool isJumping();
	bool isMoving();
	bool isDead();
	bool isImune();
	float getJumpspeed();
	int getDirection();
	int getSpeed();
	int getHealth();

	void setSpeed(int speed);
	void setHealth(int health);
	void setImune(int imune);

private:
	bool m_crouching;
	bool m_jumping;
	bool m_moving;
	float m_jumpspeed;
	int m_dx;
	int m_speed;
	int m_health;
	bool m_dead;
	bool m_imune;
};

#endif // CAIO_H