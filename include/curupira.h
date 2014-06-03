#ifndef CURUPIRA_H
#define CURUPIRA_H

#include "enemy.h"

class Curupira : public Enemy
{
public:
	Curupira(int earlyPosition);
	~Curupira();

	void generateBehaviour();
	void generateClips();
	void update();
};

#endif

