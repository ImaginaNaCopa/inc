#ifndef SECONDLAYER_H
#define SECONDLAYER_H

#include "imagesprite.h"

class SecondLayer : public ImageSprite
{
public:
	SecondLayer();
	~SecondLayer();

	void generateClips();
	void drawEach();
};

#endif // SECONDLAYER_H