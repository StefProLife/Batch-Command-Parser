#include <iostream>
#include <stdexcept>
#include <memory>
#include "network_adapter.h"
#include "generate_command.h"
#include "std_reader.h"
#include "std_writer.h"
#include "file_logger.h"
#include "parser.h"

int main(int argc, char const* argv[])
{
    if (argc < 2) return 0;

    std::string strArg = argv[1];
    size_t countPackageInBolock = 3;

    try
    {
        countPackageInBolock = std::stoul(strArg);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Invalid argument: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Out of range: " << e.what() << std::endl;
        return 1;
    }

    IGenerateCommand* pIGenerateCommand = new GenerateCommand();
    IReader* pReader = new StdReader();
    INetworkAdapter* pNetworkAdapter = new NetworkAdapter(pIGenerateCommand, pReader, countPackageInBolock);

    IWriter* pWriter = new StdWriter();
    ILogger& log = Logger::GetInstance();
    Parser parser = Parser(pNetworkAdapter, &(log), pWriter);
    parser.Run();

    return 0;
}