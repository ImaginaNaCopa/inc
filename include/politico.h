#ifndef POLITICO_H
#define POLITICO_H

#include "enemy.h"

class Politico : public Enemy
{
public:
	Politico(int item, bool side, int earlyPosition);
	~Politico();

	void generateBehaviour();
	void generateClips();
	void update(SDL_Rect target);

private:
	typedef enum {STANDING, ATTACKING, MOVING} State;
	typedef enum {FORWARD, BACKWARD} Looking;

	Looking m_looking;
	State m_state;

	bool m_side;
	bool wasJustBorn;
	bool passive;

	void standing();
	void attacking();
	void moving();
};

#endif // POLITICO_H

