#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL2/SDL.h>
#include <queue>
#include "../include/systemlogger.h"

//Button
#define J_B_BUTTON event.jbutton.button
#define J_B_ID event.jbutton.which
#define J_B_TYPE event.jbutton.type
#define J_B_STATE event.jbutton.state

//Hat
#define J_H_HAT event.jhat.hat
#define J_H_ID event.jhat.which
#define J_H_TYPE event.jhat.type
#define J_H_VALUE event.jhat.value

//Sticks
#define J_A_AXIS event.jaxis.axis
#define J_A_VALUE event.jaxis.value
#define M_J_S_LEFT_X 0
#define M_J_S_LEFT_Y 1
#define M_J_S_RIGHT_X 2
#define M_J_S_RIGHT_Y 5
#define M_J_S_L2 4
#define M_J_S_R2 5

//JOYSTICK BUTTONS
#define B_J_ACTION 0
#define B_J_JUMP 1
#define B_J_CROUCH 2
#define B_J_USEITEM 3
#define B_J_LITEM 4
#define B_J_RITEM 5
#define B_J_SPECIAL 6
#define B_J_SHOOT 7
#define B_J_FEC 8
#define B_J_MENU 9
#define B_J_SEC 13

/*#define ADDED_NEW_JOYSTICK SDL_JOYDEVICEADDED
#define REMOVED_JOYSTICK SDL_JOYDEVICEREMOVED*/

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
	bool isCUsedItem();
	bool isCLeftItem();
	bool isCRightItem();
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
	void falseCaction();
	void falseCUseItem();
	void falseCLeftItem();
	void falseCRightItem();
	void falseCItemOne();
	void falseCItemTwo();
	void falseCItemThree();
	void falseCItemFour();
	void falseCItemFive();
	void falseCItemSix();
	void falseCShoot();
	void falseCSpecial();

	void trueCItemOne();
	void trueCItemTwo();
	void trueCItemThree();
	void trueCItemFour();
	void trueCItemFive();
	void trueCItemSix();

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
	typedef enum{ONE,TWO,NONE} QtdJ;
	void checkJoysticks();
	bool getJoystickButtonUp();
	void falseCJButtonUp();
	int getNumberOfJoysticks();
	void setNumberOfJoysticks(int quantity);
	void createJoystickOne();
	void createJoystickTwo();
	void releaseJoystickOne();
	void releaseJoystickTwo();
	bool isOneJoystick();
	bool areTwoJoysticks();

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