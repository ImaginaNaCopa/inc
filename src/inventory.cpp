#include "imageload.h"
#include "inventory.h"
#include "systemlogger.h"

using namespace std;

Inventory::Inventory() : ImageSprite()
{
    item = new Item();

    step("[Inventory] Constructing.");
    imagePath.assign("res/images/s_hud.png");
    generatePosition(0,0,40,40);
    generateClips();
    isDrawn = false;
}

Inventory::~Inventory()
{
    step("[Inventory] Destroying.");
    delete item;
    release();
}

void 
Inventory::drawEach()
{
    item->drawItem();
    loop("[Inventory] Drawing each Inventory Rect.");
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
}

void
Inventory::initInventory()
{
    item->initItem();
}

void 
Inventory::updateInventory()
{
    loop("[Inventory] Updating Inventory.");
    item->updateItem();
}