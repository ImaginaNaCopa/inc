#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "imageload.h"
#include "inventory.h"
#include "systemlogger.h"

using namespace std;

Inventory::Inventory() : ImageSprite()
{
    imagePath.clear();
    imagePath.assign("res/images/s_hud.png");
    generatePosition(0,0,40,40);
    generateClips();
    isDrawn = false;
}

Inventory::~Inventory()
{
}

void 
Inventory::drawEach()
{
    m_position.x = 10;
    m_position.y = 30;
    draw();
    m_position.x += 5 + m_position.w;
    draw();
    m_position.x += 5 + m_position.w;
    draw();
    m_position.x += 5 + m_position.w;
    draw();
    m_position.x += 5 + m_position.w;
    draw();
    m_position.x += 5 + m_position.w;
    draw();
}

void
Inventory::generateClips()
{
    step("[Inventory] Generating Sprite Clips.");
    addClip(0,15,m_position.w,m_position.h);
    step("[Inventory] Finished Generating Sprite Clips.");
}