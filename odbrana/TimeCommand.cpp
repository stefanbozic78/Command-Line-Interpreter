#include "TimeCommand.h"
TimeCommand::TimeCommand(Gorica* info):  Commands(info) {}

string TimeCommand::execute() {
	if (!m_Gorica->arg.empty())throw UnaryPipe();
	string output = "";
	
	time_t now = time(nullptr);
	struct tm time;
	localtime_s(&time, &now);

	output += (time.tm_hour < 10 ? "0" : "") + to_string(time.tm_hour) + ":";
	output += (time.tm_min < 10 ? "0" : "") + to_string(time.tm_min) + ":";
	output += (time.tm_sec < 10 ? "0" : "") + to_string(time.tm_sec);

	return output;
}
