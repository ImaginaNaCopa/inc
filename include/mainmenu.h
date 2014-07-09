#ifndef MAINMENU_H
#define MAINMENU_H

#include "background.h"
#include "menu.h"
#include "text.h"

class MainMenu : public Menu
{
public:
	MainMenu();
	~MainMenu();

	void generateClips();
	void update();

private:
	Background* m_background;
	Text* m_option;

};

#endif // MAINMENU_H