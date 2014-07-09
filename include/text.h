#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include "camera.h"
#include "collision.h"
#include "configuration.h"
#include "imageload.h"
#include "fontconfiguration.h"

using namespace camera;
using namespace collision;
using namespace configuration;
using namespace imageLoad;
using namespace std;
using namespace fontConfiguration;

class Text
{
public:
	Text(const string& fontPath, int fontSize);
	~Text();

	void addText(const string& newText);
	void removeText();
	void setTextNumber(int newTextNumber);

	void addPosition(int x, int y);
	void setPositionNumber(int newPositionNumber);
	void setPosition(int newX, int newY);

	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	void drawText();
	void drawTextRelative();

private:
	TTF_Font* m_font;
	SDL_Color m_fontColor;
	vector<string> m_texts;
	vector<SDL_Rect> m_positions;
	int m_textNumber;
	int m_positionNumber;
};

#endif // TEXT_H