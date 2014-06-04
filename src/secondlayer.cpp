#include "secondlayer.h"

SecondLayer::SecondLayer(const string& path)
{
    step("[Sebastiao] Constructing.");
	imagePath.assign(path);
}

SecondLayer::~SecondLayer()
{
    step("[Sebastiao] Destroying.");
	release();
}