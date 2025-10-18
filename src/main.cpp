#include <iostream>
#include <stdexcept>
#include <memory>
#include "network_adapter.h"
#include "generate_command.h"
#include "generate_block_static.h"
#include "std_reader.h"
#include "std_writer.h"
#include "file_logger.h"
#include "parser.h"

int main(int argc, char const* argv[])
{
    //if (argc < 1) return 0;

    //std::string strArg = argv[1];
    size_t countPackageInBolock = 3;

    //try
    //{
    //    countPackageInBolock = std::stoul(strArg);
    //}
    //catch (const std::invalid_argument& e)
    //{
    //    std::cerr << "Invalid argument: " << e.what() << std::endl;
    //}
    //catch (const std::out_of_range& e)
    //{
    //    std::cerr << "Out of range: " << e.what() << std::endl;
    //}

    IGenerateCommand* pIGenerateCommand = new GenerateCommand();
    IGenerateBolck* pIGenerateBolck = new GenerateBolckStatic();
    IReader* pReader = new StdReader();
    INetworkAdapter* pNetworkAdapter = new NetworkAdapter(pIGenerateCommand, pIGenerateBolck, pReader, countPackageInBolock);
    
    IWriter* pWriter = new StdWriter();
    ILogger& log = Logger::GetInstance();
    Parser* parser = new Parser(pNetworkAdapter, &(log), pWriter);
    parser->Run();

    return 0;
}