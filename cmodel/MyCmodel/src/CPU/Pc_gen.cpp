#include "Pc_gen.hpp"
Pc_gen::Pc_gen(uint32_t pc)
{
    next_pc_out = pc;
    prev_pc = pc;
}
void
Pc_gen::generate_pc()
{
    next_pc_out = prev_pc + 4;
    prev_pc = next_pc_out;
}

uint32_t
Pc_gen::get_pc()
{
    return next_pc_out;
}