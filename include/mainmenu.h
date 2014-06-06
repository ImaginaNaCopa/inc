#ifndef MAINMENU_H
#define MAINMENU_H

#include "input.h"
#include "inputhandler.h"
#include "secondlayer.h"
#include "background.h"

using namespace input;

class MainMenu : public InputHandler, public SecondLayer
{
public:
	MainMenu();
	~MainMenu();

	void generateClips();
	void update();

	bool handle(SDL_Event& event);

	bool isSelected();
	bool checkCollision(int selection);

private:
	bool m_mouseSelect;
	bool m_mouseCollision;
	bool m_select;
	int m_selection;
	Background* m_background;
	SDL_Rect m_mouse;	
};

#endif // MAINMENU_H