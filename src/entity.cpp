#include "entity.h"

Entity::Entity()
{
	step("[Entity] Constructing.");
	aim = new Aim();
	caio = new Caio();
}

Entity::~Entity()
{
	step("[Entity] Destroying.");
	releaseEntity();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		delete *it;
	delete caio;
	delete aim;
}

void 
Entity::initEntity()
{
	step("[Entity] Uploading Sprite Sheets and Initiating Input Handle Environments.");
	aim->init();
	caio->init();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->init();

	addHandler(caio);
    addHandler(aim);
}

void
Entity::drawEntity()
{
	loop("[Entity] Rendering Entities.");
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->drawRelative();
	caio->drawRelative();
	aim->draw();
}

void
Entity::updateEntity()
{
	loop("[Entity] Updating Entities.");
	aim->update();
	aim->overPlayer(caio->getPosition());
	caio->update(getNormalLevelW());
	updateCamera(caio->getPosition(), getNormalLevelW());
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->update();
}

void 
Entity::releaseEntity()
{
	loop("[Entity] Releasing Entities.");
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->release();
	caio->release();
	aim->release();
}

void
Entity::generateEnemies() {}

void
Entity::controlEntityEvents() {}