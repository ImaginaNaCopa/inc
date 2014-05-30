#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "imagesprite.h"

class Dialogue : public ImageSprite
{
public:
	Dialogue();
	~Dialogue();

	void generateClips();
};

#endif // DIALOGUE_H