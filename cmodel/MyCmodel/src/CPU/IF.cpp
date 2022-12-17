#include "IF.hpp"
#include "../memory/Dram.hpp"

void IF::load_pc(uint32_t pc)
{
    this->next_pc_in = pc;
}

void IF::Fetch(Dram *dram)
{
    instruction_out = 0;
    for (uint32_t i = next_pc_in; i < next_pc_in + 4; i++)
    {
        instruction_out = instruction_out << 8;
        instruction_out += (uint32_t)dram->read(i);
    }
#ifdef DEBUG
    if (next_pc_in < 100)
    {
        printf("address: 0x%x   instruction: ",0x80000000+(next_pc_in - 1));
        for (int i = 31; i >= 0; i--)
        {
            std::cout << ((instruction_out >> i) & 1);
        }
        std::cout<<std::endl;
    }
#endif
}

uint32_t IF::get_ins()
{
    return this->instruction_out;
}

uint32_t IF::get_address()
{
    return 0x80000000+(next_pc_in - 1);
}