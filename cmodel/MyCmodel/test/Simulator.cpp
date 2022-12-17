#include "Simulator.hpp"
using namespace std;
Simulator::Simulator(const YAML::Node& Config)
{
    const YAML::Node DRAMCfg = Config["DRAM"];
    this->m_dram = new Dram(DRAMCfg["MemoryMap"]["Base"].as<uint64_t>(),
                          DRAMCfg["MemoryMap"]["Length"].as<uint64_t>());
}

Simulator::~Simulator(){
    delete this->m_dram;
}

void 
Simulator::Tick(){

}

Dram* 
Simulator::GetDRAM(){
    return this->m_dram;
}
