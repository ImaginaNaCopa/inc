#ifndef SECONDLAYER_H
#define SECONDLAYER_H

#include "imagesprite.h"

class SecondLayer : public ImageSprite
{
public:
	SecondLayer(const string& path);
	~SecondLayer();
};

#endif // SECONDLAYER_H