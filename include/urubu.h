#ifndef URUBU_H
#define URUBU_H

#include "enemy.h"

class Urubu : public Enemy
{
public:
	Urubu(int earlyPosition);
	~Urubu();

	void generateBehaviour();
	void generateClips();
	void update();
};

#endif // URUBU_H
