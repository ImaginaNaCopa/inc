#ifndef CIVIL_H
#define CIVIL_H

#include "imageeffect.h"

class Civil : public ImageEffect
{
public:
	Civil(int item, int earlyPosition);
	~Civil();

	void update();
	int getItem();
	bool isSafe();
	void saved();
	bool isRunned();

private:
	int calculatePosition(int direction);
	void generateClips();
	void updatePosition();

	bool m_safe;
	bool m_runned;

	int m_item;
};

#endif //CIVIL_H