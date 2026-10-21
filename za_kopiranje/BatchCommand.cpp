#include "BatchCommand.h"
#include "Parser.h" 
#include "Program.h"
BatchCommand::BatchCommand(Gorica* info): Commands(info){}

string BatchCommand::execute()
{
    Program* program = Program::getInstance();
    Print* print = Print::getInstance();
    program->program2(m_Gorica->arg,m_Gorica->outputFile,m_Gorica->output);
    return "123";
}
