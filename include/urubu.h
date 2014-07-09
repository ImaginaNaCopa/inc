#ifndef URUBU_H
#define URUBU_H

#include "enemy.h"

#include "audiohandler.h"
using namespace audioHandler;

class Urubu : public Enemy
{
public:
	Urubu(int item, int earlyPosition);
	~Urubu();

	void generateBehaviour();
	void generateClips();
	void update(SDL_Rect target);
};

#endif // URUBU_H
