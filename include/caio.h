#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include <string>
#include "imageload.h"
#include "inputhandler.h"
#include "imagesprite.h"

class Caio : public InputHandler, public ImageSprite
{

public:
	Caio();
	~Caio();

	void init();
	void draw();
	void update(Uint32 delta);
	void release();
	bool handle(SDL_Event& event);

	void moveForward();
	void moveBackward();
	void moveJump();
	void moveCrouch();

	void generatePosition();
	void generateClips();
	SDL_Rect getPosition() const;

private:
	bool isMoving;
	bool isJumping;
	bool isCrouching;
	int speed;
	int dx;
	float jumpspeed;
};

#endif // CAIO_H