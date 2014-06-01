#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <cmath>

namespace behavior
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

#endif // BEHAVIOR_H