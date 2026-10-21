#include "PromptCommand.h"
#include "Program.h" 
PromptCommand::PromptCommand(Gorica* info) : Commands(info) {}

string PromptCommand::execute() {
if (m_Gorica->opt != "") throw UnknownOption();
if (m_Gorica->input != "") throw NotAllowedInputRedirection();
if (m_Gorica->arg == "") throw NotExistingArgument();

string output = "", sign = "";

Program* program = Program::getInstance();

if (m_Gorica->flag == "quote") {
	sign += m_Gorica->arg;
}
else {
	if (m_Gorica->arg != "" && m_Gorica->flag == "file") {//ako treba da ulaz bude samo na 
		//< , onda staviti m_Gorica->input == "<";

		FileReader* reader = new FileReader(m_Gorica->arg);

		if (!reader->isFileOpen()) throw UnknownFile();

		while (!reader->isEnd()) {
			string line = reader->readLine();
			sign += line;
		}

		delete reader;

	}
}

program->setStartSign(sign);

return output;
}
