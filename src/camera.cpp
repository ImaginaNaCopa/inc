#include "camera.h"

Camera::Camera()
{
	m_width=1600;
	m_height=600;
	m_range = {0,0,800,600};
}

Camera::~Camera()
{
}

void
Camera::update()
{
	/*
	m_range.x = (m_caio->m_position.x + m_caio->m_position.w/2) - (m_range.w/2);
	if(m_range.x < 0)
		m_range.x = 0;
	else if(m_range.x > m_width - m_range.w )
		m_range.x = m_width - m_range.w;
	*/
}

