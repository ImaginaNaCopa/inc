#ifndef HP_H
#define HP_H

#include <SDL2/SDL.h>
#include "imageload.h"
#include "imagesprite.h"

class Hp : public ImageSprite
{
public:
	Hp();
	~Hp();

	void init();
	void draw();
	void release();
	
	void generateClips();

private:
	bool isDrawn;
};

#endif // HP_H