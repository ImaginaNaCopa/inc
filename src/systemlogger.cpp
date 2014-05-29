#include <iostream>
#include "systemlogger.h"

using namespace std;

bool SystemLogger::isStepVerbose = false;

void
SystemLogger::log(const string& message)
{
	cerr << "System:	" << message << endl;
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
SystemLogger::step(const string& message)
{
	if(SystemLogger::isStepVerbose==true)
	{
		cout << "Step: " << message << endl;
	}
}
