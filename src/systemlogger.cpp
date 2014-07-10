#include <iostream>
#include "systemlogger.h"

namespace systemLogger
{
	bool actionVerbosity = false;
	bool controlsVerbosity = false;
	bool conditionVerbosity = false;
	bool imageVerbosity = false;
	bool loopVerbosity = false;
	bool stepVerbosity = false;

	void
	action(int type, const string& message)
	{
		if(isActionVerbose())
		{
			switch(type)
			{
				case 0:
					cout << "Caio Action:	" << message << endl;
				case 1:
					cout << "Sebastiao Action:	" << message << endl;
				case 2:
					cout << "Special Action:	" << message << endl;
			}
		}
	}
	void
	condition(const string& message)
	{
		if(isConditionVerbose())
			cout << "Condition:	" << message << endl;
	}

	void
	controls(int type, const string& message)
	{
		if(isControlsVerbose())
		{
			switch(type)
			{
				case 0:
					cout << "Mouse Action:	" << message << endl;
				case 1:
					cout << "Keyboard Action:	" << message << endl;
				case 2:
					cout << "Joystick Action:	" << message << endl;
			}
		}
	}

	void
	error(const string& message)
	{
		cerr << "Error:		" << message << endl;
	}

	void
	errorSDL(const string& message, const string& error)
	{
		cerr << "SDL Error:	" << message << endl;
		cerr << "-->	" << error << endl;
	}

	void
	image(const string& message)
	{
		if(isImageVerbose())
			cout << "Image:	" << message << endl; 
	}

	void
	log(const string& message)
	{
		cout << "System:	" << message << endl;
	}

	void
	loop(const string& message)
	{
		if(isLoopVerbose())
			cout << "Loop:	" << message << endl;
	}

	void
	step(const string& message)
	{
		if(isStepVerbose())
			cout << message << endl;
	}

	void
	setVerbosity(bool action, bool controls, bool condition, bool image, bool loop, bool step)
	{
		actionVerbosity = action;
		controlsVerbosity = controls;
		conditionVerbosity = condition;
		imageVerbosity = image;
		loopVerbosity = loop;
		stepVerbosity = step;
	}

	bool
	isActionVerbose()
	{
		return actionVerbosity;
	}

	bool
	isControlsVerbose()
	{
		return controlsVerbosity;
	}

	bool
	isConditionVerbose()
	{
		return conditionVerbosity;
	}

	bool
	isImageVerbose()
	{
		return imageVerbosity;
	}

	bool isLoopVerbose()
	{
		return loopVerbosity;
	}

	bool
	isStepVerbose()
	{
		return stepVerbosity;
	}	
}
