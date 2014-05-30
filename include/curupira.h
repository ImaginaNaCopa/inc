#ifndef CURUPIRA_H
#define CURUPIRA_H

#include "imagesprite.h"
#include "enemy.h"

class Curupira : public Enemy
{
public:
	Curupira(int x, int y, int dx, int max_x, int max_y);

	void generateClips();
	void update(Uint32 delta);

protected:
	int m_max_x;
	int m_max_y;
};

#endif

