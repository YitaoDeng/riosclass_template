#include "Dram.hpp"

Dram::Dram(const uint32_t base, const uint32_t length)
{
    this->m_base = base;
    this->m_length = length;
    this->m_ram = new char[length];
}
Dram::~Dram()
{
    delete[] this->m_ram;
}

bool Dram::checkRange(uint32_t address)
{
    return (address >= m_base) && (address < m_base + m_length);
}

uint32_t Dram::getBase()
{
    return this->m_base;
}
uint32_t Dram::read(uint32_t address)
{
    if (!checkRange(address))
    {
        printf("Access Unknown Address: %lu\n", address);
    }
    uint32_t result = (uint32_t)m_ram[address + m_base];
    #ifdef DEBUG
        if(address<0)
            std::cout<<result<<std::endl;
    #endif
}

uint32_t
Dram::readDouble(uint32_t address)
{
    if (!checkRange(address))
    {
        printf("Access Unknown Address: %lu\n", address);
    }
    return *(uint32_t *)(m_ram + (address - m_base));
}

char Dram::readByte(uint32_t address)
{
    if (!checkRange(address))
    {
        printf("Access Unknown Address: %lu\n", address);
    }
    return *(m_ram + (address - m_base));
}

void Dram::write(uint32_t address, const char *data, const uint32_t len)
{
    if (!checkRange(address))
    {
        // printf("Access Unknown Address: %lu\n", address);
    }
    std::copy(data, data + len, m_ram + address - m_base);
}

void Dram::writeDouble(uint32_t address, const uint32_t data)
{
    if (!checkRange(address))
    {
        printf("Access Unknown Address: %lu\n", address);
    }
    std::copy(&data, &data + 8, m_ram + address - m_base);
}
void Dram::writeData(uint32_t address, const uint32_t data)
{
    if (!checkRange(address))
    {
        printf("Access Unknown Address: %lu\n", address);
    }
    m_ram[address] = (char)data;
}

void Dram::write(uint32_t address, const char *data, const uint32_t len, const uint32_t mask)
{
    if (!checkRange(address))
    {
        printf("Access Unknown Address: %lu\n", address);
    }
    for (size_t i = 0; i < len; i++)
    {
        if ((mask >> i) & 1)
        {
            m_ram[address - m_base + i] = data[i];
        }
    }
}

const uint32_t &
Dram::size()
{
    return this->m_length;
}
