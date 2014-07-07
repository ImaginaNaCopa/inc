#ifndef FRONTEND_H
#define FRONTEND_H

#include "background.h"
#include "imageeffect.h"
#include "controls.h"

using namespace controls;

class FrontEnd : public ImageEffect
{
public:
	FrontEnd();
	~FrontEnd();

	void generateClips();
	void update();

private:
	Background* background;
	bool m_use;
	bool m_skip;
	
};

#endif // FRONTEND_H