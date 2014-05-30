#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "imagesprite.h"

class Background : public ImageSprite
{
public:
	Background();
	~Background();

	void generateClips();
};

#endif // BACKGROUND_H