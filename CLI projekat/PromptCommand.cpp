#include "PromptCommand.h"
#include "Program.h" 
PromptCommand::PromptCommand(General* info) : Commands(info) {}

string PromptCommand::execute() {
if (m_General->opt != "") throw UnknownOption();
if (m_General->input != "") throw NotAllowedInputRedirection();
if (m_General->arg == "") throw NotExistingArgument();

string output = "", sign = "";

Program* program = Program::getInstance();

if (m_General->flag == "quote") {
	sign += m_General->arg;
}
else {
	if (m_General->arg != "" && m_General->flag == "file") { 
		

		FileReader* reader = new FileReader(m_General->arg);

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
