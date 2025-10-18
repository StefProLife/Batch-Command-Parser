#include "generate_command.h"
#include "command.h"

ICommand* GenerateCommand::CreateCommnad()
{
    return new Command();
}