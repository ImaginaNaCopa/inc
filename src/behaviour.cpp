#include "behaviour.h"

namespace behaviour
{
	int normalSpeed = 55;
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
		loop("[Behaviour] Receiving Speed -> SLOW.");
		return slowSpeed;
	}

	int
	haveNormalSpeed()
	{
		loop("[Behaviour] Receiving Speed -> NORMAL.");
		return normalSpeed;
	}

	int
	haveQuicklySpeed()
	{
		loop("[Behaviour] Receiving Speed -> QUICKLY.");
		return quicklySpeed;
	}

	int
	haveZombieRotation()
	{
		loop("[Behaviour] Receiving Rotation -> ZOMBIE.");
		return zombieRotation;
	}

	int
	haveNormalRotation()
	{
		loop("[Behaviour] Receiving Rotation -> NORMAL.");
		return normalRotation;
	}

	int
	haveAgileRotation()
	{
		loop("[Behaviour] Receiving Rotation -> AGILE.");
		return agileRotation;
	}

	int
	haveDumbDetection()
	{
		loop("[Behaviour] Receiving Detection -> DUMB.");
		return dumbDetection;
	}

	int
	haveCommonDetection()
	{
		loop("[Behaviour] Receiving Detection -> COMMON.");
		return commonDetection;
	}

	int
	haveSmartDetection()
	{
		loop("[Behaviour] Receiving Detection -> SMART.");
		return smartDetection;
	}

	int
	dontPatrol()
	{
		loop("[Behaviour] Receiving Patrolling -> NO.");
		return noPatrol;
	}

	int
	doNormalPatrol()
	{
		loop("[Behaviour] Receiving Patrolling -> NORMAL.");
		return normalPatrol;
	}

	int
	doExtensePatrol()
	{
		loop("[Behaviour] Receiving Patrolling -> EXTENSE.");
		return extensePatrol;
	}

	int
	haveWeakHealth()
	{
		loop("[Behaviour] Receiving Health -> WEAK.");
		return weakHealth;
	}

	int
	haveNormalHealth()
	{
		loop("[Behaviour] Receiving Health -> NORMAL.");
		return normalHealth;
	}

	int
	haveStrongHealth()
	{
		loop("[Behaviour] Receiving Health -> STRONG.");
		return strongHealth;
	}

	int
	haveEventHealth()
	{
		loop("[Behaviour] Receiving Health -> EVENT.");
		return eventHealth;
	}

	int
	doSimpleDamageType()
	{
		loop("[Behaviour] Receiving Dam. Type -> SIMPLE.");
		return simpleDamageType;
	}

	int
	doPoisonDamageType()
	{
		loop("[Behaviour] Receiving Dam. Type -> POISON.");
		return poisonDamageType;
	}

	int
	doInstakillDamageType()
	{
		loop("[Behaviour] Receiving Dam. Type -> INSTAKILL.");
		return instakillDamageType;
	}

	bool
	isFlying()
	{
		loop("[Behaviour] Receiving Mov. Type -> FLYING.");
		return flying;
	}

	bool
	isTerrestrial()
	{
		loop("[Behaviour] Receiving Mov. Type -> TERRESTRIAL.");
		return terrestrial;
	}

	bool
	isHunter()
	{
		loop("[Behaviour] Receiving Sniffler Type -> HUNTER.");
		return hunter;
	}
	
	bool
	isPassive()
	{
		loop("[Behaviour] Receiving Sniffler Type -> PASSIVE.");
		return passive;
	}

	int
	getFlyingStandardHeight()
	{
		return getPlatformH()-300;
	}
}