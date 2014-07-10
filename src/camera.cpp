#include "camera.h"

namespace camera
{
	SDL_Rect m_range = {0,0,getWindowW(),getWindowH()};

	void
	updateCamera(SDL_Rect target)
	{
		//loop("[Camera] Updating Camera Position.");
		m_range.x = (target.x+target.w/2)-(m_range.w/2);
		if(m_range.x < 0)
			m_range.x = 0;
		else if(m_range.x > getLevelW() -m_range.w)
			m_range.x = getLevelW() - m_range.w;
	}

	void
	updateCameraRange()
	{
		//step("[Camera] Updating Range According to Window Dimensions.");
		m_range.w = getWindowW();
		m_range.h = getWindowH();
	}

	SDL_Rect
	getCameraRange()
	{
		//loop("[Camera] Getting Camera AOS.");
		return m_range;
	}

	int
	getCameraLeftPosition()
	{
		//loop("[Camera] Getting Camera Left Position.");
		return m_range.x;
	}

	int
	getCameraRightPosition()
	{
		//loop("[Camera] Getting Camera Right Position.");
		return m_range.x + m_range.w;
	}
}