#include "../include/Macros.h"
class Pc_gen
{
private:
    uint32_t prev_pc;
    uint32_t next_pc_out;
public:
    Pc_gen(uint32_t pc);
    void generate_pc();
    uint32_t get_pc();
};