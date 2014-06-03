#ifndef HP_H
#define HP_H

#include "imagesprite.h"

class Hp : public ImageSprite
{
public:
	Hp();
	~Hp();

	void generateClips();
	void drawEach();
};

#endif // HP_H