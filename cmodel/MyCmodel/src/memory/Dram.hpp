#ifndef __Dram_HH__
#define __Dram_HH__ 

#include <stdint.h>
#include <iostream>
#include <cstring>
#include "../include/debug.h"
    
class Dram 
{
private:
    uint32_t             m_base;
    uint32_t             m_length;
    char*                m_ram;
public:
    Dram();
    Dram(const uint32_t base , const uint32_t length);
    ~Dram();
    const uint32_t& size();
    uint32_t getBase();
    bool checkRange(uint32_t address);
    uint32_t read(uint32_t address);
    uint32_t readDouble(uint32_t address);
    char readByte(uint32_t address);
    void write(uint32_t address, const char* data, const uint32_t len);
    void writeDouble(uint32_t address,const uint32_t data);
    void writeData(uint32_t address,const uint32_t data);
    void write(uint32_t address,const char* data, const uint32_t len, const uint32_t mask);
};

#endif	