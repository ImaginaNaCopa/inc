#ifndef CAIO_H
#define CAIO_H

#include "inputhandler.h"
#include "collision.h"
#include "imageeffect.h"

class Caio : public InputHandler, public ImageEffect
{

public:
	Caio();
	Caio(int x);
	~Caio();

	void generateClips();
	void update(Uint32 delta, int levelWidth);

	bool overEnemy(SDL_Rect rect);

	bool handle(SDL_Event& event);
	void moveBackward();
	void moveCrouch();
	void moveForward();
	void moveJump();

	bool isCrouching();
	bool isJumping();
	bool isMoving();
	float getJumpspeed();
	int getDirection();
	int getSpeed();

	void setSpeed(int speed);
private:
	bool m_crouching;
	bool m_jumping;
	bool m_moving;
	float m_jumpspeed;
	int m_dx;
	int m_speed;
};

#endif // CAIO_H