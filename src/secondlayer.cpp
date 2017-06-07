#include "../include/secondlayer.h"

SecondLayer::SecondLayer(const string& path) : ImageEffect()
{
	//step("[SecondLayer] Constructing.");
	imagePath.assign(path);
}

SecondLayer::~SecondLayer(){}