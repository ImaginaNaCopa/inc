#ifndef STAGE_H
#define STAGE_H

#include "hud.h"
#include "scenario.h"
#include "entity.h"
#include "potion.h"
#include "alteredpotion.h"
#include "text.h"
#include "fontconfiguration.h"

using namespace fontConfiguration;

class Stage : public Scenario, public Hud, public Entity
{
public:
	Stage();
	~Stage();

	void init();
	void draw();
	void update();
	
	void setGameOver(bool over);
	bool gameOver();
	void setFinished(bool finished);
	bool isFinished();
	void damagingCaio();
	void lootItem();
	void killingEnemy();
	void usingItens();
	void controlEntityEvents();
	
protected:
	bool m_gameOver;
	bool m_finished;
	Text* m_text;
	Uint32 now;
	Uint32 last;
};

#endif // STAGE_H