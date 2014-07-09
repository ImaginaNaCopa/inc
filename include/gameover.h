#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "imageeffect.h"
#include "controls.h"

#include "fontconfiguration.h"
#include "text.h"

#include "timer.h"

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