#include "../include/Macros.h"
#include "../memory/Dram.hpp"
class IF
{
private:
    uint32_t next_pc_in;
    uint32_t instruction_out;
public:
    void load_pc(uint32_t pc);
    void Fetch(Dram* dram);
    uint32_t get_ins();
    uint32_t get_address();
};