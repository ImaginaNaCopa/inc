#ifndef INVENTORY_H
#define INVENTORY_H

#include "imageload.h"
#include "imagesprite.h"
#include "item.h"

class Inventory : public ImageSprite
{
public:
	Inventory();
	~Inventory();

	void drawEach();
	void generateClips();
	void initInventory();
	void updateInventory();

private:
	bool isDrawn;
	Item* item;
};

#endif // INVENTORY_H