#include "enemy.h"

using namespace std;

Enemy::Enemy(int x, int y)
	: ImageSprite()
{
	m_box.x = x;
	m_box.y = y;
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void
Enemy::update(Uint32 delta)
{
}
