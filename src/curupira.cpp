#include "curupira.h"
#include "systemlogger.h"
#include <iostream>

using namespace std;

Curupira::Curupira(int x, int y, int dx, int max_x, int max_y)
	: Enemy() 
{
	SystemLogger::step("[Curupira] Creating Curupira.");
	m_speed = 50;
	m_dx = dx;
	m_frame = 0;

	m_max_x = max_x;
	m_max_y = max_y;

	imagePath.clear();
    imagePath.insert(0,"res/images/s_curupira.png");
    generatePosition(x, y, 50, 100);
    generateClips();
    SystemLogger::step("[Curupira] Curupira created.");
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
	if (delta < 100)
	{
		m_position.x += round(((m_speed*delta)/1000.0)*m_dx);

		if (m_position.x >= m_max_x)
			m_dx = -1;

		if (m_dx == -1)
		{
			if (m_position.x % 8 == 0)
				m_clipNumber = 0;
			if (m_position.x % 8 == 1)
				m_clipNumber = 1;
			if (m_position.x % 8 == 2)
				m_clipNumber = 2;
			if (m_position.x % 8 == 3)
				m_clipNumber = 3;
		}

		if (m_position.x <= m_max_y)
			m_dx = 1;

		if (m_dx == 1)
		{
			if (m_position.x % 8 == 4)
				m_clipNumber = 4;
			if (m_position.x % 8 == 5)
				m_clipNumber = 5;
			if (m_position.x % 8 == 6)
				m_clipNumber = 6;
			if (m_position.x % 8 == 7)
				m_clipNumber = 7;	
		}			
	}
}
