#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "imageeffect.h"

class Background : public ImageEffect
{
public:
	Background(const string& path);
	~Background();
};

#endif // BACKGROUND_H