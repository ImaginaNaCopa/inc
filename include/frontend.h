#ifndef FRONTEND_H
#define FRONTEND_H

#include "imageeffect.h"

class FrontEnd : public ImageEffect
{
public:
	FrontEnd();
	~FrontEnd();

	void generateClips();
	void update();

	bool isOver();
	void setOver(bool overState);

private:
	bool m_over;
};

#endif // FRONTEND_H