#ifndef MENU_H
#define MENU_H

#include "../include/controls.h"
#include "../include/secondlayer.h"

using namespace controls;

class Menu : public SecondLayer
{
public:
	Menu(const string& path);
	~Menu();

	bool isSelected();
	bool checkCollision(int selection, SDL_Rect targetPosition);	

protected:
	int m_selection;
	
	bool m_mouseSelect;
	bool m_mouseCollision;
	bool m_select;

	SDL_Rect m_mouse;
};

#endif // MENU_H