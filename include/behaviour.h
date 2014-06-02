#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <cmath>

namespace behaviour
{
	int haveSlowSpeed();
	int haveNormalSpeed();
	int haveQuicklySpeed();

	int haveZombieRotation();
	int haveNormalRotation();
	int haveAgileRotation();

	int haveDumbDetection();
	int haveCommonDetection();
	int haveSmartDetection();

	int dontPatrol();
	int doNormalPatrol();
	int doExtensePatrol();

	int haveWeakHealth();
	int haveNormalHealth();
	int haveStrongHealth();
	int haveEventHealth();

	int doSimpleDamageType();
	int doPoisonDamageType();
	int doInstakillDamageType();

	bool isFlying();
	bool isTerrestrial();

	bool isHunter();
	bool isPassive();
}

#endif // BEHAVIOUR_H