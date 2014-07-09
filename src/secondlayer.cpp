#include "secondlayer.h"

SecondLayer::SecondLayer(){}

SecondLayer::SecondLayer(const string& path)
{
	step("[Sebastiao] Constructing.");
	imagePath.assign(path);
}

SecondLayer::~SecondLayer(){}