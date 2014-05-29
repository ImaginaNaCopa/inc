#include <iostream>
#include "systemlogger.h"

using namespace std;

bool SystemLogger::isConditionPlusVerbose = false;
bool SystemLogger::isConditionVerbose = false;
bool SystemLogger::isLoopVerbose = false;
bool SystemLogger::isStepVerbose = false;

void
SystemLogger::condition(const string& message)
{
	if(SystemLogger::isConditionVerbose)
		cout << "Condition:	" << message << endl;
}

void
SystemLogger::conditionPlus(int type, const string& message)
{
	if(SystemLogger::isConditionPlusVerbose)
	{
		if(type==0)
			cout << "Mouse Action:	" << message << endl;
	}
}

void
SystemLogger::error(const string& message)
{
	cerr << "Error:		" << message << endl;
}

void
SystemLogger::errorSDL(const string& message, const string& error)
{
	cerr << "SDL Error:	" << message << endl;
	cerr << "-->	" << error << endl;
}

void
SystemLogger::log(const string& message)
{
	cerr << "System:	" << message << endl;
}

void
SystemLogger::loop(const string& message)
{
	if(SystemLogger::isLoopVerbose)
		cout << "Loop:	" << message << endl;
}

void
SystemLogger::step(const string& message)
{
	if(SystemLogger::isStepVerbose)
		cout << "Step:	" << message << endl;
}
