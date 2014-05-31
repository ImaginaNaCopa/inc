#ifndef SYSTEMLOGGER_H
#define SYSTEMLOGGER_H

#include <string>

using namespace std;

namespace systemLogger
{
	void action(int type, const string& message);
	void condition(const string& message);
	void controls(int type, const string& message);
	void error(const string& message);
	void errorSDL(const string& message, const string& error);
	void image(const string& message);
	void log(const string& message);
	void loop(const string& messsage);
	void step(const string& message);

	bool isActionVerbose();
	bool isControlsVerbose();
	bool isConditionVerbose();
	bool isImageVerbose();
	bool isLoopVerbose();
	bool isStepVerbose();	

	void setVerbosity(bool action, bool controls, bool condition, bool image, bool loop, bool step);
}

#endif //SYSTEMLOGGER_H