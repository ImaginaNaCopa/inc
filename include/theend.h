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

	Background* m_background;
	Background* m_titulo;
	Background* m_nome;

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

	typedef enum
	{
		IAGO,
		ARKYE,
		LUCIANO,
		ATILLA,
		INARA,
		RENATA,
		LUCIAN,
		CARLA,
		EDSON,
		RENAN,
		TIAGO,
	} Nomes;

	TimelineTheEnd m_steps;
	Nomes m_stepsN;
};

#endif //THEEND_H