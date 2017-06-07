#ifndef MAINMENU_H
#define MAINMENU_H

#include "../include/background.h"
#include "../include/audiohandler.h"
#include "../include/menu.h"
#include "../include/text.h"

using namespace audioHandler;

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