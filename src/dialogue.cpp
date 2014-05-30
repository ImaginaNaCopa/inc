#include "dialogue.h"

Dialogue::Dialogue() : ImageSprite()
{
	imagePath.insert(0,"res/images/s_hud.png");
	generatePosition(280,10,260,90);
	generateClips();
}

Dialogue::~Dialogue()
{
	// Nothing yet
}

void 
Dialogue::generateClips()
{
	addClip(42,17,4,4);
}