#ifndef INVENTORY_H
#define INVENTORY_H

#include "imageload.h"
#include "imagesprite.h"
#include "systemlogger.h"

using namespace std;

class Inventory : public ImageSprite
{
public:
	Inventory();
	~Inventory();

	void drawEach();
	void generateClips();
	void initInventory();
	void updateInventory();
};

#endif // INVENTORY_H
