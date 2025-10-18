#include "generate_block_static.h"
#include "block_static.h"

IBlock* GenerateBlockStatic::CreateBlock()
{
    return new BlockStatic();
}