#include <iostream>
#include "command.h"

int main(int argc, char const* argv[])
{
    Command cmd("cmd 1");
    std::cout << cmd.GetCommnad() << std::endl;
    std::cout << cmd.GetTime() << std::endl;

    return 0;
}