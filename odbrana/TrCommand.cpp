#include "TrCommand.h"
using namespace std;
TrCommand::TrCommand(Gorica* info): Commands(info) {}

string TrCommand::execute()
{
	string tmp, output = "";
	tmp = Commands::shared();
	string what = m_Gorica->what, with = m_Gorica->with;
	int pos = 0, i = 0;
	string word = "";
	while (pos < tmp.length()) {
		word += tmp[pos];
		if (tmp[pos] == what[i]) {
			i++; 
			if (i == what.length()) {
				output += with; i = 0;
				word = "";
			}
			

		}
		else {
			i = 0; output += word;
			word = "";
		}


		pos++;
	}
	return output;
}
