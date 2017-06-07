#ifndef IMAGEEFFECT_H
#define IMAGEEFFECT_H

#include "../include/imagesprite.h"

class ImageEffect : public ImageSprite
{
public:
	ImageEffect();
	~ImageEffect();

	void fade(Uint8 fadeTick, int idle);
	void reverseFade(Uint8 fadeTick, int idle);
	void fadeinTick(Uint8 fadeTick);
	void fadeoutTick(Uint8 fadeTick);

	bool isFadeEnded();
	void newFade();
	void newReverseFade();
	void drawInAlpha(Uint8 alpha);

	int getCurrentIdleTime();
	void setCurrentIdleTime(int newIdleTime);
	void newIdleTime();
	void newVariousIdleTimes(int quantity);
	void defineCurrentIdleTime(int coordinate);
	
protected:
	vector<int> idleTimes;
	int m_iTimeNumber = 0;

	Uint8 m_alpha;
	
	bool m_fading;
	bool m_fadingin;
	bool m_endedFade;
};

#endif // IMAGEEFFECT_H