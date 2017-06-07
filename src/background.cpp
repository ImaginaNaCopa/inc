#include "../include/background.h"

Background::Background(const string& path) : ImageEffect()
{
	//step("[Background] Constructing.");
	imagePath.assign(path);
	generatePosition(0,0,getWindowW(),getWindowH());
}

Background::~Background()
{
	//step("[Background] Destroying.");
}