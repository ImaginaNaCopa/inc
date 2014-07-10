#include "controls.h"
#include <math.h>
#include <iostream>

namespace controls
{
	SDL_Keycode openMenuKeyboard = SDLK_ESCAPE;
	SDL_Keycode firstExitCommandKeyboard = SDLK_LALT;
	SDL_Keycode secondExitCommandKeyboard = SDLK_q;

	SDL_Keycode moveForwardKeyboard = SDLK_d;
	SDL_Keycode moveBackwardKeyboard = SDLK_a;
	SDL_Keycode jumpKeyboard = SDLK_SPACE;
	SDL_Keycode crouchKeyboard = SDLK_s;
	SDL_Keycode actionKeyboard = SDLK_e;
	SDL_Keycode itemOneKeyboard = SDLK_1;
	SDL_Keycode itemTwoKeyboard = SDLK_2;
	SDL_Keycode itemThreeKeyboard = SDLK_3;
	SDL_Keycode itemFourKeyboard = SDLK_4;
	SDL_Keycode itemFiveKeyboard = SDLK_5;
	SDL_Keycode itemSixKeyboard = SDLK_6;

	Uint32 motionMouse = SDL_MOUSEMOTION;
	Uint8 shootMouse = SDL_BUTTON_LEFT;
	Uint8 specialMouse = SDL_BUTTON_RIGHT;

	SDL_Joystick* joystickOne = NULL;
	SDL_Joystick* joystickTwo = NULL;

	QtdJ currentJoysticksInUse = NONE;
	int numberOfJoysticks = 0;
	bool joystickOneCreated = false;
	bool joystickTwoCreated = false;
	bool joystickButtonUp = false;

	int xAxis = 355;
	int yAxis = 255;

	bool openMenu = false;
	bool firstExitCommand = false;
	bool secondExitCommand = false;

	bool moveForward = false;
	bool moveBackward = false;
	bool jump = false;
	bool crouch = false;
	bool action = false;
	bool useItem = false;
	bool leftItem = false;
	bool rightItem = false;
	bool itemOne = false;
	bool itemTwo = false;
	bool itemThree = false;
	bool itemFour = false;
	bool itemFive = false;
	bool itemSix = false;
	bool keyUp = false;
	bool key = false;
	bool quit = false;

	bool shoot = false;
	bool special = false;
	bool buttonUp = false;

	bool
	anyCaioControl()
	{
		return key;
	}

	bool
	isCKeyUp()
	{
		return keyUp;
	}

	bool
	isCButtonUp()
	{
		return buttonUp;
	}

	bool
	isCOpenedMenu()
	{
		return openMenu;
	}

	bool
	isCExit()
	{
		if((firstExitCommand==true && secondExitCommand==true) || quit==true)
		{
			return true;
		}
		return false;
	}

	bool
	isCForwarded()
	{
		return moveForward;
	}

	bool
	isCBackwarded()
	{
		return moveBackward;
	}

	bool
	isCJumped()
	{
		return jump;
	}

	bool
	isCCrouched()
	{
		return crouch;
	}

	bool
	isCActioned()
	{
		return action;
	}

	bool
	isCUsedItem()
	{
		return useItem;
	}

	bool
	isCLeftItem()
	{
		return leftItem;
	}

	bool
	isCRightItem()
	{
		return rightItem;
	}

	bool
	isCItemOne()
	{
		return itemOne;
	}

	bool
	isCItemTwo()
	{
		return itemTwo;
	}

	bool
	isCItemThree()
	{
		return itemThree;
	}

	bool
	isCItemFour()
	{
		return itemFour;
	}

	bool
	isCItemFive()
	{
		return itemFive;
	}

	bool
	isCItemSix()
	{
		return itemSix;
	}

	bool
	isCShooted()
	{
		return shoot;
	}

	bool
	isCSpecial()
	{
		return special;
	}

	void
	falseCaioControl()
	{
		key = false;
	}

	void
	falseCKeyUp()
	{
		keyUp = false;
	}
	void
	falseCButtonUp()
	{
		buttonUp = false;
	}

	void
	falseCExit()
	{
		firstExitCommand = false;
		secondExitCommand = false;
	}

	void
	falseCOpenMenu()
	{
		openMenu = false;
	}

	void
	falseCForward()
	{
		moveForward = false;
	}

	void
	falseCBackward()
	{
		moveBackward = false;
	}

	void
	falseCJump()
	{
		jump = false;
	}

	void
	falseCCrouch()
	{
		crouch = false;
	}

	void
	falseCaction()
	{
		action = false;
	}

	void
	falseCUseItem()
	{
		useItem = false;
	}

	void
	falseCLeftItem()
	{
		leftItem = false;
	}

	void
	falseCRightItem()
	{
		rightItem = false;
	}

