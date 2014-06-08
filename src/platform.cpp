#include "platform.h"

using namespace std;

Platform::Platform(const string& path) : ImageSprite()
{
	step("[Platform] Constructing.");
	imagePath.assign(path);
	generatePosition(0,getPlatformH(),getWindowW(),getWindowH()-getPlatformH());
	generateClips();
}

Platform::~Platform()
{
	step("[Platform] Destroying.");
	release();
}

void
Platform::generateClips()
{
	step("[Platform] Generating Sprite Clips.");
	addClip(0,4,2,1);
}