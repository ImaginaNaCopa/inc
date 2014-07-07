#ifndef MAINMENU_H
#define MAINMENU_H

#include "background.h"
#include "menu.h"

class MainMenu : public Menu
{
public:
	MainMenu();
	~MainMenu();

	void generateClips();
	void update();

private:
	Background* m_background;

};

#endif // MAINMENU_H