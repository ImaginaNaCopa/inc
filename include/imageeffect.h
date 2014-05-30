#ifndef IMAGEEFFECT_H
#define IMAGEEFFECT_H

#include "imagesprite.h"

class ImageEffect : public ImageSprite
{
public:
	ImageEffect();
	~ImageEffect();

	void fadein();
	void fadeout();
protected:
	Uint8 m_alpha;
};

#endif // IMAGEEFFECT_H