#ifndef HUD_H
#define HUD_H

#include "../include/dialogue.h"
#include "../include/hp.h"
#include "../include/gamemenu.h"
#include "../include/inventory.h"
#include "../include/sebastiao.h"

class Hud
{
public:
	Hud();
	~Hud();
	void initHud();
	void drawHud();
	void updateHud();
protected:
	Dialogue* dialogue;
	GameMenu* gameMenu;
	Hp* hp;
	Inventory* inventory;
	Sebastiao* sebastiao;
};

#endif // HUD_H