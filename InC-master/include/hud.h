#ifndef HUD_H
#define HUD_H

#include "hp.h"
#include "inventory.h"
#include "dialogue.h"
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
};

#endif // HUD_H