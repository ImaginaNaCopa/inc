#ifndef STAGE_H
#define STAGE_H

#include "hud.h"
#include "scenario.h"
#include "entity.h"
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
protected:
	bool m_gameOver;
	bool m_finished;
	Text* m_text;
};

#endif // STAGE_H