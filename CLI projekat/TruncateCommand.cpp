#include "TruncateCommand.h"

TruncateCommand::TruncateCommand(General* info): Commands(info) {}

string TruncateCommand::execute(){

	if (m_General->opt != "") throw UnknownOption();
	if (m_General->input != "") throw NotAllowedInputRedirection();
	if (m_General->arg == "") throw NotExistingArgument();

	string output = "";

	ifstream file(m_General->arg);

	if (file.good()) {
		file.close();

		ofstream file;
		file.open(m_General->arg, ios::out | ios::trunc);
		file.close();
	}
	else throw UnknownFile();
	return "";
}
