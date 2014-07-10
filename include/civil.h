#ifndef CIVIL_H
#define CIVIL_H

#include "audiohandler.h"
#include "imageeffect.h"

using namespace audioHandler;

class Civil : public ImageEffect
{
public:
	Civil(int item, int tipo, int earlyPosition);
	~Civil();

	void update();
	int getItem();
	bool isSafe();
	void saved();
	bool isRunned();
	int getTipo();

private:
	int calculatePosition(int direction);
	void generateClips();
	void savingCivil();
	
	void grounded();
	void moving();
	void stoped();
	void stopedCivilFour();
	void stopedCivilSix();
	void civilOneMove();
	void civilTwoMove();
	void civilThreeMove();
	void civilFourMove();
	void civilFiveMove();
	void civilSixMove();

	typedef enum {GROUNDED, MOVING, STOPED} State;
	State m_state;
	
	bool m_safe;
	bool m_runned;
	bool gotUp;
	bool m_times;

	int m_item;
	int m_tipo;
};

#endif //CIVIL_H