#ifndef FREEBOI_H
#define FREEBOI_H

#include "item.h"

class Freeboi : public Item
{
public:
	Freeboi(int earlyPositionX, int earlyPositionY);
	~Freeboi();

	void generateClips();
	void update();
private:
	int m_dropspeed;
};

#endif // FREEBOI_H
