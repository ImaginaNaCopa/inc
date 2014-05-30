#ifndef ENTITY_H
#define ENTITY_H

#include "caio.h"
#include "aim.h"
#include "enemy.h"
#include "curupira.h"

#include <vector>
using std::vector;

class Entity
{
public:
	Entity();
	~Entity();

	void init();
	void draw();
	void update(Uint32 delta);
	void release();

	Caio* getCaio() const;
	Aim* getAim() const;
private:
	Caio* caio;
	vector<Enemy *> enemies;
	Aim* aim;
	Enemy* enemy;
};

#endif // ENTITY_H
