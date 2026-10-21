#include "HeadCommand.h"

HeadCommand::HeadCommand(General* info): Commands(info) {}

string HeadCommand::execute()
{
	if (m_General->opt[0] != 'n') throw UnknownOption();
	m_General->opt = m_General->opt.substr(1, m_General->opt.length());
	int i = stoi(m_General->opt);
	string test = "", realOutput = "";
	stringstream output(shared());
	vector<string> list;
	while (getline(output,test,'\n'))list.push_back(test);
	if (list[0] == "") list.erase(list.begin());
	for (int j = 0; i > 0; j++,i--) realOutput += list[j] += " ";
	

	return realOutput;
}
