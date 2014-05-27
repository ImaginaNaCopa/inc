#ifndef SCENARIO_H
#define SCENARIO_H

#include "background.h"
#include "platform.h"
#include "secondlayer.h"

class Scenario
{
public:
	Scenario();
	~Scenario();
	void init();
	void draw();
	void update();
	void release();
private:
	Background* background;
	Platform* platform;
	SecondLayer* secondlayer;
};

#endif // SCENARIO_H