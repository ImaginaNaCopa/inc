#ifndef USERLOGGER_H
#define USERLOGGER_H

#include "../include/systemlogger.h"

using namespace systemLogger;

namespace userLogger
{
	void updateItem(int type, int quantity);
	void updateMaxHealth(int currentMHP);
	void updateHealth(int currentHP);

	int getItemQuantity(int type);
	int getCurrentMaxHealth();
	int getCurrentHealth();
}

#endif //USERLOGGER_H