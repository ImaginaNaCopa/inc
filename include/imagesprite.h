#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include <vector>
#include "imageload.h"
#include "camera.h"
#include "collision.h"
#include "configuration.h"
#include "timer.h"

using namespace camera;
using namespace collision;
using namespace configuration;
using namespace imageLoad;
using namespace std;
using namespace timer;

class ImageSprite
{
public:
	ImageSprite();
	~ImageSprite();

	void init();
	void draw();
	void drawRelative();
	void release();
	
	void generatePosition(int x, int y, int w, int h);
	void addClip(int x, int y, int w, int h);

	SDL_Rect getPosition();
	int getWidth();
	int getHeight();

	void setClipNumber(int clipNumber);
	void setOnlyClipNumber(int clipNumber);
	
protected:
	SDL_Rect m_position;
	vector<SDL_Rect> m_clips;

	SDL_Texture* m_texture;
	
	int m_clipNumber;
	int m_width;
	int m_height;
	
	string imagePath;
};

#endif // IMAGESPRITE_H