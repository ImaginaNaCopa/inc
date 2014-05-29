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
	void init();
	void draw();
	void update();
	void release();
private:
	Hp* hp;
	Inventory* inventory;
	Dialogue* dialogue;
	Sebastiao* sebastiao;
	GameMenu* gameMenu;
};

#endif // HUD_H