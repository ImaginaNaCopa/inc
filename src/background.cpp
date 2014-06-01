#include "background.h"

Background::Background(const string& path) : ImageSprite()
{
	step("[Background] Constructing.");
	imagePath.assign(path);
	generatePosition(0,0,getWindowW(),getWindowH());
	generateClips();
}

Background::~Background()
{
	step("[Background] Destroying.");
	release();
}

void
Background::generateClips()
{
	image("[Background] Generating Sprite Clips.");
	addClip(0,0,2,2);
	image("[Background] Finished Generating Sprite Clips.");
}