#ifndef ITEM_H
#define ITEM_H

#include "imagesprite.h"

class Item : public ImageSprite
{
public:
	Item();
	virtual ~Item();

	virtual void update();
};

#endif // ITEM_H
