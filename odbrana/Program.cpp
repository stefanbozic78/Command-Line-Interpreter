
#include "Program.h"
#include "PromptCommand.h"

Program* Program::instance = nullptr;

Program::Program(){
	startSign = "$";
}

Program* Program::getInstance() {
	if (instance == nullptr) {
		instance = new Program();
	}
	return instance;
}

Program::~Program() = default;

void Program::destroyInstance() {
	delete instance;
	instance = nullptr;
}
string Program::getStartSign() const {
	return startSign;
}

void Program::setStartSign(string newSign) {
	startSign = newSign;
}

void Program::program() {
	this->program2("","","");
}
void Program::program2(string Istream1, string ostream1, string output1) {
	string output ="", line="", a ="", outputFile ="";
	ConsoleReader* reader = ConsoleReader::getInstance();
	Parser parser(reader);
	Print* print = Print::getInstance();
	//vector<string> cmds;
	int pipe_pos = 0;
	
	string originalOstream = ostream1;
	string originalOutput = output1;
	while (true) {

		try {

			reader->setIStream(Istream1);
			print->setOstream(ostream1, output1);

			if(Istream1.empty())cout << endl << startSign << " ";

			line = reader->readLine();

			if (line.empty() && (reader->isEnd() || reader->isAtEnd())) break;
			
			vector<size_t> lexer;

			lexer = parser.Lexer(line);

			if (!lexer.empty()) {

				string mistakes(line.length(), ' ');

				for (size_t index : lexer) {
					if (index >= 0 && index < line.length()) mistakes[index] = '^';
				}

				line += '\n' + mistakes;

				throw LexicalMistakes(line);
			}
			//std::unique_ptr<Commands> command;
			unique_ptr<Gorica> info = parser.parseCommand(line);
			if (info->input == "<")reader->setIStream(info->arg);

			vector<string> cmds = parser.Pipe(line);
			for (size_t i = 0; i < cmds.size();i++) {

				if (cmds.size() > 1) {
					info = parser.parseCommand(cmds[i]);
					info->pipe = 1;
					if (i > 0) {
						if (info->arg != "") throw ArgumentInPipe();
						info->arg = a;
						/*info->flag = "quote";*/
					}
				}


				if (info->output == ">" || info->output == ">>")
					print->setOstream(info->outputFile, info->output);

				unique_ptr<Commands> command;

				if (info->cmd == "time") command = make_unique<TimeCommand>(info.get());
				else if (info->cmd == "date") command = make_unique <DateCommand>(info.get());
				else if (info->cmd == "echo") command = make_unique <EchoCommand>(info.get());
				else if (info->cmd == "wc") command = make_unique <WcCommand>(info.get());
				else if (info->cmd == "touch") command = make_unique <TouchCommand>(info.get());
				else if (info->cmd == "prompt") command = make_unique < PromptCommand>(info.get());
				else if (info->cmd == "truncate") command = make_unique <TruncateCommand>(info.get());
				else if (info->cmd == "rm") command = make_unique <RmCommand>(info.get());
				else if (info->cmd == "tr") command = make_unique <TrCommand>(info.get());
				else if (info->cmd == "head") command = make_unique <HeadCommand>(info.get());
				else if (info->cmd == "batch") command = make_unique <BatchCommand>(info.get());
				

				else throw UnknownCommand(info->cmd);


				output = command->execute();
				
				if (info->cmd == "batch") {
					
					outputFile = info->outputFile;  // Sacuvam gde treba da ide output
				}
				else {
					// Za sve ostale komande radi normalno
					a = output;
					outputFile = info->outputFile;
				}
			}
			
			if (!Istream1.empty() && outputFile.empty()) {
				outputFile = originalOstream;
			}
			if (info->cmd != "batch") {
				print->realPrint(output, outputFile);
			}
		}
		catch (exception& e) {
			
			print->realPrint(e.what(), "");
		}
	}
	
}