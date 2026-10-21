	#include "WcCommand.h"

WcCommand::WcCommand(General* info) : Commands(info){}

string WcCommand::execute() {
	int number = 0;
	if (m_General->opt == "")throw NoOption();
	else if (m_General->opt != "c" && m_General->opt != "w") throw UnknownOption();

	string output = Commands::shared();

	if (m_General->opt == "c") {
		for (char c : output)number++;
	}
	else if (m_General->opt == "w") {
		istringstream stream(output);
		string inst;
		while (stream >> inst)number++;
	}
	else throw UnknownOption();
	return to_string(number);
}
