#include "platform.h"

using namespace std;

Platform::Platform(const string& path) : ImageSprite()
{
	imagePath.assign(path);
	generatePosition(0,450,800,150);
	generateClips();
}

Platform::~Platform()
{
	release();
}

void
Platform::generateClips()
{
	step("[Platform] Generating Sprite Clips.");
	addClip(0,4,2,1);
	step("[Platform] Finished Generating Sprite Clips.");
}