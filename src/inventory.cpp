#include "inventory.h"

using namespace std;

Inventory::Inventory() : ImageSprite()
{
	step("[Inventory] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(0,0,40,65);
	generateClips();
	m_qtdPotion = 0;
	m_qtdAlteredPotion = 0;

	m_currentItem = 0;
	m_referencedText = new Text(getFontTulpenOne(),getFontSize(1));
	m_referencedText->addText("#");
	m_referencedText->setColor(0, 0, 0, 255);
	m_referencedText->addPosition(38,28);
	m_potionText = new Text(getFontTulpenOne(),getFontSize(1));
	m_potionText->setColor(0, 0, 0, 255);
	m_potionText->addPosition(27, 72);
	m_alteredPotionText = new Text(getFontTulpenOne(),getFontSize(1));
	m_alteredPotionText->setColor(0, 0, 0, 255);
	m_alteredPotionText->addPosition(77, 72);
}

Inventory::~Inventory()
{
	step("[Inventory] Destroying.");
	delete m_alteredPotionText;
	delete m_potionText;
	delete m_referencedText;
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
		m_potionText->addText(to_string(getQtdPotion()));
	
		m_potionText->setTextNumber(0);
	
		m_potionText->drawText();
		m_potionText->removeText();
	}

	if (getQtdAlteredPotion() >= 0)
	{
		m_alteredPotionText->addText(to_string(getQtdAlteredPotion()));
	
		m_alteredPotionText->setTextNumber(0);
	
		m_alteredPotionText->drawText();
		m_alteredPotionText->removeText();
	}

	if(isCLeftItem())
	{
		falseCLeftItem();
		if(m_currentItem==0)
			m_currentItem=5;
		else
			m_currentItem--;
		if(m_currentItem==3)
			m_currentItem--;
	}
	if(isCRightItem())
	{
		falseCRightItem();
		if(m_currentItem==5)
			m_currentItem=0;
		else
			m_currentItem++;
		if(m_currentItem==3)
			m_currentItem++;
	}
	if(isCUsedItem())
	{
		falseCUseItem();
		if(m_currentItem==0)
			trueCItemOne();
		else if(m_currentItem==1)
			trueCItemTwo();
		else if(m_currentItem==2)
			trueCItemThree();
		else if(m_currentItem==4)
			trueCItemFive();
		else
			trueCItemSix();
	}

	m_referencedText->setPosition((38+(50*m_currentItem)),28);
	m_referencedText->drawText();
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
	m_qtdPotion += qtd;
}

int
Inventory::getQtdPotion()
{
	return m_qtdPotion;
}

void
Inventory::setQtdAlteredPotion(int qtd)
{
	m_qtdAlteredPotion += qtd;
}

int
Inventory::getQtdAlteredPotion()
{
	return m_qtdAlteredPotion;
}