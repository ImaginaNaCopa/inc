#include "frontend.h"

FrontEnd::FrontEnd() : ImageEffect()
{
	step("WOLOLO");
	imagePath.insert(0,"res/images/s_frontend.png");
	generateClips();
}

FrontEnd::~FrontEnd()
{
	release();
}

void
FrontEnd::generateClips()
{
	addClip(0,0,350,270);
	addClip(0,280,400,400);
	addClip(360,0,475,270);

	addClip(410,300,40,30);
	addClip(450,300,40,30);
	addClip(490,300,40,30);
}

void
FrontEnd::drawEach()
{
    int steps = 0;
    while(steps!=4)
    {
	    tick();
	    switch(steps)
	    {
	    	case 0:
		    	m_clipNumber = 0;
				generatePosition(225,165,350,270);
				fadein();
				steps++;
			break;
			case 1:
				waitMiliseconds(2000);
				fadeout();
				m_clipNumber = 1;
				generatePosition(200,100,400,400);
				fadein();
				steps++;
			break;
			case 2:
				waitMiliseconds(2000);
				fadeout();
				m_clipNumber = 2;
				generatePosition(163,165,475,270);
				fadein();
				steps++;
			break;
			case 3:
				waitMiliseconds(2000);
				fadeout();
				steps++;
			break;

			default:
			break;
	    }
	}
}