#include "platform.h"

using namespace std;

Platform::Platform() : ImageSprite()
{
	imagePath.clear();
	imagePath.assign("res/images/s_02.png");
	generatePosition(0,450,800,150);
	generateClips();
}

Platform::~Platform()
{
}

void
Platform::generateClips()
{
	SystemLogger::step("[Platform] Generating Sprite Clips.");
	addClip(0,4,2,1);
	SystemLogger::step("[Platform] Finished Generating Sprite Clips.");
}