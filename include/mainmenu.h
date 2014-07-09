#ifndef MAINMENU_H
#define MAINMENU_H

#include "background.h"
#include "audiohandler.h"
#include "menu.h"

class MainMenu : public Menu
{
public:
	MainMenu();
	~MainMenu();

	void generateClips();
	void update();
	void defineEffects();

private:
	AudioHandler* m_mainmenu;
	Background* m_background;

};

#endif // MAINMENU_H