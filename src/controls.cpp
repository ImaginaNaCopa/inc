#include "controls.h"

namespace controls
{
	SDL_Keycode openMenuKeyboard = SDLK_ESCAPE;
	SDL_Keycode leftAltKeyboard = SDLK_LALT;
	SDL_Keycode qKeyboard = SDLK_q;

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
	bool joystickOneCreated = false;
	bool joystickTwoCreated = false;
	bool joystickButtonUp = false;
	int numberOfJoysticks = 0;
	const int joystickDeadZone = 8000;

	int xAxis = 355;
	int yAxis = 255;

	bool openMenu = false;
	bool leftAlt = false;
	bool q = false;

	bool moveForward = false;
	bool moveBackward = false;
	bool jump = false;
	bool crouch = false;
	bool action = false;
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
		if((leftAlt==true && q==true) || quit==true)
		{
			releaseJoystickOne();
			releaseJoystickTwo();
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
		leftAlt = false;
		q = false;
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
	falseCAction()
	{
		action = false;
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

			if(sym==leftAltKeyboard){leftAlt = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
			else if(sym==qKeyboard){q = type == SDL_KEYDOWN ? true : false; keyUp = type == SDL_KEYUP ? true : false;}
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
		else if (getNumberOfJoysticks() > 0)
		{
			if (joystickOneCreated && joystickTwoCreated)
			{
				if(JOY_BUTTON_BUTTON==BUTTON_JOYSTICK_A){jump = JOY_BUTTON_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = JOY_BUTTON_TYPE == SDL_JOYBUTTONUP ? true : false;}
			}
			else if (joystickOneCreated && !joystickTwoCreated)
			{
			
				if (JOY_BUTTON_TYPE == SDL_JOYBUTTONDOWN || JOY_BUTTON_TYPE == SDL_JOYBUTTONUP)
				{
				
				//	cout << "back: " << leftAlt << endl;
					if(JOY_BUTTON_BUTTON==BUTTON_JOYSTICK_HOME){leftAlt = JOY_BUTTON_TYPE == SDL_JOYBUTTONDOWN ? true : false; keyUp = JOY_BUTTON_TYPE == SDL_JOYBUTTONUP ? true : false;}
				//	else if(JOY_BUTTON_BUTTON==BUTTON_JOYSTICK_BACK){q = JOY_BUTTON_STATE == SDL_PRESSED ? true : false; keyUp = JOY_BUTTON_STATE == SDL_RELEASED ? true : false;}
				//	else if(JOY_BUTTON_BUTTON==BUTTON_JOYSTICK_START){openMenu = JOY_BUTTON_STATE == SDL_PRESSED ? true : false; keyUp = JOY_BUTTON_STATE == SDL_RELEASED ? true : false;}
				//	else if(JOY_HAT_HAT==MOTION_JOYSTICK_HAT_RIGHT){moveForward = JOY_BUTTON_STATE == MOTION_JOYSTICK_HAT_RIGHT ? true : false; keyUp = SDL_JOYHATMOTION == MOTION_JOYSTICK_HAT_CENTERED ? true : false;}
				//	else if(JOY_HAT_HAT==MOTION_JOYSTICK_HAT_LEFT){moveBackward = JOY_BUTTON_STATE == MOTION_JOYSTICK_HAT_LEFT ? true : false; keyUp = SDL_JOYHATMOTION == MOTION_JOYSTICK_HAT_CENTERED ? true : false;}
				//	else if(JOY_BUTTON_BUTTON==BUTTON_JOYSTICK_A){jump = JOY_BUTTON_STATE == SDL_PRESSED ? true : false; keyUp = JOY_BUTTON_STATE == SDL_RELEASED ? true : false;}
				//	else if(JOY_BUTTON_BUTTON==BUTTON_JOYSTICK_B){crouch = JOY_BUTTON_STATE == SDL_PRESSED ? true : false; keyUp = JOY_BUTTON_STATE == SDL_RELEASED ? true : false;}
				//	else if(JOY_BUTTON_BUTTON==BUTTON_JOYSTICK_X){action = JOY_BUTTON_STATE == SDL_PRESSED ? true : false; keyUp = JOY_BUTTON_STATE == SDL_RELEASED ? true : false;}
					//else 
					//	key = false;
				//	cout << "Home: " << leftAlt << endl;
				//	cout << "Back: " << q << endl;
				//	cout << "start: " << openMenu << endl;
				//	cout << "frente: " << moveForward << endl;
				//	cout << "trás: " << moveBackward << endl;
				//	cout << "a: " << jump << endl;
				//	cout << "b: " << crouch << endl;
				//	cout << "x: " << action << endl;
				}
			}
			else
			{
				if (getNumberOfJoysticks() > 0)
				{
					createJoystickOne();
				}
				/*else if (getNumberOfJoysticks() == 2 && !joystickOneCreated)
				{
					createJoystickOne();
					createJoystickTwo();
				}
				else if (numberOfJoysticks == 2 && joystickOneCreated)
					createJoystickTwo();*/
			}
		}
	}

	void
	eventLoop()
	{
		loop("[Input] Beginning the event Handling Loop.");
		SDL_Event event;
		queue <SDL_Event> events;

		loop("[Input] Adding all Events in a Queue.");
		while (SDL_PollEvent(&event) != 0)
		{
			events.push(event);
		}

		loop("[Input] Handling each Event until Queue empty.");
		while(events.empty() == false)
		{
			event = events.front();
			events.pop();
			handle(event);
		}
	}
}