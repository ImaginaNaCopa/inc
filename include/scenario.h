#ifndef SCENARIO_H
#define SCENARIO_H

#include "background.h"
#include "platform.h"
#include "secondlayer.h"

class Scenario
{
public:
	Scenario();
	virtual ~Scenario();
	void initScenario();
	void drawScenario();
	void updateScenario();
	void releaseScenario();

	virtual void defineBackground();
	virtual void generatePlatform();
	virtual void generateSecondLayer();
protected:
	Background* background;
	Platform* platform;
	SecondLayer* secondlayer;
};

#endif // SCENARIO_H