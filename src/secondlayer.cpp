#include "secondlayer.h"

SecondLayer::SecondLayer()
{
	imagePath.insert(0,"res/images/s_02.png");
	generateClips();
}

SecondLayer::~SecondLayer()
{
}

void
SecondLayer::generateClips()
{
	addClip(4,0,270,210);
	addClip(4,210,270,270);
	addClip(274,0,120,360);
}

void
SecondLayer::drawEach()
{
	m_clipNumber = 0;
	generatePosition(40,240,270,210);
	draw();
	m_clipNumber = 1;
	generatePosition(450,180,270,270);
	draw();
	m_clipNumber = 2;
	generatePosition(1100,90,120,360);
	draw();
	generatePosition(1350,90,120,360);
	draw();
	generatePosition(1600,90,120,360);
	draw();
	generatePosition(1850,90,120,360);
	draw();
}