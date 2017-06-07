#ifndef SEBASTIAO_H
#define SEBASTIAO_H

#include "../include/background.h"
#include "../include/imageeffect.h"

class Sebastiao : public ImageEffect
{
public:
	Sebastiao();
	~Sebastiao();

	void update();
	void setShoot(bool shoot);
	void setLevel(int level);

private:
	typedef enum {ONE, TWO, THREE, FOUR, FIVE} Level;
	void generateClips();
	
	Level m_level;

	bool m_shoot;

	Background* m_border;
	Background* m_background;
	Background* m_platform;
};

#endif // SEBASTIAO_H