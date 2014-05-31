#ifndef AIM_H
#define AIM_H

#include "collision.h"
#include "imagesprite.h"
#include "inputhandler.h"

using namespace collision;

class Aim : public InputHandler, public ImageSprite
{
public:
	Aim();
	~Aim();

	void generateClips();
	void update();

	bool overEnemy(SDL_Rect rect);
	void overPlayer(SDL_Rect rect);

	bool handle(SDL_Event& event);

	SDL_Rect getKernel();
	void updateKernel();	
private:
	SDL_Rect m_kernel;
	bool m_shoot;
};

#endif // AIM_H