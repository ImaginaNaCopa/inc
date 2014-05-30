#include "enemy.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Enemy::Enemy()
{
	positionCurupira.y = 350;
	positionCurupira.w = 50;
	positionCurupira.h = 100;

	positionUrubu.y = 175;
	positionUrubu.w = 50;
	positionUrubu.h = 25;

	isDrawn = false;

    imageLoad = imageLoad->getInstance();
}

Enemy::~Enemy()
{
	// Nothing yet
}

void 
Enemy::init()
{
	m_texture = imageLoad->loadImg("res/images/curupira.png");
	m_texture2 = imageLoad->loadImg("res/images/urubu.png");
}

void 
Enemy::draw()
{
	positionCurupira.x = 700;
    imageLoad->update(m_texture, &positionCurupira);
    positionCurupira.x = 600;
    imageLoad->update(m_texture, &positionCurupira);
    positionUrubu.x = 150;
    imageLoad->update(m_texture2, &positionUrubu);
    positionUrubu.x = 350;
    imageLoad->update(m_texture2, &positionUrubu);
    positionUrubu.x = 550;
    imageLoad->update(m_texture2, &positionUrubu);
}

void 
Enemy::release()
{
	SDL_DestroyTexture(m_texture);
}