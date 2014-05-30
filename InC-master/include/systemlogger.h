#ifndef SYSTEMLOGGER_H
#define SYSTEMLOGGER_H
#include <string>

using namespace std;

class SystemLogger
{
public:
	static bool isStepVerbose;

	static void log(const string& message);
	static void error(const string& message);
	static void errorSDL(const string& message, const string& error);
	static void step(const string& message);
};

#endif //SYSTEMLOGGER_H