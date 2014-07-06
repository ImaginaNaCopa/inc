#ifndef AIM_H
#define AIM_H

#include "audiohandler.h"
#include "inputhandler.h"
#include "imagesprite.h"

class Aim : public InputHandler, public ImageSprite
{
public:
	Aim();
	~Aim();

	void generateClips();
	void defineEffects();
	void update();

	bool overEnemy(SDL_Rect rect);
	void overPlayer(SDL_Rect rect);

	bool handle(SDL_Event& event);

	SDL_Rect getKernel();
	void updateKernel();
	bool getShoot();
	void setShoot(bool shoot);

private:
	AudioHandler* shot1;
	SDL_Rect m_kernel;
	bool m_shoot;
};

#endif // AIM_H