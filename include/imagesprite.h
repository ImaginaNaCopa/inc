#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "imageload.h"

using namespace std;

class ImageSprite
{
public:
	ImageSprite();
	~ImageSprite();
	void free();

	bool loadFromFile(const string& path);
	void render(int x, int y, SDL_Rect* clip = NULL );
	void generatePosition(int x, int y, int w, int h);
	void addClip(int x, int y, int w, int h);

	int getWidth();
	int getHeight();

	SDL_Texture* m_texture;
	ImageLoad* imageLoad;
	vector<SDL_Rect> m_clips;

	int m_clipNumber;
	SDL_Rect m_position;

private:
	int m_width;
	int m_height;
	
};


#endif // IMAGESPRITE_H