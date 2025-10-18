#include "std_writer.h"

void StdWriter::Write(BlockPtr block)
{
    if (block->Empty()) return;

    // TODO :: ��-�������� ������� �� ������ �� IBlock, �� �� ������� �����������
    // ��������.
    const auto& commands = block->GetCommands();
    std::cout << "bulk: ";
    for (size_t i = 0; i < block->GetSizeBlock(); ++i)
    {
        std::cout << std::format("{}", commands[i]->GetCommnad());
        if (i < block->GetSizeBlock() - 1) std::cout << ", ";
    }
}