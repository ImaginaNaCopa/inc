#include "../include/userlogger.h"

namespace userLogger
{
	int maxHp = 3;
	int hp = 3;

	int commonTonic = 0;
	int alteredTonic = 0;
	int antiallTonic = 0;
	int battery = 0;
	int freeboiMeat = 0;
	int trophy = 0;
	int imaginaNaCopa = 0;

	void
	updateItem(int type, int quantity)
	{
		if(type==1)
			commonTonic = quantity;
		else if(type==2)
			alteredTonic = quantity;
		else if(type==3)
			antiallTonic = quantity;
		else if(type==4)
			battery = quantity;
		else if(type==5)
			freeboiMeat = quantity;
		else if(type==6)
			trophy = quantity;
		else if(type==7)
			imaginaNaCopa = quantity;
	}

	void
	updateMaxHealth(int currentMHP)
	{
		maxHp = currentMHP;
	}

	void
	updateHealth(int currentHP)
	{
		hp = currentHP;
	}

	int
	getItemQuantity(int type)
	{
		if(type==1)
			return commonTonic;
		else if(type==2)
			return alteredTonic;
		else if(type==3)
			return antiallTonic;
		else if(type==4)
			return battery;
		else if(type==5)
			return freeboiMeat;
		else if(type==6)
			return trophy;
		else if(type==7)
			return imaginaNaCopa;
		return -1;
	}

	int
	getCurrentMaxHealth()
	{
		return maxHp;
	}

	int
	getCurrentHealth()
	{
		return hp;
	}
}