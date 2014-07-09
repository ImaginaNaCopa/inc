#include "secondlayer.h"

SecondLayer::SecondLayer(){}

SecondLayer::SecondLayer(const string& path)
{
	step("[SecondLayer] Constructing.");
	imagePath.assign(path);
}

SecondLayer::~SecondLayer(){}