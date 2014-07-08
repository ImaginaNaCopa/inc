#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "imageeffect.h"
#include "controls.h"

#include "fontconfiguration.h"
#include "text.h"

using namespace controls;
using namespace fontConfiguration;

class GameOver : public ImageEffect
{
public:
	GameOver();
	~GameOver();

	void generateClips();
	void update();

private:
	Text* m_text;

	bool m_use;
	bool m_isFinished;
	bool m_return;
	bool m_skip;
};

#endif //GAMEOVER_H