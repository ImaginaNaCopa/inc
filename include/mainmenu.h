#ifndef MAINMENU_H
#define MAINMENU_H

#include "background.h"
#include "menu.h"

class MainMenu :  public InputHandler, public Menu
{
public:
	MainMenu();
	~MainMenu();

	void generateClips();
	void update();

	bool handle(SDL_Event& event);

private:
	Background* m_background;
};

#endif // MAINMENU_H