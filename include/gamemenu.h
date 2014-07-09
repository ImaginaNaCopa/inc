#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "text.h"
#include "imagesprite.h"

class GameMenu : public ImageSprite
{
public:
	GameMenu();
	~GameMenu();

	void generateClips();
};

#endif // GAMEMENU_H