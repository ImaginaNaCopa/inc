#ifndef INVENTORY_H
#define INVENTORY_H

#include "imageload.h"
#include "caio.h"
#include "imagesprite.h"
#include "systemlogger.h"
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

private:
	int qtdPotion;
	int qtdAlteredPotion;
	Text* potionText;
	Text* alteredPotionText;
};

#endif // INVENTORY_H
