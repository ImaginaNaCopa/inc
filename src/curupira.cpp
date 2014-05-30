#include "curupira.h"
#include "systemlogger.h"
#include <iostream>

using namespace std;

Curupira::Curupira(int x, int y, int dx, int max_x, int max_y)
	: Enemy() 
{
	m_speed = 50;
	m_dx = dx;
	m_frame = 0;

	m_max_x = max_x;
	m_max_y = max_y;

	imagePath.clear();
    imagePath.insert(0,"res/images/s_curupira.png");
    generatePosition(x, y, 50, 100);
    generateClips();
}

void 
Curupira::generateClips()
{
	SystemLogger::step("[Curupira] Generating Sprite Clips.");
	addClip(0,0,m_position.w,m_position.h);
    addClip(m_position.w,0,m_position.w,m_position.h);
    addClip(m_position.w*2,0,m_position.w,m_position.h);
    addClip(m_position.w*3,0,m_position.w,m_position.h);

    addClip(0,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w*2,m_position.h,m_position.w,m_position.h);
    addClip(m_position.w*3,m_position.h,m_position.w,m_position.h);
    SystemLogger::step("[Curupira] Finished Generating Sprite Clips.");
}

void 
Curupira::update(Uint32 delta)
{	
    m_clipNumber = 0;
	if (delta < 100)
	{
		m_position.x += round(((m_speed*delta)/1000.0)*m_dx);

		if (m_position.x >= m_max_x)
			m_dx = -1;
		if (m_position.x <= m_max_y)
			m_dx = 1;
	}

	delta = 0;
}
