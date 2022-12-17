#include "HEXParser.hpp"
#include<iomanip>
HEXParser::HEXParser(const char *elfPath)
{
    ifs.open(elfPath, ios::in);
    length = 0;
}
HEXParser::~HEXParser(){};

uint32_t
HEXParser::CharParser(char l, char r)
{
    uint32_t ans = 0;
    if (l >= '0' && l <= '9')
        ans += l - '0';
    if (l >= 'a' && l <= 'z')
        ans += l - 'a' + 10;
    ans *= 16;
    if (r >= '0' && r <= '9')
        ans += r - '0';
    if (r >= 'a' && r <= 'z')
        ans += r - 'a' + 10;
    return ans;
}
void HEXParser::Load(Dram *dram)
{
    char buf[3];
    int num = 0;
    while (ifs >> buf)
    {
        length++;
        num++;
        uint32_t data1 = CharParser(buf[0], buf[1]);
        uint32_t real_des = (num - 1) / 4 * 4 + (5 - (num - (num - 1) / 4 * 4)) + dram->getBase();
        dram->writeData(real_des, data1);
        #ifdef DEBUG
        if(num<0)
            cout<<"address: "<<real_des<<"  data: "<<setw(5)<<setfill('0')<<data1<<endl;
        #endif
    }
}
int HEXParser::size()
{
    return this->length;
}
