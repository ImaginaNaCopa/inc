#ifndef FRONTEND_H
#define FRONTEND_H

#include "imageeffect.h"

class FrontEnd : public ImageEffect
{
public:
	FrontEnd();
	~FrontEnd();

	void generateClips();
	void drawEach();
};

#endif // FRONTEND_H