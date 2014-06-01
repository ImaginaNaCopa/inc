#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "imagesprite.h"

class Background : public ImageSprite
{
public:
	Background(const string& path);
	~Background();

	void generateClips();
};

#endif // BACKGROUND_H