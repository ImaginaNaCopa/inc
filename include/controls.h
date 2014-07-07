#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL2/SDL.h>
#include <queue>
#include "systemlogger.h"

using namespace systemLogger;

namespace controls
{
	bool anyCaioControl();

	bool isCKeyUp();
	bool isCButtonUp();

	bool isCExit();
	bool isCOpenedMenu();

	bool isCForwarded();
	bool isCBackwarded();
	bool isCJumped();
	bool isCCrouched();
	bool isCActioned();
	bool isCItemOne();
	bool isCItemTwo();
	bool isCItemThree();
	bool isCItemFour();
	bool isCItemFive();
	bool isCItemSix();
	bool isCShooted();
	bool isCSpecial();

	void falseCaioControl();

	void falseCKeyUp();
	void falseCButtonUp();

	void falseCExit();
	void falseCOpenMenu();

	void falseCForward();
	void falseCBackward();
	void falseCJump();
	void falseCCrouch();
	void falseCAction();
	void falseCItemOne();
	void falseCItemTwo();
	void falseCItemThree();
	void falseCItemFour();
	void falseCItemFive();
	void falseCItemSix();
	void falseCShoot();
	void falseCSpecial();

	SDL_Keycode getMForwardK();
	SDL_Keycode getMBackwardK();
	SDL_Keycode getJumpK();
	SDL_Keycode getCrouchK();
	SDL_Keycode getActionK();
	SDL_Keycode getItemOneK();
	SDL_Keycode getItemTwoK();
	SDL_Keycode getItemThreeK();
	SDL_Keycode getItemFourK();
	SDL_Keycode getItemFiveK();
	SDL_Keycode getItemSixK();

	void setMForwardK(SDL_Keycode newHotKey);
	void setMBackwardK(SDL_Keycode newHotKey);
	void setJumpK(SDL_Keycode newHotkey);
	void setCrouchK(SDL_Keycode newHotkey);
	void setActionK(SDL_Keycode newHotkey);
	void setItemOneK(SDL_Keycode newHotkey);
	void setItemTwoK(SDL_Keycode newHotkey);
	void setItemThreeK(SDL_Keycode newHotkey);
	void setItemFourK(SDL_Keycode newHotkey);
	void setItemFiveK(SDL_Keycode newHotkey);
	void setItemSixK(SDL_Keycode newHotkey);

	SDL_Rect updateKernelMotionM(SDL_Rect kernel);
	void updateMouseMotion(SDL_Rect &mouse);

	Uint8 getShootM();
	Uint8 getSpecialM();

	void handle(SDL_Event &event);
	void eventLoop();
}

#endif // CONTROLS_H