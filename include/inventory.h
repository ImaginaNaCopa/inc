#ifndef INVENTORY_H
#define INVENTORY_H

#include "imageload.h"
#include "caio.h"
#include "imagesprite.h"
#include "systemlogger.h"
#include "background.h"
#include "text.h"

using namespace std;

class Inventory : public ImageSprite
{
public:
	Inventory();
	~Inventory();

	void drawEach();
	void generateClips();
	void initInventory();
	void updateInventory();

	void setQtdPotion(int qtd);
	int getQtdPotion();
	void setQtdAlteredPotion(int qtd);
	int getQtdAlteredPotion();
	void setQtdAntiTudo(int qtd);
	int getQtdAntiTudo();
	void setQtdBattery(int qtd);
	int getQtdBattery();
	void setQtdFreeboi(int qtd);
	int getQtdFreeboi();
	void setQtdCup(int qtd);
	int getQtdCup();
	void setIncLogo(bool inCLogo);
	bool getInCLogo();
	void setQtdAntiBoss(int qtd);
	int getQtdAntiBoss();

private:
	int m_currentItem;
	int m_qtdPotion;
	int m_qtdAlteredPotion;
	int m_qtdAntiTudo;
	int m_qtdBaterry;
	int m_qtdFreeboi;
	int m_qtdCup;
	bool m_inCLogo;
	int m_qtdAntiBoss;

	Background* m_itemSprite;

	Text* m_potionText;
	Text* m_alteredPotionText;
	Text* m_antiTudoText;
	Text* m_batteryText;
	Text* m_freeboiText;
	Text* m_cupText;
	Text* m_referencedText;
};

#endif // INVENTORY_H
