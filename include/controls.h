#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL2/SDL.h>
#include <queue>
#include "systemlogger.h"

//Button
#define JOY_BUTTON_BUTTON event.jbutton.button
#define JOY_BUTTON_WHICH event.jbutton.which
#define JOY_BUTTON_TYPE event.jbutton.type
#define JOY_BUTTON_STATE event.jbutton.state

//Hat
#define JOY_HAT_HAT event.jhat.hat
#define JOY_HAT_TYPE event.jhat.type
#define JOY_HAT_VALUE event.jhat.value

//Sticks
#define MOTION_JOYSTICK SDL_JOYAXISMOTION
#define MOTION_JOYSTICK_STICK_LEFT_X 0
#define MOTION_JOYSTICK_STICK_LEFT_Y 1
#define MOTION_JOYSTICK_STICK_RIGHT_X 2
#define MOTION_JOYSTICK_STICK_RIGHT_Y 3
#define MOTION_JOYSTICK_STICK_RT 4
#define MOTION_JOYSTICK_STICK_LT 5

//D-Pad
#define MOTION_JOYSTICK_HAT SDL_JOYHATMOTION
#define MOTION_JOYSTICK_HAT_UP SDL_HAT_UP
#define MOTION_JOYSTICK_HAT_DOWN SDL_HAT_DOWN
#define MOTION_JOYSTICK_HAT_LEFT SDL_HAT_LEFT
#define MOTION_JOYSTICK_HAT_RIGHT SDL_HAT_RIGHT
#define MOTION_JOYSTICK_HAT_LEFTUP SDL_HAT_LEFTUP
#define MOTION_JOYSTICK_HAT_UP SDL_HAT_UP
#define MOTION_JOYSTICK_HAT_RIGHTUP SDL_HAT_RIGHTUP
#define MOTION_JOYSTICK_HAT_LEFT SDL_HAT_LEFT
#define MOTION_JOYSTICK_HAT_CENTERED SDL_HAT_CENTERED
#define MOTION_JOYSTICK_HAT_RIGHT SDL_HAT_RIGHT
#define MOTION_JOYSTICK_HAT_LEFTDOWN SDL_HAT_LEFTDOWN
#define MOTION_JOYSTICK_HAT_DOWN SDL_HAT_DOWN
#define MOTION_JOYSTICK_HAT_RIGHTDOWN SDL_HAT_RIGHTDOWN

//XBox Buttons
#define BUTTON_JOYSTICK_A 0
#define BUTTON_JOYSTICK_B 1
#define BUTTON_JOYSTICK_X 2
#define BUTTON_JOYSTICK_Y 3
#define BUTTON_JOYSTICK_LB 4
#define BUTTON_JOYSTICK_RB 5
#define BUTTON_JOYSTICK_BACK 6
#define BUTTON_JOYSTICK_START 7
#define BUTTON_JOYSTICK_HOME 8
#define BUTTON_JOYSTICK_STICK1 9
#define BUTTON_JOYSTICK_STICK2 10

#define ADDED_NEW_JOYSTICK SDL_JOYDEVICEADDED
#define REMOVED_JOYSTICK SDL_JOYDEVICEREMOVED

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

	//Controle XBox
	bool getJoystickButtonUp();
	void falseCJButtonUp();
	int getNumberOfJoysticks();
	void setNumberOfJoysticks(int quantity);
	void createJoystickOne();
	void createJoystickTwo();
	void releaseJoystickOne();
	void releaseJoystickTwo();

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