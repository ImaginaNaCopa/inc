#ifndef THEEND_H
#define THEEND_H

#include "imageeffect.h"
#include "background.h"
#include "controls.h"
#include "fontconfiguration.h"
#include "text.h"

using namespace controls;
using namespace fontConfiguration;

class TheEnd : public ImageEffect
{
public:
	TheEnd();
	~TheEnd();

	void generateClips();
	void update();

private:
	bool m_use;
	bool m_isFinished;
	bool m_return;
	bool m_skip;

	Background* background;

	typedef enum 
	{
		TRYFORCE,
		EQUIPE,
		PROGRAMADORES,
		ARTISTAS,
		MUSICO,
		AGRADECIMENTOS,
		FIMDEJOGO,
		INIMIGOEOUTRO
	} TimelineTheEnd;

	TimelineTheEnd m_steps;
};

#endif //THEEND_H