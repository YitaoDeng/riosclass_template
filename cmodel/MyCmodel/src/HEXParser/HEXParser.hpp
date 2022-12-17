#ifndef __HEXPARSER_HH__
#define __HEXPARSER_HH__

#include "../memory/Dram.hpp"
#include <string>
#include <fstream>

using namespace std;

class HEXParser
{
private:
    ifstream ifs;
    uint32_t CharParser(char l,char r);
    int length;
public:
    HEXParser(const char* elfPath);

    ~HEXParser();

    void Load(Dram *dram);

    int size();
};

#endif