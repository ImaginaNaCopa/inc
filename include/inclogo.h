#ifndef INCLOGO_H
#define INCLOGO_H

#include "item.h"

class InCLogo : public Item
{
public:
	InCLogo(int earlyPositionX, int earlyPositionY);
	~InCLogo();

	void generateClips();
	void update();
};

#endif // INCLOGO_H
