#include <iostream>
#include "HEXParser/HEXParser.hpp"
#include "CPU/Pc_gen.hpp"
#include "CPU/Insn.hpp"
#include "CPU/Decode.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // const YAML::Node config = YAML::LoadFile(cmdParser.get<string>("config"));
    // Emulator::Simulator Simulator(config["Simulator"]);
    HEXParser test1(argv[1]);
    Dram *dram = new Dram(0, 65536+1);
    test1.Load(dram);
    IF if1;
    Pc_gen cpu_pc(1);
    while (1)
    {
        if (!dram->checkRange(cpu_pc.get_pc()))
        {
            break;
        }
        if1.load_pc(cpu_pc.get_pc());
        if1.Fetch(dram);
        cpu_pc.generate_pc();
        Insn ins1(if1);
        Decode(ins1);
    }
}
