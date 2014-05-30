#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "imageload.h"
#include "systemlogger.h"

using namespace std;

class ImageSprite
{
public:
	ImageSprite();
	~ImageSprite();
	
	void generatePosition(int x, int y, int w, int h);
	void addClip(int x, int y, int w, int h);

	int getWidth();
	int getHeight();

	void init();
	void draw();
	void render();
	void release();

	SDL_Texture* m_texture;
	ImageLoad* imageLoad;
	vector<SDL_Rect> m_clips;
	string imagePath;

	int m_clipNumber;
	SDL_Rect m_position;

private:
	int m_width;
	int m_height;
	
};


#endif // IMAGESPRITE_H