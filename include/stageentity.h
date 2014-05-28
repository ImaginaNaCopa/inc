#ifndef STAGEENTITY_H
#define STAGEENTITY_H

#include "caio.h"
#include "aim.h"
#include "enemy.h"

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
	Enemy* enemy;
	Aim* aim;

};

#endif // STAGEENTITY_H