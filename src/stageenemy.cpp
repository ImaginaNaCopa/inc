#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "stageenemy.h"

using namespace std;

/* CORRIGIR TUDO ISSO :P
 -> Aqui é bom ficar APENAS o roteiro dos inimigos no cenario
 -> Como a posição inicial dele e possiveis alterações no comportamento
 -> Todo o Restante deverá estar individualmente nos padrões de cada inimigo
*/
 
StageEnemy::StageEnemy()
{
    m_clips[0].x = 0;
    m_clips[0].y = 0;
    m_clips[0].w = 50;
    m_clips[0].h = 100;

    m_clips[1].x = 50;
    m_clips[1].y = 0;
    m_clips[1].w = 50;
    m_clips[1].h = 100;

    m_clips[2].x = 100;
    m_clips[2].y = 0;
    m_clips[2].w = 50;
    m_clips[2].h = 100;

    m_clips[3].x = 150;
    m_clips[3].y = 0;
    m_clips[3].w = 50;
    m_clips[3].h = 100;

    m_clips[4].x = 0;
    m_clips[4].y = 100;
    m_clips[4].w = 50;
    m_clips[4].h = 100;

    m_clips[5].x = 50;
    m_clips[5].y = 100;
    m_clips[5].w = 50;
    m_clips[5].h = 100;

    m_clips[6].x = 100;
    m_clips[6].y = 100;
    m_clips[6].w = 50;
    m_clips[6].h = 100;

    m_clips[7].x = 150;
    m_clips[7].y = 100;
    m_clips[7].w = 50;
    m_clips[7].h = 100;

	positionCurupira[0].x = 700;
	positionCurupira[0].y = 350;
	positionCurupira[0].w = 50;
	positionCurupira[0].h = 100;

	positionCurupira[1].x = 300;
	positionCurupira[1].y = 350;
	positionCurupira[1].w = 50;
	positionCurupira[1].h = 100;

	positionUrubu[0].x = 150;
	positionUrubu[0].y = 175;
	positionUrubu[0].w = 50;
	positionUrubu[0].h = 25;

	positionUrubu[1].x = 450;
	positionUrubu[1].y = 175;
	positionUrubu[1].w = 50;
	positionUrubu[1].h = 25;
	
	positionUrubu[2].x = 550;
	positionUrubu[2].y = 175;
	positionUrubu[2].w = 50;
	positionUrubu[2].h = 25;

	speedC = 55;
	speedU = 150;
	
	dxC[0] = -1;
	dxC[1] = 1;

	dxU[0] = 1;
	dxU[1] = -1;
	dxU[2] = 1;
	
	uC[0] = uC[1] = 0;

    imageLoad = imageLoad->getInstance();
    m_imageSpriteUrubu = new ImageSprite();
    m_imageSpriteCurupira = new ImageSprite();
}

StageEnemy::~StageEnemy()
{
}

void 
StageEnemy::init()
{
}

void 
StageEnemy::draw()
{
    imageLoad->update(m_imageSpriteCurupira->m_texture, &m_clips[uC[0]], &positionCurupira[0]);
    imageLoad->update(m_imageSpriteCurupira->m_texture, &m_clips[uC[1]], &positionCurupira[1]);
    imageLoad->update(m_imageSpriteUrubu->m_texture, NULL, &positionUrubu[0]);
    imageLoad->update(m_imageSpriteUrubu->m_texture, NULL, &positionUrubu[1]);
    imageLoad->update(m_imageSpriteUrubu->m_texture, NULL, &positionUrubu[2]);
}

