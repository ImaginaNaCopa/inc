#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "frontend.h"
#include "imageload.h"

using namespace std;

FrontEnd::FrontEnd() : ImageEffect()
{
	imagePath.insert(0,"res/images/s_frontend.png");
	generateClips();
}

FrontEnd::~FrontEnd()
{
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
	Uint32 now = SDL_GetTicks();
    Uint32 last = 0;
    int step = 0;
    while(step!=4)
    {
	    now = SDL_GetTicks();
	    if(step==0)
	    {
			m_clipNumber = 0;
			generatePosition(225,165,350,270);
			fadein();
			step++;
		}
		else if((now > last + 2000) && (step==1))
		{
			fadeout();
			m_clipNumber = 1;
			generatePosition(200,100,400,400);
			fadein();
			step++;
			last = now;
		}
		else if((now > last + 2000) && (step==2))
		{
			fadeout();
			m_clipNumber = 2;
			generatePosition(163,165,475,270);
			fadein();
			step++;
			last = now;
		}
		else if((now > last + 2000) && (step==3))
		{
			fadeout();
			step++;
		}
	}
}