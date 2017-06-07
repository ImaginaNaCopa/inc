#ifndef ANTITUDO_H
#define ANTITUDO_H

#include "../include/item.h"

class AntiTudo : public Item
{
public:
	AntiTudo(int earlyPositionX, int earlyPositionY);
	~AntiTudo();

	void generateClips();
	void update();
private:
	int m_dropspeed;
};

#endif // ANTITUDO_H
