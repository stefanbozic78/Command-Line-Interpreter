#include "DateCommand.h"

DateCommand::DateCommand(General* info) : Commands(info) {}

string DateCommand::execute() {
	if (!m_General->arg.empty()) throw UnaryPipe();
	string output = "";

	time_t now = time(nullptr);
	struct tm date;
	localtime_s(&date, &now);

	output += (date.tm_mday < 10 ? "0" : "") + to_string(date.tm_mday) + ".";
	output += (date.tm_mon < 10 ? "0" : "") + to_string(date.tm_mon + 1) + ".";
	output += to_string(date.tm_year + 1900) + ".";

	return output;
}