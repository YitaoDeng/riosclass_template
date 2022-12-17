#include "Decode.hpp"
using namespace std;

void Decode(Insn instr)
{
    bool illegal_instr = false;
    bool ecall = false;
    bool ebreak = false;
    switch (instr.opcode())
    {
    case OpcodeBranch:
        switch (instr.func3())
        {
        case 0b000:
            instr.SubOp = BRU_BEQ;
            break;
        case 0b001:
            instr.SubOp = BRU_BNE;
            break;
        case 0b100:
            instr.SubOp = BRU_BLT;
            break;
        case 0b101:
            instr.SubOp = BRU_BGE;
            break;
        case 0b110:
            instr.SubOp = BRU_BLTU;
            break;
        case 0b111:
            instr.SubOp = BRU_BGEU;
            break;
        default:
            illegal_instr = true;
            break;
        }
        break;
    case OpcodeJal:
        instr.SubOp = ALU_ADD;
        break;
    case OpcodeJalr:
        instr.SubOp = BRU_JALR;
        if (instr.func3() != 0)
        {
            illegal_instr = true;
        }
        break;
    case OpcodeOp:
        switch (instr.func7())
        {
        case 0b0000000:
            switch (instr.func3())
            {
            case 0b000:
                instr.SubOp = ALU_ADD;
                break;
            case 0b001:
                instr.SubOp = ALU_SLL;
                break;
            case 0b010:
                instr.SubOp = ALU_SLT;
                break;
            case 0b011:
                instr.SubOp = ALU_SLTU;
                break;
            case 0b100:
                instr.SubOp = ALU_XOR;
                break;
            case 0b101:
                instr.SubOp = ALU_SRL;
                break;
            case 0b110:
                instr.SubOp = ALU_OR;
                break;
            case 0b111:
                instr.SubOp = ALU_AND;
                break;
            default:
                illegal_instr = true;
                break;
            }
            break;
        case 0b0100000:
            switch (instr.func3())
            {
            case 0b000:
                instr.SubOp = ALU_SUB;
                break;
            case 0b101:
                instr.SubOp = ALU_SRA;
                break;
            default:
                illegal_instr = true;
                break;
            }
            break;
        case 0b0000001:
            switch (instr.func3())
            {
            case 0b000:
                instr.SubOp = MUL_MUL;
                break;
            case 0b001:
                instr.SubOp = MUL_MULH;
                break;
            case 0b010:
                instr.SubOp = MUL_MULHSU;
                break;
            case 0b011:
                instr.SubOp = MUL_MULHU;
                break;
            case 0b100:
                instr.SubOp = DIV_DIV;
                break;
            case 0b101:
                instr.SubOp = DIV_DIVU;
                break;
            case 0b110:
                instr.SubOp = DIV_REM;
                break;
            case 0b111:
                instr.SubOp = DIV_REMU;
                break;
            default:
                break;
            }
            break;
        default:
            illegal_instr = true;
            break;
        }
        break;
    case OpcodeOpImm:
        switch (instr.func3())
        {
        case 0b000:
            instr.SubOp = ALU_ADD;
            break;
        case 0b001:
            instr.SubOp = ALU_SLL;
            if ((instr.func7() >> 1) != 0)
            {
                illegal_instr = true;
            }
            break;
        case 0b010:
            instr.SubOp = ALU_SLT;
            break;
        case 0b011:
            instr.SubOp = ALU_SLTU;
            break;
        case 0b100:
            instr.SubOp = ALU_XOR;
            break;
        case 0b101:
            if ((instr.func7() >> 1) == 0b000000)
            {
                instr.SubOp = ALU_SRL;
            }
            else if ((instr.func7() >> 1) == 0b010000)
            {
                instr.SubOp = ALU_SRA;
            }
            else
            {
                illegal_instr = true;
            }
            break;
        case 0b110:
            instr.SubOp = ALU_OR;
            break;
        case 0b111:
            instr.SubOp = ALU_AND;
            break;
        default:
            illegal_instr = true;
            break;
        }
        break;
    case OpcodeAuipc:
        instr.SubOp = ALU_ADD;
        break;
    default:
        illegal_instr = true;
        break;
    }
#ifdef DEBUG1
    if (instr.address <= 0x80000030)
    {
        printf("    %x      ",instr.address);
        switch (instr.opcode())
        {
        case OpcodeSystem:
            cout << "csr" << endl;
        case OpcodeBranch:
            switch (instr.func3())
            {
            case 0b000:
                if (instr.rs2() == 0)
                    cout << "beqz";
                else
                    cout << "beq";
                break;
            case 0b001:
                if (instr.rs2() == 0)
                    cout << "bnez";
                else
                    cout << "bne";
                break;
            case 0b100:
                if (instr.rs2() == 0)
                    cout << "bltz";
                else
                    cout << "blt";
                break;
            case 0b101:
                if (instr.rs2() == 0)
                    cout << "bgez";
                else
                    cout << "bge";
                break;
            case 0b110:
                if (instr.rs2() == 0)
                    cout << "bltuz";
                else
                    cout << "bltu";
                break;
            case 0b111:
                if (instr.rs2() == 0)
                    cout << "bgeuz";
                else
                    cout << "bgeu";
                break;
            default:
                illegal_instr = true;
                break;
            }
            break;
        case OpcodeJal:
            cout << "j";
            break;
        case OpcodeJalr:
            cout << "j";
            break;
        case OpcodeOp:
            switch (instr.func7())
            {
            case 0b0000000:
                switch (instr.func3())
                {
                case 0b000:
                    cout << "add";
                    break;
                case 0b001:
                    instr.SubOp = ALU_SLL;
                    break;
                case 0b010:
                    instr.SubOp = ALU_SLT;
                    break;
                case 0b011:
                    instr.SubOp = ALU_SLTU;
                    break;
                case 0b100:
                    cout << "xor";
                    break;
                case 0b101:
                    instr.SubOp = ALU_SRL;
                    break;
                case 0b110:
                    instr.SubOp = ALU_OR;
                    break;
                case 0b111:
                    instr.SubOp = ALU_AND;
                    break;
                default:
                    illegal_instr = true;
                    break;
                }
                break;
            case 0b0100000:
                switch (instr.func3())
                {
                case 0b000:
                    instr.SubOp = ALU_SUB;
                    break;
                case 0b101:
                    instr.SubOp = ALU_SRA;
                    break;
                default:
                    illegal_instr = true;
                    break;
                }
                break;
            case 0b0000001:
                switch (instr.func3())
                {
                case 0b000:
                    instr.SubOp = MUL_MUL;
                    break;
                case 0b001:
                    instr.SubOp = MUL_MULH;
                    break;
                case 0b010:
                    instr.SubOp = MUL_MULHSU;
                    break;
                case 0b011:
                    instr.SubOp = MUL_MULHU;
                    break;
                case 0b100:
                    instr.SubOp = DIV_DIV;
                    break;
                case 0b101:
                    instr.SubOp = DIV_DIVU;
                    break;
                case 0b110:
                    instr.SubOp = DIV_REM;
                    break;
                case 0b111:
                    instr.SubOp = DIV_REMU;
                    break;
                default:
                    break;
                }
                break;
            default:
                illegal_instr = true;
                break;
            }
            break;
        case OpcodeOpImm:
            switch (instr.func3())
            {
            case 0b000:
                if (instr.rs1() == 0)
                    cout << "li";
                else
                    cout << "addi";
                break;
            case 0b001:
                instr.SubOp = ALU_SLL;
                if ((instr.func7() >> 1) != 0)
                {
                    illegal_instr = true;
                }
                break;
            case 0b010:
                instr.SubOp = ALU_SLT;
                break;
            case 0b011:
                instr.SubOp = ALU_SLTU;
                break;
            case 0b100:
                instr.SubOp = ALU_XOR;
                break;
            case 0b101:
                if ((instr.func7() >> 1) == 0b000000)
                {
                    instr.SubOp = ALU_SRL;
                }
                else if ((instr.func7() >> 1) == 0b010000)
                {
                    instr.SubOp = ALU_SRA;
                }
                else
                {
                    illegal_instr = true;
                }
                break;
            case 0b110:
                instr.SubOp = ALU_OR;
                break;
            case 0b111:
                instr.SubOp = ALU_AND;
                break;
            default:
                illegal_instr = true;
                break;
            }
            break;
        case OpcodeAuipc:
            cout << "auipc";
            break;
        default:
            illegal_instr = true;
            break;
        }
        cout << endl;
    }

#endif
}