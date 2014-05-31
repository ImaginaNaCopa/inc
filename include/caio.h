#ifndef CAIO_H
#define CAIO_H

#include "inputhandler.h"
#include "collision.h"
#include "imageeffect.h"

class Caio : public InputHandler, public ImageEffect
{

public:
	Caio();
	~Caio();

	void generateClips();
	void update(Uint32 delta);
	bool overEnemy(SDL_Rect rect);
	bool handle(SDL_Event& event);

	void moveForward();
	void moveBackward();
	void moveJump();
	void moveCrouch();
	
private:
	bool isMoving;
	bool isJumping;
	bool isCrouching;
	int speed;
	int dx;
	float jumpspeed;
};

#endif // CAIO_H