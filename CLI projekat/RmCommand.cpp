#include "RmCommand.h"

RmCommand::RmCommand(General* info): Commands(info){}

string RmCommand::execute() {
	if (m_General->opt != "") throw UnknownOption();
	if (m_General->input != "") throw NotAllowedInputRedirection();
	if (m_General->arg == "") throw NotExistingArgument();

	ifstream file(m_General->arg);

	if (file.good()) {
		file.close();

		if (remove(m_General->arg.c_str()) != 0)
			cout << "\nGreska pri brisanju fajla!\n";
	}
	else throw UnknownFile();
	return "";
}


