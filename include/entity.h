#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "aim.h"
#include "caio.h"
#include "camera.h"
#include "enemy.h"
#include "input.h"
#include "systemlogger.h"

using namespace camera;
using namespace input;
using namespace systemLogger;

class Entity
{
public:
	Entity();
	virtual ~Entity();
	
	virtual void controlEntityEvents();
	virtual void generateEnemies();

	void initEntity();
	void drawEntity();
	void updateEntity();

protected:
	Aim* aim;
	Caio* caio;
	Enemy* enemy;
	vector<Enemy *> enemies;
};

#endif // ENTITY_H
