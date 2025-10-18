#include "Igenerate_command.h"

class GenerateCommand : public IGenerateCommand
{
public:
    GenerateCommand() = default;
public:
    ICommand* CreateCommnad() override;
};