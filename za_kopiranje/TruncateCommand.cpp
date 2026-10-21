#include "TruncateCommand.h"

TruncateCommand::TruncateCommand(Gorica* info): Commands(info) {}

string TruncateCommand::execute(){

	if (m_Gorica->opt != "") throw UnknownOption();
	if (m_Gorica->input != "") throw NotAllowedInputRedirection();
	if (m_Gorica->arg == "") throw NotExistingArgument();

	string output = "";

	ifstream file(m_Gorica->arg);

	if (file.good()) {
		file.close();

		ofstream file;
		file.open(m_Gorica->arg, ios::out | ios::trunc);
		file.close();
	}
	else throw UnknownFile();
	return "";
}
