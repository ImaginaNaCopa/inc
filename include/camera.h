#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>

class Camera
{
public:
	Camera();
	~Camera();

	void update();
	SDL_Rect m_range;

private:
	int m_width;
	int m_height;

};

#endif // CAMERA_H