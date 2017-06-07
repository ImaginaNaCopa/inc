#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "../include/aim.h"
#include "../include/caio.h"
#include "../include/camera.h"
#include "../include/civil.h"
#include "../include/enemy.h"
#include "../include/item.h"
#include "../include/timer.h"
#include "../include/systemlogger.h"

using namespace camera;
using namespace systemLogger;
using namespace timer;

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
	vector<Enemy*> enemies;
	Civil* civil;
	vector<Civil*> civis;
	Item* item;
	vector<Item*> itens;
};

#endif // ENTITY_H
