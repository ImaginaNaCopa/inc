#ifndef STAGEENTITY_H
#define STAGEENTITY_H

#include "aim.h"
#include "caio.h"
#include "camera.h"
#include "stageenemy.h"

class StageEntity
{
public:
	StageEntity();
	~StageEntity();

	void init();
	void draw();
	void update(Uint32 delta);
	void release();

	Caio* getCaio() const;
	Aim* getAim() const;
private:
	Caio* caio;
	StageEnemy* enemy;
	Aim* aim;

};

#endif // STAGEENTITY_H