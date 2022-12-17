#ifndef __SIMULATOR_HH__
#define __SIMULATOR_HH__

#include "memory/Dram.hpp"
#include "include/yaml-cpp/yaml.h"

class Simulator
{
private:
    Dram *m_dram;

public:
    Simulator(const YAML::Node& Config);

    ~Simulator();

    Dram *GetDRAM();

    void Tick();
};

#endif