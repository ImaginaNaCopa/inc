#ifndef POTION_H
#define POTION_H

#include "../include/item.h"

class Potion : public Item
{
public:
	Potion(int earlyPositionX, int earlyPositionY);
	~Potion();

	void generateClips();
	void update();
private:
	int m_dropspeed;
};

#endif // POTION_H
