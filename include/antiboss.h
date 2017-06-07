#ifndef ANTIBOSS_H
#define ANTIBOSS_H

#include "../include/item.h"

class AntiBoss : public Item
{
public:
	AntiBoss(int earlyPositionX, int earlyPositionY);
	~AntiBoss();

	void generateClips();
	void update();
private:
	int m_dropspeed;
};

#endif // ANTIBOSS_H
