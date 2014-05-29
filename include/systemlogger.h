#ifndef SYSTEMLOGGER_H
#define SYSTEMLOGGER_H

#include <string>

using namespace std;

class SystemLogger
{
public:
	static bool isConditionPlusVerbose;
	static bool isConditionVerbose;
	static bool isLoopVerbose;
	static bool isStepVerbose;

	static void condition(const string& message);
	static void conditionPlus(int type, const string& message);
	static void error(const string& message);
	static void errorSDL(const string& message, const string& error);
	static void log(const string& message);
	static void loop(const string& messsage);
	static void step(const string& message);
};

#endif //SYSTEMLOGGER_H