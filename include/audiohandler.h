#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#define MIX_LOOP -1

#include <string>
#include <SDL2/SDL_mixer.h>
#include "../include/systemlogger.h"

using namespace systemLogger;

namespace audioHandler 
{
	typedef enum {BCH, BNS, CRO, HUE, JOR, SAP, NOMUSIC} Music;
	typedef enum
	{	C1,C2,C3,C4,C5,C6,C7,pDie,eDerp1,eDerp2,eDerp3,
		eDerp4,eDerp5,eDerp6,eDerp7,FF,GO,gAtt,gDie,iC,
		iU,lAtt,lDie,Ouch,PS,S1,S2,tDie,uDie,NOEFFECT	} Effect;
	
	void tickRand();
	int getRand();
	void resetRand();
	void setCurrentMusic(Music index);
	void setCurrentEffect(Effect index);
	void playMusic(const int times);
	void playEffect();

	void initMusicsAndSoundEffects();
	void freeMusicsAndSoundEffects();
}

#endif //AUDIOHANDLER_H