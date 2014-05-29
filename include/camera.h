#ifndef CAMERA_H
#define CAMERA_H

#include "caio.h"

class Camera
{
public:
	Camera(Caio* const caio);
	~Camera();

	void update();
	SDL_Rect m_clip;
private:
	int m_width;
	int m_height;
	Caio* m_caio;
};

#endif // CAMERA_H