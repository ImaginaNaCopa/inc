#ifndef STAGE_H
#define STAGE_H

#include "hud.h"
#include "inputhandler.h"
#include "scenario.h"
#include "stageentity.h"

class Stage
{
public:
	Stage();
	~Stage();

	void init();
	void draw();
	void update(Uint32 delta);

	void release();

	StageEntity* getEntity() const;

private:
	Camera* camera;
	Hud* hud;
	StageEntity* entity;
	Scenario* scenario;
};

#endif // STAGE_H