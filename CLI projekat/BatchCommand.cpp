#include "BatchCommand.h"
#include "Parser.h" 
#include "Program.h"
BatchCommand::BatchCommand(General* info): Commands(info){}

string BatchCommand::execute()
{
    Program* program = Program::getInstance();
    Print* print = Print::getInstance();
    program->program2(m_General->arg,m_General->outputFile,m_General->output);
    return "123";
}
