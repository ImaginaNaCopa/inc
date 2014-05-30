#include "background.h"

using namespace std;

Background::Background() : ImageSprite()
{
	imagePath.insert(0,"res/images/s_02.png");
	generatePosition(0,0,800,600);
	generateClips();
}

Background::~Background()
{
	release();
}

void
Background::generateClips()
{
	addClip(0,0,2,2);
}