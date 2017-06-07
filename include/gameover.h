#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "../include/imageeffect.h"
#include "../include/controls.h"

#include "../include/fontconfiguration.h"
#include "../include/text.h"

#include "../include/timer.h"

using namespace controls;
using namespace fontConfiguration;
using namespace timer;

class GameOver : public ImageEffect
{
public:
	GameOver();
	~GameOver();

	void update();

private:
	Text* m_text;
};

#endif //GAMEOVER_H