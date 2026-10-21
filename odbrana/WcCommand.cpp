	#include "WcCommand.h"

WcCommand::WcCommand(Gorica* info) : Commands(info){}

string WcCommand::execute() {
	int number = 0;
	if (m_Gorica->opt == "")throw NoOption();
	else if (m_Gorica->opt != "c" && m_Gorica->opt != "w") throw UnknownOption();

	string output = Commands::shared();

	if (m_Gorica->opt == "c") {
		for (char c : output)number++;
	}
	else if (m_Gorica->opt == "w") {
		istringstream stream(output);
		string inst;
		while (stream >> inst)number++;
	}
	else throw UnknownOption();
	return to_string(number);
}
