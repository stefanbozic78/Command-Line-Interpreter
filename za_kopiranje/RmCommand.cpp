#include "RmCommand.h"

RmCommand::RmCommand(Gorica* info): Commands(info){}

string RmCommand::execute() {
	if (m_Gorica->opt != "") throw UnknownOption();
	if (m_Gorica->input != "") throw NotAllowedInputRedirection();
	if (m_Gorica->arg == "") throw NotExistingArgument();

	ifstream file(m_Gorica->arg);

	if (file.good()) {
		file.close();

		if (remove(m_Gorica->arg.c_str()) != 0)
			cout << "\nGreska pri brisanju fajla!\n";
	}
	else throw UnknownFile();
	return "";
}


