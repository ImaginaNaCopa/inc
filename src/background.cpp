#include "background.h"

Background::Background() : ImageSprite()
{
	step("[Background] Constructing.");
	imagePath.insert(0,"res/images/s_02.png");
	generatePosition(0,0,800,600);
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