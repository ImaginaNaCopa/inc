#ifndef MENU_H
#define MENU_H

#include "input.h"
#include "inputhandler.h"
#include "secondlayer.h"

using namespace input;

class Menu : public SecondLayer
{
public:
	Menu(const string& path);
	~Menu();

	bool isSelected();
	bool checkCollision(int selection, SDL_Rect targetPosition);	

protected:
	bool m_mouseSelect;
	bool m_mouseCollision;
	bool m_select;
	int m_selection;

	SDL_Rect m_mouse;
};

#endif // MENU_H