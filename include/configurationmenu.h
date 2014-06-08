#ifndef CONFIGURATIONMENU_H
#define CONFIGURATIONMENU_H

#include "background.h"
#include "fontconfiguration.h"
#include "menu.h"
#include "inputhandler.h"
#include "secondlayer.h"
#include "text.h"

using namespace fontConfiguration;

class ConfigurationMenu : public Menu
{
public:
	ConfigurationMenu();
	~ConfigurationMenu();

	void generateClips();
	void update();

	//bool handle(SDL_Event& event);
	void generateIndexTexts();

private:
	Background* m_background;
	Text* m_textIndex;
	Text* m_textOption;
	Text* m_textTitle;
	Text* m_textApply;
};

#endif // CONFIGURATIONMENU_H