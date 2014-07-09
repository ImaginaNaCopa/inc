#ifndef ITEM_H
#define ITEM_H

#include "imageeffect.h"

class Item : public ImageEffect
{
public:
	Item();
	virtual ~Item();

	virtual void update();
	virtual int getId();
protected:
	int id;
};

#endif // ITEM_H
