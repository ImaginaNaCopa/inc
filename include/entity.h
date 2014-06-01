#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "aim.h"
#include "caio.h"
#include "camera.h"
#include "enemy.h"
#include "input.h"

using namespace camera;
using namespace input;
using namespace std;

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void generateEnemies();

	void initEntity();
	void drawEntity();
	void updateEntity();
	void releaseEntity();

	virtual void controlEntityEvents();

protected:
	Aim* aim;
	Caio* caio;
	vector<Enemy *> enemies;
	Enemy* enemy;
};

#endif // ENTITY_H
