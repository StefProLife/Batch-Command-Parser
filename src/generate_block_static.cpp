#include "generate_block_static.h"
#include "block_static.h"

IBlock* GenerateBolckStatic::CreateBlock()
{
    return new BlockStatic();
}