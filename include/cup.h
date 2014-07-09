#ifndef CUP_H
#define CUP_H

#include "item.h"

class Cup : public Item
{
public:
	Cup(int earlyPositionX, int earlyPositionY);
	~Cup();

	void generateClips();
	void update();
};

#endif // CUP_H
