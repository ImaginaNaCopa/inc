#include "behaviour.h"

namespace behaviour
{
	int normalSpeed = 110;
	int slowSpeed = round(normalSpeed/2);
	int quicklySpeed = 2*normalSpeed;

	int normalRotation = 1;
	int zombieRotation = 2*normalRotation;
	int agileRotation = 0;

	int commonDetection = 400;
	int dumbDetection = 0;
	int smartDetection = 1;

	int noPatrol = 0;
	int normalPatrol = 200;
	int extensePatrol = normalPatrol*2;

	int weakHealth = 1;
	int normalHealth = 3;
	int strongHealth = 5;
	int eventHealth = 0;	

	int simpleDamageType = 1;
	int poisonDamageType = 2;
	int instakillDamageType = 0;

	bool flying = true;
	bool terrestrial = false;

	bool hunter = true;
	bool passive = false;

	int
	haveSlowSpeed()
	{
		return slowSpeed;
	}

	int
	haveNormalSpeed()
	{
		return normalSpeed;
	}

	int
	haveQuicklySpeed()
	{
		return quicklySpeed;
	}

	int
	haveZombieRotation()
	{
		return zombieRotation;
	}

	int
	haveNormalRotation()
	{
		return normalRotation;
	}

	int
	haveAgileRotation()
	{
		return agileRotation;
	}

	int
	haveDumbDetection()
	{
		return dumbDetection;
	}

	int
	haveCommonDetection()
	{
		return commonDetection;
	}

	int
	haveSmartDetection()
	{
		return smartDetection;
	}

	int
	dontPatrol()
	{
		return noPatrol;
	}

	int
	doNormalPatrol()
	{
		return normalPatrol;
	}

	int
	doExtensePatrol()
	{
		return extensePatrol;
	}

	int
	haveWeakHealth()
	{
		return weakHealth;
	}

	int
	haveNormalHealth()
	{
		return normalHealth;
	}

	int
	haveStrongHealth()
	{
		return strongHealth;
	}

	int
	haveEventHealth()
	{
		return eventHealth;
	}

	int
	doSimpleDamageType()
	{
		return simpleDamageType;
	}

	int
	doPoisonDamageType()
	{
		return poisonDamageType;
	}

	int
	doInstakillDamageType()
	{
		return instakillDamageType;
	}

	bool
	isFlying()
	{
		return flying;
	}

	bool
	isTerrestrial()
	{
		return terrestrial;
	}

	bool
	isHunter()
	{
		return hunter;
	}
	
	bool
	isPassive()
	{
		return passive;
	}
}