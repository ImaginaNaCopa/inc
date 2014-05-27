#ifndef ENTITY_H
#define ENTITY_H

#include "caio.h"
#include "aim.h"
#include "enemy.h"

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
	Enemy* enemy;
	Aim* aim;

};

#endif // ENTITY_H