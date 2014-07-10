#include "entity.h"

Entity::Entity()
{
	//step("[Entity] Constructing.");
	aim = new Aim();
	caio = new Caio();
}

Entity::~Entity()
{
	//step("[Entity] Destroying.");
	for (auto it = itens.begin(); it != itens.end(); it++)
		delete *it;
	for (auto it = civis.begin(); it != civis.end(); it++)
		delete *it;
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		delete *it;

	delete caio;
	delete aim;
}

void 
Entity::initEntity()
{
	//step("[Entity] Uploading Sprite Sheets");
	aim->init();
	caio->init();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->init();
	for (auto it = civis.begin(); it != civis.end(); it++)
		(*it)->init();
	for (auto it = itens.begin(); it != itens.end(); it++)
		(*it)->init();
}

void
Entity::drawEntity()
{
	//loop("[Entity] Drawing Entities.");
	caio->drawTexts();
	caio->drawRelative();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->drawRelative();
	for (auto it = civis.begin(); it != civis.end(); it++)
		(*it)->drawRelative();
	for (auto it = itens.begin(); it != itens.end(); it++)
		(*it)->drawRelative();

	if(getTimelineEvent() != LEVELFOUR)
		aim->draw();
}

void
Entity::updateEntity()
{
	//loop("[Entity] Updating Entities.");
	aim->update();
	aim->overPlayer(caio->getPosition());
	caio->update();
	updateCamera(caio->getPosition());
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->update(caio->getPosition());
	for (auto it = civis.begin(); it != civis.end(); it++)
	{
		aim->overPlayer((*it)->getPosition());
		(*it)->update();
	}
	for (auto it = itens.begin(); it != itens.end(); it++)
		(*it)->update();
}

void
Entity::generateEnemies() {}

void
Entity::controlEntityEvents() {}