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
	void drawScenarioStaticImages();

	virtual void defineBackground();
	virtual void generatePlatform();
	virtual void generateSecondLayer();
	virtual void drawScenarioRelativeImages();

protected:
	Background* background;
	Platform* platform;
	SecondLayer* secondlayer;
};

#endif // SCENARIO_H