void 
StageEnemy::update(Uint32 delta)
{
	if (delta < 100){
		// Curupiras
		if (positionCurupira[0].x >= 600)
			dxC[0] = -1;
		if (positionCurupira[0].x <= 500)
			dxC[0] = 1;
		if (positionCurupira[1].x >= 400)
			dxC[1] = -1;
		if (positionCurupira[1].x <= 300)
			dxC[1] = 1;

		// Urubus
		if (positionUrubu[0].x == 150)
			dxU[0] = 1;
		if (positionUrubu[0].x == 250)
			dxU[0] = -1;
		if (positionUrubu[1].x == 450)
			dxU[1] = -1;
		if (positionUrubu[1].x == 350)
			dxU[1] = 1;
		if (positionUrubu[2].x == 550)
			dxU[2] = 1;
		if (positionUrubu[2].x == 650)
			dxU[2] = -1;

		//Animation to the left
		if(dxC[0] == -1 && ((positionCurupira[0].x % 8) == 0 || (positionCurupira[0].x % 8) == 1))
			uC[0] = 0;

		if(dxC[0] == -1 && ((positionCurupira[0].x % 8) == 2 || (positionCurupira[0].x % 8) == 3))
			uC[0] = 1;

		if(dxC[0] == -1 && ((positionCurupira[0].x % 8) == 4 || (positionCurupira[0].x % 8) == 5))
			uC[0] = 2;
           
		if(dxC[0] == -1 && ((positionCurupira[0].x % 8) == 6 || (positionCurupira[0].x % 8) == 7))
			uC[0] = 3;

		//Animation to the right
		if(dxC[0] == 1 && ((positionCurupira[0].x % 8) == 0 || (positionCurupira[0].x % 8) == 1))
			uC[0] = 4;

		if(dxC[0] == 1 && ((positionCurupira[0].x % 8) == 2 || (positionCurupira[0].x % 8) == 3))
			uC[0] = 5;

		if(dxC[0] == 1 && ((positionCurupira[0].x % 8) == 4 || (positionCurupira[0].x % 8) == 5))
			uC[0] = 6;
           
		if(dxC[0] == 1 && ((positionCurupira[0].x % 8) == 6 || (positionCurupira[0].x % 8) == 7))
			uC[0] = 7;

		//Animation to the left
		if(dxC[1] == -1 && ((positionCurupira[1].x % 8) == 0 || (positionCurupira[1].x % 8) == 1))
			uC[1] = 0;

		if(dxC[1] == -1 && ((positionCurupira[1].x % 8) == 2 || (positionCurupira[1].x % 8) == 3))
			uC[1] = 1;

		if(dxC[1] == -1 && ((positionCurupira[1].x % 8) == 4 || (positionCurupira[1].x % 8) == 5))
			uC[1] = 2;
           
		if(dxC[1] == -1 && ((positionCurupira[1].x % 8) == 6 || (positionCurupira[1].x % 8) == 7))
			uC[1] = 3;

		//Animation to the right
		if(dxC[1] == 1 && ((positionCurupira[1].x % 8) == 0 || (positionCurupira[1].x % 8) == 1))
			uC[1] = 4;

		if(dxC[1] == 1 && ((positionCurupira[1].x % 8) == 2 || (positionCurupira[1].x % 8) == 3))
			uC[1] = 5;

		if(dxC[1] == 1 && ((positionCurupira[1].x % 8) == 4 || (positionCurupira[1].x % 8) == 5))
			uC[1] = 6;
           
		if(dxC[1] == 1 && ((positionCurupira[1].x % 8) == 6 || (positionCurupira[1].x % 8) == 7))
			uC[1] = 7;

		positionCurupira[0].x += round(((speedC*delta)/1000.0)*dxC[0]);
		positionCurupira[1].x += round(((speedC*delta)/1000.0)*dxC[1]);

		positionUrubu[0].x += round(((speedU*delta)/1000.0)*dxU[0]);
		positionUrubu[1].x += round(((speedU*delta)/1000.0)*dxU[1]);
		positionUrubu[2].x += round(((speedU*delta)/1000.0)*dxU[2]);
	}
}

void 
StageEnemy::release()
{
	SDL_DestroyTexture(m_texture);
}