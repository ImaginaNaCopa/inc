#ifndef FRONTEND_H
#define FRONTEND_H

#include "background.h"
#include "imageeffect.h"

class FrontEnd : public ImageEffect
{
public:
	FrontEnd();
	~FrontEnd();

	void generateClips();
	void update();

private:
	Background* background;
};

#endif // FRONTEND_H