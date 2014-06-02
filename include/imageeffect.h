#ifndef IMAGEEFFECT_H
#define IMAGEEFFECT_H

#include "imagesprite.h"

class ImageEffect : public ImageSprite
{
public:
	ImageEffect();
	~ImageEffect();

	void fade();
	void fadeinTick();
	void fadeoutTick();
	
protected:
	Uint8 m_alpha;
	bool m_fading;
	bool m_fadingin;
};

#endif // IMAGEEFFECT_H