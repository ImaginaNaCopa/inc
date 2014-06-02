#include "dialogue.h"

Dialogue::Dialogue() : ImageSprite()
{
	step("[Dialogue] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(280,10,260,90);
	generateClips();
}

Dialogue::~Dialogue()
{
	step("[Dialogue] Destroying.");
	release();
}

void 
Dialogue::generateClips()
{
	step("[Dialogue] Generating Sprite Clips.");
	addClip(42,17,4,4);
	step("[Dialogue] Finished Generating Sprite Clips.");
}