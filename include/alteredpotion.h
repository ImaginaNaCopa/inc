#ifndef ALTEREDPOTION_H
#define ALTEREDPOTION_H

#include "../include/item.h"

class AlteredPotion : public Item
{
public:
	AlteredPotion(int earlyPositionX, int earlyPositionY);
	~AlteredPotion();

	void generateClips();
	void update();
private:
	int m_dropspeed;
};

#endif // ALTEREDPOTION_H
