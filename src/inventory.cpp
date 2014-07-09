#include "inventory.h"

using namespace std;

Inventory::Inventory() : ImageSprite()
{
	step("[Inventory] Constructing.");
	imagePath.assign("res/images/s_hud.png");
	generatePosition(0,0,40,65);
	m_qtdPotion = 0;
	m_qtdAlteredPotion = 0;
	m_qtdAntiTudo = 0;
	m_qtdBaterry = 0;
	m_qtdFreeboi = 0;
	m_qtdCup = 0;
	m_inCLogo = 0;
	m_qtdAntiBoss = 0;

	m_itemSprite = new Background("res/images/s_item.png");
	m_itemSprite->init();
	m_itemSprite->generatePosition(10,34,32,40);
	generateClips();

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
	m_antiTudoText = new Text(getFontTulpenOne(),getFontSize(1));
	m_antiTudoText->setColor(0, 0, 0, 255);
	m_antiTudoText->addPosition(127, 72);
	m_batteryText = new Text(getFontTulpenOne(),getFontSize(1));
	m_batteryText->setColor(0, 0, 0, 255);
	m_batteryText->addPosition(177, 72);
	m_freeboiText = new Text(getFontTulpenOne(),getFontSize(1));
	m_freeboiText->setColor(0, 0, 0, 255);
	m_freeboiText->addPosition(227, 72);
	m_cupText = new Text(getFontTulpenOne(),getFontSize(1));
	m_cupText->setColor(0, 0, 0, 255);
	m_cupText->addPosition(277, 72);
}

Inventory::~Inventory()
{
	step("[Inventory] Destroying.");
	delete m_cupText;
	delete m_freeboiText;
	delete m_batteryText;
	delete m_antiTudoText;
	delete m_alteredPotionText;
	delete m_potionText;
	delete m_referencedText;
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

	m_itemSprite->setOnlyClipNumber(0);
	m_itemSprite->generatePosition(16,34,26,33);

	if (getQtdPotion() > 0)
	{
		m_potionText->addText(to_string(getQtdPotion()));
	
		m_potionText->setTextNumber(0);
	
		m_potionText->drawText();
		m_potionText->removeText();

		m_itemSprite->drawInAlpha(255);
	}
	else
		m_itemSprite->drawInAlpha(50);

	m_itemSprite->setOnlyClipNumber(1);
	m_itemSprite->generatePosition(66,34,26,33);
	if (getQtdAlteredPotion() > 0)
	{
		m_alteredPotionText->addText(to_string(getQtdAlteredPotion()));
	
		m_alteredPotionText->setTextNumber(0);
	
		m_alteredPotionText->drawText();
		m_alteredPotionText->removeText();

		m_itemSprite->drawInAlpha(255);
	}
	else
		m_itemSprite->drawInAlpha(50);

	m_itemSprite->setOnlyClipNumber(2);
	m_itemSprite->generatePosition(116,34,26,33);
	if (getQtdAntiTudo() > 0)
	{
		m_antiTudoText->addText(to_string(getQtdAntiTudo()));
	
		m_antiTudoText->setTextNumber(0);
	
		m_antiTudoText->drawText();
		m_antiTudoText->removeText();

		m_itemSprite->drawInAlpha(255);
	}
	else
		m_itemSprite->drawInAlpha(50);

	m_itemSprite->setOnlyClipNumber(3);
	m_itemSprite->generatePosition(173,34,16,33);
	if (getQtdBattery() > 0)
	{
		m_batteryText->addText(to_string(getQtdBattery()));
	
		m_batteryText->setTextNumber(0);
	
		m_batteryText->drawText();
		m_batteryText->removeText();

		m_itemSprite->drawInAlpha(255);
	}
	else
		m_itemSprite->drawInAlpha(50);

	m_itemSprite->setOnlyClipNumber(4);
	m_itemSprite->generatePosition(214,42,33,16);
	if (getQtdFreeboi() > 0)
	{
		m_freeboiText->addText(to_string(getQtdFreeboi()));
	
		m_freeboiText->setTextNumber(0);
	
		m_freeboiText->drawText();
		m_freeboiText->removeText();

		m_itemSprite->drawInAlpha(255);
	}
	else
		m_itemSprite->drawInAlpha(50);

	m_itemSprite->setOnlyClipNumber(5);
	m_itemSprite->generatePosition(272,34,16,33);
	if (getQtdCup() > 0)
	{
		m_cupText->addText(to_string(getQtdCup()));
	
		m_cupText->setTextNumber(0);
	
		m_cupText->drawText();
		m_cupText->removeText();

		m_itemSprite->drawInAlpha(255);
	}
	else
		m_itemSprite->drawInAlpha(50);

	if (getQtdCup() == 4)
	{
		delete m_cupText;
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
	m_itemSprite->addClip(0,0,32,40);
	m_itemSprite->addClip(32,0,32,40);
	m_itemSprite->addClip(64,0,33,40);
	m_itemSprite->addClip(97,0,21,40);
	m_itemSprite->addClip(118,0,40,22);
	m_itemSprite->addClip(158,0,22,40);
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

void 
Inventory::setQtdAntiTudo(int qtd)
{
	m_qtdAntiTudo += qtd;
}

int 
Inventory::getQtdAntiTudo()
{
	return m_qtdAntiTudo;
}

void 
Inventory::setQtdBattery(int qtd)
{
	m_qtdBaterry += qtd;
	if(m_qtdBaterry<0)
		m_qtdBaterry=0;
}

int
Inventory::getQtdBattery()
{
	return m_qtdBaterry;
}

void 
Inventory::setQtdFreeboi(int qtd)
{
	m_qtdFreeboi += qtd;
}

int
Inventory::getQtdFreeboi()
{
	return m_qtdFreeboi;
}

void 
Inventory::setQtdCup(int qtd)
{
	m_qtdCup += qtd;
}

int
Inventory::getQtdCup()
{
	return m_qtdCup;
}

void 
Inventory::setIncLogo(bool inCLogo)
{
	m_inCLogo += inCLogo;
}

bool 
Inventory::getInCLogo()
{
	return m_inCLogo;
}

void 
Inventory::setQtdAntiBoss(int qtd)
{
	m_qtdAntiBoss += qtd;
}

int
Inventory::getQtdAntiBoss()
{
	return m_qtdAntiBoss;
}
