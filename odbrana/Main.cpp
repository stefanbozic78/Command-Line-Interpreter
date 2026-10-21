#include "Program.h"
#include "Commands.h"

using namespace std;

int main() {
	Program* prog = Program::getInstance();
	prog->program();

	prog->destroyInstance();
	Print::destroyInstance();
	ConsoleReader::destroyInstance();
	return 0;
}