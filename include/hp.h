#ifndef HP_H
#define HP_H

#include "../include/imagesprite.h"
#include "../include/userlogger.h"

using namespace userLogger;

class Hp : public ImageSprite
{
public:
	Hp();
	~Hp();

	void generateClips();
	void drawEach();
	void setHp(int health);
	void setMaxHp(int max);
	void setPoisonedHp(int poison);
	int getHp();
protected:
	int hp;
	int maxHp;
	int poisonedHp;
};

#endif // HP_H