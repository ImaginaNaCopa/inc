#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "imagesprite.h"

class Background : public ImageSprite
{
public:
	Background(const string& path);
	~Background();
};

#endif // BACKGROUND_H