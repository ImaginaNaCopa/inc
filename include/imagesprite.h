#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include <string>
#include <SDL2/SDL.h>
#include "imageload.h"

using namespace std;

class ImageSprite
{
public:
	ImageSprite();
	~ImageSprite();
	bool loadFromFile(const string& path);
	void free();
	void render(int x, int y, SDL_Rect* clip = NULL );
	int getWidth();
	int getHeight();
	SDL_Texture* m_texture;
	ImageLoad* imageLoad;
private:
	int m_width;
	int m_height;
};


#endif // IMAGESPRITE_H