#ifndef LEVELONE_H
#define LEVELONE_H

#include "stage.h"
#include "curupira.h"

class LevelOne : public Stage
{
public:
	LevelOne();
	~LevelOne();

	void generateEnemies();
	void controlEntityEvents();

	void defineBackground();
	void generatePlatform();
	void generateSecondLayer();

	bool isOver();
	void setOver(bool overState);

private:
	bool m_over;
};

#endif // LEVELONE_H