#include "Parser.h"
#include "Errors.h"

Parser::Parser(Reader* reader) : m_reader(reader) {}

Parser::~Parser() = default;

unique_ptr<General> Parser::parseCommand(const string& line) {

	size_t len = line.length();
	size_t i=0, num=0, pos = 0;
	auto info = make_unique <General>();
	string cmd= "", opt= "", arg= "", flag= "", of = "", what = "", with = "";
	int pipe = 0;

	if ((pos = line.find('|')) != string::npos && (num = count(line.begin(), line.begin() + pos, '"')) % 2 == 0) pipe = 1;
	else {

		if (!line.empty() && line[i] == '$')i++;

		//initial state
		passSpace(line, i, len);

		//first: take command
		getWord(line, i, len, cmd);

		//space from command to first next(arg,opt..)
		passSpace(line, i, len);

		if (cmd == "tr") {
			if (line[i] == '-') {
				trHelper(line, i, len , flag , what , with);
				flag = "";
			}
			else {
				//take file
				getWord(line, i, len, arg);
				passSpace(line, i, len);
				if (line[i] == '-') {
					trHelper(line, i, len, flag, what, with);
					flag = "file";
				}
				else throw UnknownOption();
			}
			proveraIzlaza(line, i, len, info->output);
			if (!info->output.empty()) { passSpace(line, i, len);getWord(line, i, len, of); }
		}
		//if it immediately encounters "" 
		else if (line[i] == '"' && i < len ) {
			getAllQuotes(line, i, len, arg, flag);
			proveraIzlaza(line, i, len, info->output);
			if (!info->output.empty()) {
				passSpace(line, i, len);
				getWord(line, i, len, of);
			}
		}
		//if a redirection occurs
		else if (line[i] == '<' || line[i] == '>') {
			if (line[i] == '<') {
				info->input = "<";flag = "file";
				passSpace(line, ++i, len);
				getWord(line, i, len, arg);
				passSpace(line, i, len);
			}

			proveraIzlaza(line, i, len, info->output);

			if (i < len) {
				passSpace(line, i, len);
				getWord(line, i, len, of);
			}
		}
		//else if for all -opt
		else if (line[i] == '-') {
			i++;
			getWord(line, i, len, opt);

			passSpace(line, i, len);

			//for quote
			if (line[i] == '"')
				getAllQuotes(line, i, len, arg, flag);
			//redirecting input
			else if (line[i] == '<' || isPath(line[i])) {
				if (line[i] == '<')i++;
				getWord(line, i, len, arg);
				passSpace(line, i, len);
				flag = "file";
			}
			//after "" and filePath, check for ">" and ">>"
			if (flag != "" && len > i && line[i] == '>') {
				proveraIzlaza(line, i, len, info->output);
				passSpace(line, i, len);
				getWord(line, i, len, of);
			}

		}


		else {
			if (i < len) {
				passSpace(line, i, len);
				getWord(line, i, len, arg);
				if (!arg.empty())flag = "file";
				passSpace(line, i, len);
				proveraIzlaza(line, i, len, info->output);
				if (!info->output.empty()) {
					passSpace(line, i, len);
					getWord(line, i, len, of);
				}
			}
		}
	}
		info->cmd = cmd;
		info->opt = opt;
		info->arg = arg;
		info->flag = flag;
		info->outputFile = of;
		info->what = what;
		info->with = with;
		info->pipe = pipe;
		return info;
}


vector<string> Parser::Pipe(string line) {

	vector<string> cmds = Pipe2(line, '|');
	return cmds;
}

vector<string> Parser::Pipe2(string line, char stopSymbol) {
	vector<string> cmds;
	size_t pos = 0, prevPos = 0, quote = 0;

	while ((pos = line.find(stopSymbol, pos)) != std::string::npos) {
		quote = count(line.begin() + prevPos, line.begin() + pos, '"');
		if (quote % 2 == 0) {
			cmds.push_back(line.substr(prevPos, pos - prevPos));
			prevPos = pos + 1;
		}
		pos++;

	}

	cmds.push_back(line.substr(prevPos));

	return cmds;
}



vector<size_t> Parser::Lexer(string line) {

	vector<size_t> bad;

		if (line.size() > 512) line = line.substr(0, 512);

		bool inQuotes = false;
		size_t quoteStart = 0;

		for (size_t i = 0; i < line.size(); i++) {
			char c = line[i];

			if (c == '"') {
				if (!inQuotes) { inQuotes = true; quoteStart = i; }
				else { inQuotes = false; }
				continue;
			}

			if (inQuotes) continue;

			//skip second >
			if (c == '>' && i + 1 < line.size() && line[i + 1] == '>') {
				i++;
				continue;
			}

			if (!isAllowedOutsideQuotes(c)) {
				bad.push_back(i);
			}
		}

		if (inQuotes) {
			bad.push_back(quoteStart);
		}

		return bad;
	}








void Parser::passSpace(string line, size_t &i, size_t len) {
	if (len <= i) return;
	while (i < len && isspace(line[i])) i++;
}
void Parser::getWord(string line, size_t &i, size_t len, string &cmd) {
	if (len <= i) return;
	while ((i < len && !isspace((unsigned char)line[i]) &&
		line[i] != '<' && line[i] != '>' && line[i] != '|')) cmd += line[i++];
}

void Parser::getQuotes(string line, size_t& i, size_t len, string& cmd) {
	if (len <= i) return;
	while (i < len && line[i] != '"') cmd += line[i++];
}
void Parser::getAllQuotes(string line, size_t& i, size_t len, string& cmd, string& flag) {
	getQuotes(line, ++i, len, cmd);
	if (i == len) throw NoQuoteEnd();
	flag = "quote";
	passSpace(line, ++i, len);
}


void Parser::proveraIzlaza(string line, size_t& i, size_t len,string& output) {
		if (i < len && line[i] == '>' ) { output = ">";i++; }
		if (i < len && line[i] == '>' ) { output = ">>";i++; }
	}
bool Parser::isPath(char c) {
	unsigned char uc = static_cast <unsigned char>(c);
	return isalnum(uc) || c == '.' || c == '/';
}

bool Parser::isAllowedOutsideQuotes(char c) {

	if (c == ' ' || c == '\t') return true;

	if (c == '|' || c == '<' || c == '>' || c == '"') return true;

	if (isalnum(c)) return true;

	if (c == '.' || c == '/' || c == '\\' || c == '_' || c == '-' || c == '$') return true;

	return false;
}

void Parser::trHelper(string line, size_t& i , size_t& len,string& flag, string& what, string& with ) {
	i++;
	getAllQuotes(line, i, len, what, flag);
	getAllQuotes(line, i, len, with, flag);

}