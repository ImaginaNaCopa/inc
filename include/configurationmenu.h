#ifndef CONFIGURATIONMENU_H
#define CONFIGURATIONMENU_H

#include "../include/background.h"
#include "../include/fontconfiguration.h"
#include "../include/menu.h"
#include "../include/secondlayer.h"
#include "../include/text.h"

using namespace fontConfiguration;

class ConfigurationMenu : public Menu
{
public:
	ConfigurationMenu();
	~ConfigurationMenu();

	void generateClips();
	void update();

	void generateIndexTexts();

private:
	Background* m_background;
	Text* m_textIndex;
	Text* m_textOption;
	Text* m_textTitle;
	Text* m_textApply;
};

#endif // CONFIGURATIONMENU_H