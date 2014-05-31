#include "enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy()
	: ImageSprite()
{
}

Enemy::~Enemy()
{

}

void
Enemy::update(Uint32 delta)
{
	cout << delta << endl;
}