	void
	falseCItemOne()
	{
		itemOne = false;
	}

	void
	falseCItemTwo()
	{
		itemTwo = false;
	}

	void
	falseCItemThree()
	{
		itemThree = false;
	}

	void
	falseCItemFour()
	{
		itemFour = false;
	}

	void
	falseCItemFive()
	{
		itemFive = false;
	}

	void
	falseCItemSix()
	{
		itemSix = false;
	}

	void
	falseCShoot()
	{
		shoot = false;
	}

	void
	falseCSpecial()
	{
		special = false;
	}

	void
	trueCItemOne()
	{
		itemOne = true;
	}

	void
	trueCItemTwo()
	{
		itemTwo = true;
	}

	void
	trueCItemThree()
	{
		itemThree = true;
	}

	void
	trueCItemFour()
	{
		itemFour = true;
	}

	void
	trueCItemFive()
	{
		itemFive = true;
	}

	void
	trueCItemSix()
	{
		itemSix = true;
	}	

	SDL_Keycode
	getMForwardK()
	{
		return moveForwardKeyboard;
	}

	SDL_Keycode
	getMBackwardK()
	{
		return moveBackwardKeyboard;
	}

	SDL_Keycode
	getJumpK()
	{
		return jumpKeyboard;
	}

	SDL_Keycode
	getCrouchK()
	{
		return crouchKeyboard;
	}

	SDL_Keycode
	getActionK()
	{
		return actionKeyboard;
	}

	SDL_Keycode
	getItemOneK()
	{
		return itemOneKeyboard;
	}

	SDL_Keycode
	getItemTwoK()
	{
		return itemTwoKeyboard;
	}

	SDL_Keycode
	getItemThreeK()
	{
		return itemThreeKeyboard;
	}

	SDL_Keycode
	getItemFourK()
	{
		return itemFourKeyboard;
	}

	SDL_Keycode
	getItemFiveK()
	{
		return itemFiveKeyboard;
	}

	SDL_Keycode
	getItemSixK()
	{
		return itemSixKeyboard;
	}

	void
	checkJoysticks()
	{
		if(SDL_NumJoysticks()>0)
		{
			if(!joystickOneCreated)
			{
				createJoystickOne();
				currentJoysticksInUse = ONE;
				step("[Imagina na Copa] Joystick #01 ready to use.");
			}
			if(SDL_NumJoysticks()>1 && !joystickTwoCreated)
			{
				createJoystickTwo();
				currentJoysticksInUse = TWO;
				step("[Imagina na Copa] Joystick #02 ready to use.");
			}
		}
		else
			currentJoysticksInUse = NONE;
	}

	bool
	isOneJoystick()
	{
		if(currentJoysticksInUse==ONE)
			return true;
		return false;
	}

	bool
	areTwoJoysticks()
	{
		if(currentJoysticksInUse==TWO)
			return true;
		return false;
	}

	bool 
	getJoystickButtonUp()
	{
		return joystickButtonUp;
	}

	void 
	falseCJButtonUp()
	{
		joystickButtonUp = false;
	}

	int 
	getNumberOfJoysticks()
	{
		return numberOfJoysticks = SDL_NumJoysticks();
	}

	void 
	setNumberOfJoysticks(int quantity)
	{
		numberOfJoysticks = quantity;
	}

	void 
	createJoystickOne()
	{
		joystickOne = SDL_JoystickOpen(0);
		joystickOneCreated = true;
	}

	void 
	createJoystickTwo()
	{
		joystickTwo = SDL_JoystickOpen(1);
		joystickTwoCreated = true;
	}

	void
	releaseJoystickOne()
	{
		SDL_JoystickClose(joystickOne);
		joystickOne = NULL;
		joystickOneCreated = false;
	}

	void
	releaseJoystickTwo()
	{
		SDL_JoystickClose(joystickTwo);
		joystickTwo = NULL;
		joystickTwoCreated = false;
	}

	void
	setMForwardK(SDL_Keycode newHotKey)
	{
		moveForwardKeyboard = newHotKey;
	}

	void
	setMBackwardK(SDL_Keycode newHotKey)
	{
		moveBackwardKeyboard = newHotKey;
	}

	void
	setJumpK(SDL_Keycode newHotKey)
	{
		jumpKeyboard = newHotKey;
	}

	void
	setCrouchK(SDL_Keycode newHotKey)
	{
		crouchKeyboard = newHotKey;
	}

	void
	setActionK(SDL_Keycode newHotKey)
	{
		actionKeyboard = newHotKey;
	}

	void
	setItemOneK(SDL_Keycode newHotKey)
	{
		itemOneKeyboard = newHotKey;
	}

	void
	setItemTwoK(SDL_Keycode newHotKey)
	{
		itemTwoKeyboard = newHotKey;
	}

