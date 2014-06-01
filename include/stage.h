#ifndef STAGE_H
#define STAGE_H

#include "hud.h"
#include "scenario.h"
#include "entity.h"

class Stage : public Scenario, public Hud, public Entity
{
public:
	Stage();
	~Stage();

	void init();
	void draw();
	void update();
	void release();
};

#endif // STAGE_H