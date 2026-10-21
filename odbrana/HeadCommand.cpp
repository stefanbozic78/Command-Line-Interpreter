#include "HeadCommand.h"

HeadCommand::HeadCommand(Gorica* info): Commands(info) {}

string HeadCommand::execute()
{
	if (m_Gorica->opt[0] != 'n') throw UnknownOption();
	m_Gorica->opt = m_Gorica->opt.substr(1, m_Gorica->opt.length());
	int i = stoi(m_Gorica->opt);
	string test = "", realOutput = "";
	stringstream output(shared());
	vector<string> list;
	while (getline(output,test,'\n'))list.push_back(test);
	if (list[0] == "") list.erase(list.begin());
	for (int j = 0; i > 0; j++,i--) realOutput += list[j] += " ";
	

	return realOutput;
}
