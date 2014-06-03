#ifndef HUD_H
#define HUD_H

#include "dialogue.h"
#include "hp.h"
#include "gamemenu.h"
#include "inventory.h"
#include "sebastiao.h"

class Hud
{
public:
	Hud();
	~Hud();
	void initHud();
	void drawHud();
	void updateHud();
private:
	Dialogue* dialogue;
	GameMenu* gameMenu;
	Hp* hp;
	Inventory* inventory;
	Sebastiao* sebastiao;
};

#endif // HUD_H