	void
	setItemThreeK(SDL_Keycode newHotKey)
	{
		itemThreeKeyboard = newHotKey;
	}

	void
	setItemFourK(SDL_Keycode newHotKey)
	{
		itemFourKeyboard = newHotKey;
	}

	void
	setItemFiveK(SDL_Keycode newHotKey)
	{
		itemFiveKeyboard = newHotKey;
	}

	void
	setItemSixK(SDL_Keycode newHotKey)
	{
		itemSixKeyboard = newHotKey;
	}

	SDL_Rect
	updateKernelMotionM(SDL_Rect kernel)
	{
		SDL_Rect newKernel;
		newKernel.x = xAxis - 25;
		newKernel.y = yAxis - 25;
		newKernel.h = kernel.h;
		newKernel.w = kernel.w;
		return newKernel;
	}

	void
	updateMouseMotion(SDL_Rect &mouse)
	{
		mouse.x = xAxis;
		mouse.y = yAxis;
	}

	Uint8
	getShootM()
	{
		return shootMouse;
	}

	Uint8
	getSpecialM()
	{
		return specialMouse;
	}

	void
	handle(SDL_Event &event)
	{
		int type = event.type;
		if (type==SDL_QUIT)
		{
			quit = true;
		}
		else if(type==SDL_MOUSEBUTTONDOWN || type==SDL_MOUSEBUTTONUP)
		{
			Uint8 button = event.button.button;

			if(button==shootMouse){shoot = type == SDL_MOUSEBUTTONDOWN ? true : false; buttonUp = type == SDL_MOUSEBUTTONUP ? true : false;}
			else if(button==specialMouse){special = type == SDL_MOUSEBUTTONDOWN ? true : false; buttonUp = type == SDL_MOUSEBUTTONUP ? true : false;}
		}
		else if(type==SDL_MOUSEMOTION)
		{
			xAxis = event.motion.x;
			yAxis = event.motion.y;
		}
		else if(type==SDL_KEYDOWN || type==SDL_KEYUP)
		{
			key = true;
			SDL_Keycode sym = event.key.keysym.sym;

			if(sym==firstExitCommandKeyboard){firstExitCommand = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==secondExitCommandKeyboard){secondExitCommand = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==openMenuKeyboard){openMenu = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==moveForwardKeyboard){moveForward = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==moveBackwardKeyboard){moveBackward = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==jumpKeyboard){jump = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==crouchKeyboard){crouch = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==actionKeyboard){action = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==itemOneKeyboard){itemOne = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==itemTwoKeyboard){itemTwo = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==itemThreeKeyboard){itemThree = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==itemFourKeyboard){itemFour = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==itemFiveKeyboard){itemFive = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==itemSixKeyboard){itemSix = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else
				key = false;
		}
		else if((type == SDL_JOYBUTTONUP) || (type == SDL_JOYBUTTONDOWN) || (type == SDL_JOYAXISMOTION) || (type == SDL_JOYBALLMOTION) || (type == SDL_JOYHATMOTION))
		{
			if(areTwoJoysticks())
			{
				if(J_B_ID==SDL_JoystickInstanceID(joystickOne))
				{
					if(type == SDL_JOYBUTTONDOWN || type == SDL_JOYBUTTONUP)
					{
						if(J_B_BUTTON==B_J_FEC){firstExitCommand = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_SEC){secondExitCommand = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_ACTION){action = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_MENU){openMenu = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_JUMP){jump = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_CROUCH){crouch = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_USEITEM){useItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_LITEM){leftItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_RITEM){rightItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					}
					else if(type == SDL_JOYHATMOTION)
					{
						if(J_H_VALUE == SDL_HAT_CENTERED){jump = false, moveBackward = false; crouch = false; moveForward = false;}
						else if(J_H_VALUE & SDL_HAT_UP){jump = true;}
						else if(J_H_VALUE & SDL_HAT_RIGHT){moveForward = true;}
						else if(J_H_VALUE & SDL_HAT_DOWN){crouch = true;}
						else if(J_H_VALUE & SDL_HAT_LEFT){moveBackward = true;}
					}
					else if(type == SDL_JOYAXISMOTION)
					{
						if(J_A_AXIS == M_J_S_LEFT_X && J_A_VALUE > 0){moveForward = true;moveBackward = false;}
						else if(J_A_AXIS == M_J_S_LEFT_X && J_A_VALUE < 0){moveBackward = true;moveForward = false;}
						else if(J_A_AXIS == M_J_S_RIGHT_Y && J_A_VALUE < 0){crouch = true; jump = false;}
						else if(J_A_AXIS == M_J_S_RIGHT_Y && J_A_VALUE > 0){jump = true; crouch = false;}
						else if(J_A_VALUE == 0)
						{
							if(J_A_AXIS == M_J_S_LEFT_X){moveForward = false; moveBackward = false;}
							if(J_A_AXIS == M_J_S_RIGHT_Y){crouch = false; jump = false;}
						}
					}
				}
				else if(J_B_ID==SDL_JoystickInstanceID(joystickTwo))
				{
					if(type == SDL_JOYBUTTONDOWN || type == SDL_JOYBUTTONUP)
					{
						if(J_B_BUTTON==B_J_FEC){firstExitCommand = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_SEC){secondExitCommand = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_MENU){openMenu = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_SPECIAL){special = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_SHOOT){shoot = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_USEITEM){useItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_LITEM){leftItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
						else if(J_B_BUTTON==B_J_RITEM){rightItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					}
				}
				else
					step("[Imagina na Copa] Unknown Joystick in use.");
			}
			else if(isOneJoystick())
			{
				if(type == SDL_JOYBUTTONDOWN || type == SDL_JOYBUTTONUP)
				{
					if(J_B_BUTTON==B_J_FEC){firstExitCommand = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_SEC){secondExitCommand = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_ACTION){action = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_MENU){openMenu = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_SPECIAL){special = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_SHOOT){shoot = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_JUMP){jump = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_CROUCH){crouch = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_USEITEM){useItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_LITEM){leftItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
					else if(J_B_BUTTON==B_J_RITEM){rightItem = J_B_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = J_B_TYPE == SDL_JOYBUTTONUP ? true : false;}
				}
				else if(type == SDL_JOYHATMOTION)
				{
					if(J_H_VALUE == SDL_HAT_CENTERED){jump = false, moveBackward = false; crouch = false; moveForward = false;}
					else if(J_H_VALUE & SDL_HAT_UP){jump = true;}
					else if(J_H_VALUE & SDL_HAT_RIGHT){moveForward = true;}
					else if(J_H_VALUE & SDL_HAT_DOWN){crouch = true;}
					else if(J_H_VALUE & SDL_HAT_LEFT){moveBackward = true;}
				}
				else if(type == SDL_JOYAXISMOTION)
				{
					if(J_A_AXIS == M_J_S_LEFT_X && J_A_VALUE > 0){moveForward = true;moveBackward = false;}
					else if(J_A_AXIS == M_J_S_LEFT_X && J_A_VALUE < 0){moveBackward = true;moveForward = false;}
					else if(J_A_VALUE == 0)
					{
						if(J_A_AXIS == M_J_S_LEFT_X){moveForward = false; moveBackward = false;}
					}
				}
			}
			else
				step("[Imagina na Copa] Unknown Joystick in use.");
		}
		else if(type == SDL_JOYDEVICEADDED)
		{
			checkJoysticks();
		}
		else if(type == SDL_JOYDEVICEREMOVED)
		{
			if(event.jdevice.which == SDL_JoystickInstanceID(joystickOne) && joystickTwoCreated)
			{
				step("[Imagina na Copa] Joystick #01 removed.");
				step("[Imagina na Copa] --> Redefining Joystick #02 to #01.");
				releaseJoystickTwo();
				releaseJoystickOne();
				checkJoysticks();
			}
			else if(event.jdevice.which == SDL_JoystickInstanceID(joystickOne))
			{
				step("[Imagina na Copa] Joystick #01 removed.");
				releaseJoystickOne();
				checkJoysticks();
			}
			else if(event.jdevice.which == SDL_JoystickInstanceID(joystickTwo))
			{
				step("[Imagina na Copa] Joystick #02 removed.");
				releaseJoystickTwo();
				releaseJoystickOne();
				checkJoysticks();
			}
		}
	}

	void
	eventLoop()
	{
		if(areTwoJoysticks())
		{
			xAxis=400+((int)(SDL_JoystickGetAxis(joystickTwo,M_J_S_LEFT_X)*0.012207218));
			yAxis=300+((int)(SDL_JoystickGetAxis(joystickTwo,M_J_S_LEFT_Y)*0.012207218));
		}
		else if(isOneJoystick())
		{
			xAxis=400+((int)(SDL_JoystickGetAxis(joystickOne,M_J_S_RIGHT_X)*0.012207218));
			yAxis=300+((int)(SDL_JoystickGetAxis(joystickOne,M_J_S_RIGHT_Y)*0.012207218));
		}
		//loop("[Input] Beginning the event Handling Loop.");
		SDL_Event event;
		queue <SDL_Event> events;
		//loop("[Input] Adding all Events in a Queue.");
		while (SDL_PollEvent(&event) != 0)
		{
			events.push(event);
		}

		//loop("[Input] Handling each Event until Queue empty.");
		while(events.empty() == false)
		{
			event = events.front();
			events.pop();
			handle(event);
		}
	}
}