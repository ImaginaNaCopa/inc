#ifndef SECONDLAYER_H
#define SECONDLAYER_H

#include "imageeffect.h"

class SecondLayer : public ImageEffect
{
public:
	SecondLayer();
	SecondLayer(const string& path);
	~SecondLayer();
};

#endif // SECONDLAYER_H