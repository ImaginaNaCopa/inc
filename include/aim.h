#ifndef AIM_H
#define AIM_H

#include "audiohandler.h"
#include "controls.h"
#include "imagesprite.h"

using namespace audioHandler;
using namespace controls;

class Aim : public ImageSprite
{
public:
	Aim();
	~Aim();

	void generateClips();
	void defineEffects();
	void update();

	bool overEnemy(SDL_Rect rect);
	void overPlayer(SDL_Rect rect);

	SDL_Rect getKernel();
	void updateKernel();
	bool getShoot();
	void setShoot(bool shoot);

private:
	SDL_Rect m_kernel;
	bool m_shoot;
};

#endif // AIM_H