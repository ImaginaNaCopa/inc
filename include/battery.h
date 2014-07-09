#ifndef BATTERY_H
#define BATTERY_H

#include "item.h"

class Battery : public Item
{
public:
	Battery(int earlyPositionX, int earlyPositionY);
	~Battery();

	void generateClips();
	void update();
private:
	int m_dropspeed;
};

#endif // BATTERY_H
