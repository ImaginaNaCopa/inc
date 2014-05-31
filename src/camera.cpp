#include "camera.h"

namespace camera
{
	SDL_Rect m_range = {0,0,800,600};

	void
	updateCamera(SDL_Rect target, int levelWidth)
	{
		m_range.x = (target.x+target.w/2)-(m_range.w/2);
		if(m_range.x < 0)
			m_range.x = 0;
		else if(m_range.x>levelWidth-m_range.w)
			m_range.x = levelWidth - m_range.w;
	}

	SDL_Rect
	getCameraRange()
	{
		return m_range;
	}

	int
	getCameraLeftPosition()
	{
		return m_range.x;
	}

	int
	getCameraRightPosition()
	{
		return m_range.x + m_range.w;
	}
}

/*Camera::Camera()
{
	m_range = {0,0,800,600};
}

Camera::~Camera()
{
}

void
Camera::update(SDL_Rect target, int levelWidth)
{
	m_range.x = (target.x+target.w/2)-(m_range.w/2);
	if(m_range.x < 0)
		m_range.x = 0;
	else if(m_range.x>levelWidth-m_range.w)
		m_range.x = levelWidth - m_range.w;
}

SDL_Rect
Camera::getRange()
{
	return m_range;
}

int
Camera::getLeftPosition()
{
	return m_range.x;
}

int
Camera::getRightPosition()
{
	return m_range.x + m_range.w;
}*/