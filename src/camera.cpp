#include "camera.h"

Camera::Camera(Caio* const caio)
{
	m_caio = caio;
	m_width=1600;
	m_height=600;
	m_clip = {0,0,800,600};
}

Camera::~Camera()
{
}

void Camera::update()
{
	m_clip.x = (m_caio->m_position.x + m_caio->m_position.w/2) - (m_clip.w/2);
	m_clip.y = (m_caio->m_position.y + m_caio->m_position.h/2) - (m_clip.h/2);
	if(m_clip.x < 0)
		m_clip.x = 0;
	else if(m_clip.x > m_width - m_clip.w )
		m_clip.x = m_width - m_clip.w;
}

