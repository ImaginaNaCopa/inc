#include "secondlayer.h"

SecondLayer::SecondLayer(const string& path)
{
	imagePath.assign(path);
	generateClips();
}

SecondLayer::~SecondLayer()
{
	release();
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
	drawRelative();
	m_clipNumber = 1;
	generatePosition(450,180,270,270);
	drawRelative();
	m_clipNumber = 2;
	generatePosition(800,90,120,360);
	drawRelative();
	generatePosition(1000,90,120,360);
	drawRelative();
	generatePosition(1200,90,120,360);
	drawRelative();
	generatePosition(1400,90,120,360);
	drawRelative();
}