#ifndef PLATFORM_H
#define PLATFORM_H

#include "imagesprite.h"

class Platform : public ImageSprite
{
public:
	Platform(const string& path);
	~Platform();

	void generateClips();
private:
	bool isDrawn;
};

#endif // PLATFORM_H