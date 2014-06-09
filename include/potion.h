#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion : public Item
{
public:
	Potion(int earlyPosition);
	~Potion();

	void generateClips();
	void update();
};

#endif // POTION_H
