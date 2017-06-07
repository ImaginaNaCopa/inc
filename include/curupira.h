#ifndef CURUPIRA_H
#define CURUPIRA_H

#include "../include/enemy.h"
#include "../include/audiohandler.h"

using namespace audioHandler;

class Curupira : public Enemy
{
public:
	Curupira(int item, int earlyPosition);
	~Curupira();

	void generateBehaviour();
	void generateClips();
	void update(SDL_Rect target);

private:
	typedef enum {UNDERGROUND, STANDING, ATTACKING, MOVING} State;
	typedef enum {FORWARD, BACKWARD} Looking;

	Looking m_looking;
	State m_state;
	bool m_rose;
	
	void underground();
	void standing();
	void attacking();
	void moving();
};

#endif

