#ifndef __STATICINSN_HH__
#define __STATICINSN_HH__ 

#include "../include/Macros.h"
#include "IF.hpp"

class Insn{

protected:
    uint32_t m_insn;
public:
    uint32_t address;
    uint8_t  SubOp;

    Insn(IF if1){
        this->m_insn = if1.get_ins();
        this->address = if1.get_address();
    };

    ~Insn(){};

    uint32_t operator()(const uint8_t pos){
        return (this->m_insn & ((uint64_t)1 << pos)) >> pos;
    };

    uint32_t operator()(const uint8_t upper, const uint8_t lower){
        return ( ( this->m_insn & (((uint64_t)1 << (upper+1)) - 1) ) & ~(((uint64_t)1 << lower) - 1) ) >> lower;
    };

    uint8_t rs1(){
        return this->operator()(19,15);
    };
    uint8_t rs2(){
        return this->operator()(24,20);
    };
    uint8_t rs3(){
        return this->operator()(31,27);
    };
    uint8_t rd(){
        return this->operator()(11,7);
    };
    uint32_t opcode(){
        return this->operator()(6,0);
    };
    uint32_t func3(){
        return this->operator()(14,12);
    };
    uint32_t func7(){
        return this->operator()(31,25);
    };
    uint32_t simm(){
        return (((int32_t)this->m_insn >> 31) & ~((uint32_t)((1 << 11)-1))) +
                (this->operator()(30,25) << 5) + 
                (this->operator()(11,8) << 1) + 
                (this->operator()(7));
    };
    uint32_t sbimm(){
        return (((int32_t)this->m_insn >> 31) & ~((uint32_t)((1 << 12)-1))) +
                (this->operator()(7) << 11) +
                (this->operator()(30,25) << 5) + 
                (this->operator()(11,8) << 1);
    };
    uint32_t uimm(){
        return (int32_t)this->m_insn & ~((uint32_t)((1 << 12) - 1));
    };
    uint32_t ujimm(){
        return (((int32_t)this->m_insn >> 31) & ~((uint32_t)((1 << 20)-1))) + 
                (this->operator()(19,12) << 12) +  
                (this->operator()(20)    << 11) +   
                (this->operator()(30,25) << 5) +   
                (this->operator()(24,21) << 1);
    };
};

enum funcType_t {
    ALU , MUL , DIV, BRU, CSR, LDU, STU, FPU
};


#define BRU_JAR         0
#define BRU_JALR        1
#define BRU_BEQ         2
#define BRU_BNE         3
#define BRU_BLT         4
#define BRU_BGE         5
#define BRU_BLTU        6
#define BRU_BGEU        7    

#define CSR_CSRRW       0
#define CSR_CSRRS       1
#define CSR_CSRRC       2
#define CSR_CSRR        3
#define CSR_FENCEI      4
#define CSR_ECALL       5
#define CSR_EBREAK      6
#define CSR_MRET        7
#define CSR_SRET        8
#define CSR_FENCE       9

#define LDU_LB          0
#define LDU_LH          1
#define LDU_LW          2
#define LDU_LD          3
#define LDU_LBU         4
#define LDU_LHU         5
#define LDU_LWU         6

#define STU_SB          0
#define STU_SH          1
#define STU_SW          2
#define STU_SD          3

#define ALU_ADD         0
#define ALU_SUB         1
#define ALU_SLL         2
#define ALU_SLT         3
#define ALU_SLTU        4   
#define ALU_XOR         5
#define ALU_SRL         6
#define ALU_SRA         7
#define ALU_OR          8
#define ALU_AND         9

#define ALU_ADDW        10
#define ALU_SUBW        11
#define ALU_SLLW        12
#define ALU_SRLW        13
#define ALU_SRAW        14


#define MUL_MUL         0
#define MUL_MULH        1
#define MUL_MULHSU      2
#define MUL_MULHU       3

#define MUL_MULW        4

#define DIV_DIV         0
#define DIV_DIVU        1
#define DIV_REM         2
#define DIV_REMU        3

#define DIV_DIVW        4
#define DIV_DIVUW       5
#define DIV_REMW        6
#define DIV_REMUW       7

#endif	