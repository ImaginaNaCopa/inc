#ifndef CURUPIRA_H
#define CURUPIRA_H

#include "imagesprite.h"
#include "enemy.h"

class Curupira : public Enemy
{
public:
	Curupira(int earlyPosition);
	~Curupira();

	void generateBehavior();
	void generateClips();
	void update();
};

#endif

