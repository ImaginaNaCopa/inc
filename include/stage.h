#ifndef STAGE_H
#define STAGE_H

#include "../include/entity.h"
#include "../include/hud.h"
#include "../include/scenario.h"
//#include "../include/item.h"

#include "../include/fontconfiguration.h"
#include "../include/text.h"

#include "../include/potion.h"
#include "../include/alteredpotion.h"
#include "../include/antitudo.h"
#include "../include/battery.h"
#include "../include/freeboi.h"
#include "../include/cup.h"
#include "../include/inclogo.h"
#include "../include/antiboss.h"

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
	void rescuingCivilian();
	void controlEntityEvents();

protected:
	bool m_gameOver;
	bool m_finished;
};

#endif // STAGE_H