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
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		delete *it;
	for (auto it = itens.begin(); it != itens.end(); it++)
		delete *it;
	delete caio;
	delete aim;
}

void 
Entity::initEntity()
{
	step("[Entity] Uploading Sprite Sheets");
	aim->init();
	caio->init();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->init();
	for (auto it = itens.begin(); it != itens.end(); it++)
		(*it)->init();
	
	step("[Entity] Initiating Input Handle Environments.");
	addHandler(caio);
	addHandler(aim);
}

void
Entity::drawEntity()
{
	loop("[Entity] Drawing Entities.");
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->drawRelative();
	for (auto it = itens.begin(); it != itens.end(); it++)
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
	caio->update();
	updateCamera(caio->getPosition());
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->update();
	for (auto it = itens.begin(); it != itens.end(); it++)
		(*it)->update();
}

void
Entity::generateEnemies() {}

void
Entity::generateItens() {}

void
Entity::controlEntityEvents() {}