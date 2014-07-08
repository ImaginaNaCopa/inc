#include "inventory.h"

using namespace std;

Inventory::Inventory() : ImageSprite()
{
    step("[Inventory] Constructing.");
    imagePath.assign("res/images/s_hud.png");
    generatePosition(0,0,40,65);
    generateClips();
    qtdPotion = 0;
    qtdAlteredPotion = 0;

    potionText = new Text(getFontTulpenOne(),getFontSize(1));
    potionText->setColor(0, 0, 0, 255);
    alteredPotionText = new Text(getFontTulpenOne(),getFontSize(1));
    alteredPotionText->setColor(0, 0, 0, 255);
}

Inventory::~Inventory()
{
    step("[Inventory] Destroying.");
    release();
}

void 
Inventory::drawEach()
{
    loop("[Inventory] Drawing each Inventory Rect.");
    
    m_position.x = 10;
    m_position.y = 30;
    draw();
    m_position.x += 10 + m_position.w;
    draw();
    m_position.x += 10 + m_position.w;
    draw();
    m_position.x += 10 + m_position.w;
    draw();
    m_position.x += 10 + m_position.w;
    draw();
    m_position.x += 10 + m_position.w;
    draw();

    if (getQtdPotion() >= 0)
    {
        potionText->addPosition(27, 72);
        potionText->addText(to_string(getQtdPotion()));
    
        potionText->setPositionNumber(0);
        potionText->setTextNumber(0);
    
        potionText->drawText();
        potionText->removeText();
    }

    if (getQtdAlteredPotion() >= 0)
    {
        alteredPotionText->addPosition(77, 72);
        alteredPotionText->addText(to_string(getQtdAlteredPotion()));
    
        alteredPotionText->setPositionNumber(0);
        alteredPotionText->setTextNumber(0);
    
        alteredPotionText->drawText();
        alteredPotionText->removeText();
    }
}

void
Inventory::generateClips()
{
    step("[Inventory] Generating Sprite Clips.");
    addClip(0,45,40,65);
}

void 
Inventory::updateInventory() 
{
     
}

void
Inventory::setQtdPotion(int qtd)
{
    qtdPotion += qtd;
}

int
Inventory::getQtdPotion()
{
    return qtdPotion;
}

void
Inventory::setQtdAlteredPotion(int qtd)
{
    qtdAlteredPotion += qtd;
}

int
Inventory::getQtdAlteredPotion()
{
    return qtdAlteredPotion;
}
