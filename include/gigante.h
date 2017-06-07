#ifndef GIGANTE_H
#define GIGANTE_H

#include "../include/enemy.h"

class Gigante : public Enemy
{
public:
	Gigante(int earlyPosition);
	~Gigante();

	void generateClips();
	void update(SDL_Rect target);

protected:
	typedef enum {STANDING, MOVING} State;
	typedef enum {FORWARD, BACKWARD} Looking;

	Looking m_looking;
	State m_state;

	bool m_stopWalking;

	void standing();
	void moving();

	int m_bossHealth;
};

#endif // GIGANTE_H

