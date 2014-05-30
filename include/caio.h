#ifndef CAIO_H
#define CAIO_H

#include <SDL2/SDL.h>
#include <string>
#include "imageload.h"
#include "imagesprite.h"
#include "inputhandler.h"

class Caio : public InputHandler, public ImageSprite
{

public:
	Caio();
	~Caio();

	void generateClips();
	void update(Uint32 delta);
	bool handle(SDL_Event& event);

	void moveForward();
	void moveBackward();
	void moveJump();
	void moveCrouch();
	
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