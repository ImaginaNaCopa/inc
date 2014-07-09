#include "dialogue.h"

Dialogue::Dialogue() : ImageSprite()
{
	step("[Dialogue] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(330,10,260,90);
	addClip(200,0,260,90);
}

Dialogue::~Dialogue()
{
	step("[Dialogue] Destroying.");
}