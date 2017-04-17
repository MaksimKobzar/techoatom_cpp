//---------------------------------------------
//! @file Switcher.h
//! Header file Switcher structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _SWITCHER_H_
#define _SWITCHER_H_

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <stack>
#include <deque>
#include <math.h>
#include "cmd_defines.h"
#include "error_code_defines.h"

template<
    typename T,
    const size_t REG_NUM,
    class StackType = std::stack<T>,
    const size_t LABEL_TABLE_WIDTH = 32
>class Switcher
{
        const size_t INSTR_WIDTH        = 6;
        const size_t REG_NUM_WIDTH      = 5; // 5
        const size_t HALF_CMD           = 16; // 5
        using value_type                = T; /*TODO ограниченное разнообразие возможных T*/
    public:
        //---------------------------------------------
        //! @Constructor
        //! Create class Switcher
        //---------------------------------------------
        /* TODO все параметры шаблонных классов приходится добавлять в параметры Switcher*/
        Switcher(const std::deque<value_type> &otherMemory, StackType &stack, std::array<value_type, REG_NUM> &otherRegs);
        Switcher(Switcher &other) = delete;
        ~Switcher();

        void clearLableTable();
        void fillLabelTable();
        char switchCmds();

        //---------------------------------------------
        //! @Constructor
        //! Get different fields of command word
        //---------------------------------------------
        type_value getFieldInstr(value_type word) const;
        type_value getFieldR0(value_type word) const;
        type_value getFieldR1(value_type word) const;
        type_value getFieldData(value_type word) const;

        //---------------------------------------------
        //! @Operators:
        //! Run processing commands.
        //! If run failed return false, otherwise true.
        //! False if cmdCounter_ isnt equal 0 or failed in switching commands.
        //---------------------------------------------
        bool run();

    private:
        const std::deque<value_type>                    &cmdMemoryPtr_;
        StackType                                       &stack_;
        std::array<value_type, REG_NUM>                 &regs_;
        std::array<size_t, LABEL_TABLE_WIDTH>           labelTable_;
        size_t                                          cmdCounter_;
};

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::Switcher(const std::deque<value_type> &otherMemory, StackType &stack, std::array<value_type, REG_NUM> &otherRegs)
        : cmdMemoryPtr_ (otherMemory), stack_(stack), regs_(otherRegs), cmdCounter_(0)
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Constructor.");
    clearLableTable();
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::~Switcher()
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Destructor.");
    clearLableTable();
    #ifdef NDEBUG
        cmdCounter_ = 0;
    #endif
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldInstr(value_type word) const
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Get Instr Value.");
    return(word >> (HALF_CMD + 2*REG_NUM_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldR0(value_type word) const
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Get R0 Value.");
    return((word << INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldR1(value_type word) const
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Get R1 Value.");
    return((word << REG_NUM_WIDTH + INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldData(value_type word) const
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Get Data Value.");
    value_type instr = getFieldInstr(word);
    if(
            instr == LW_CMD    ||
            instr == ADDI_CMD  ||
            instr == MULI_CMD  ||
            instr == SUBI_CMD  ||
            instr == DIVI_CMD  ||
            instr == ANDI_CMD  ||
            instr == ORI_CMD   ||
            instr == XOR_CMD   ||
            instr == SLL_CMD   ||
            instr == SRL_CMD
            )
    {
        return(word & ((1 << (REG_NUM_WIDTH + HALF_CMD)) - 1)); // 21
    }
    else
    {
        return(word & ((1 << (2*REG_NUM_WIDTH + HALF_CMD)) - 1)); // 26
    }
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
bool Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::run()
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Run.");
    if(cmdCounter_ != 0)
    {
        return false;
    }
    fillLabelTable();
    if(switchCmds())
    {
        return false;
    }
    return true;
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::clearLableTable()
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Clear Lable Table.");
    std::cout << "Size of lable table = " << labelTable_.size() << std::endl;
    labelTable_.fill(0);
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::fillLabelTable()
{
    DEBUG_INFO("PROCESSOR: SWITCHER: Fill Lable table.");
    clearLableTable();
    while(cmdMemoryPtr_[cmdCounter_] != '\0')
    {
        if(cmdMemoryPtr_[cmdCounter_] & ((1 << HALF_CMD) - 1) == ':')
        {
            labelTable_[cmdMemoryPtr_[cmdCounter_] >> HALF_CMD] = cmdCounter_ + 1;
        }
        ++cmdCounter_;
    }
    cmdCounter_ = 0;
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
char Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::switchCmds()
{
    DEBUG_INFO("PROCESSOR: SWITCHER: SwicthCmds.");
    value_type cmdWord = 0;
    while((cmdWord = cmdMemoryPtr_[cmdCounter_]) != '\0')
    {
        std::cout << "cmdWord = " << std::hex << cmdMemoryPtr_[cmdCounter_] << std::endl;
        std::cout << "Instrac = " << std::hex << getFieldInstr(cmdWord) << std::endl;
        switch(getFieldInstr(cmdWord))
        {
            case NOOP_CMD :
            { }
                break;
            // --------------------------------- Ariphm -----------------------------------------------------
                 #define func(name, op) \
                    case name : \
                    { \
                        if(stack_.size() < 2) \
                        { \
                            return STACK_UNDERFLOW; \
                        } \
                        else \
                        { \
                           value_type op1 = stack_.top(); \
                           stack_.pop(); \
                           value_type op2 = stack_.top(); \
                           stack_.pop();\
                           regs_[getFieldR0(cmdWord)] = op1 op op2; \
                        } \
                    } \
                    break;
                #include "binaryOperators.h"
                #undef func
             // --------------------------------- Logic ------------------------------------------------------
                 #define func(name, op) \
                    case name : \
                    { \
                        if(stack_.size() < 1) \
                        { \
                            return STACK_UNDERFLOW; \
                        } \
                        else \
                        { \
                           value_type op1 = stack_.top(); \
                           stack_.pop(); \
                           value_type op2 = getFieldData(cmdWord); \
                           regs_[getFieldR0(cmdWord)] = op1 op op2; \
                        } \
                    } \
                    break;
                    #include "unaryOperators.h"
                 #undef func
            // --------------------------------- Jumps ------------------------------------------------------
            case J_CMD :
            {
                if(0 <= getFieldData(cmdWord) && getFieldData(cmdWord) < cmdMemoryPtr_.size())
                {
                    cmdCounter_ = getFieldData(cmdWord);
                    continue;
                }
                else
                {
                    return OUT_OF_MEM_RANGE; // return Error Code
                }
            }
                break;
            case JAL_CMD :
            {
                if(0 <= getFieldData(cmdWord) && getFieldData(cmdWord) < cmdMemoryPtr_.size())
                {
                    cmdCounter_ = getFieldData(cmdWord);
                    stack_.push(getFieldData(cmdWord));
                    continue;
                }
                else
                {
                    return OUT_OF_MEM_RANGE; // return Error Code
                }
            }
                break;
            case JR_CMD :
            {
                if(0 <= regs_[getFieldR0(cmdWord)] && regs_[getFieldR0(cmdWord)] < cmdMemoryPtr_.size())
                {
                    cmdCounter_ = regs_[getFieldR0(cmdWord)];
                    continue;
                }
                else
                {
                    return OUT_OF_MEM_RANGE; // return Error Code
                }
            }
                break;
            case JLB_CMD :
            {
                if(0 <= labelTable_[getFieldR0(cmdWord)] && labelTable_[getFieldR0(cmdWord)] < cmdMemoryPtr_.size())
                {
                    cmdCounter_ = labelTable_[getFieldR0(cmdWord)];
                    continue;
                }
                else
                {
                    return OUT_OF_MEM_RANGE; // return Error Code
                }
            }
                break;
                // --------------------------------- Shifts -----------------------------------------------------
            case SLL_CMD :
            {
                if(stack_.size() == 0) {
                    return STACK_UNDERFLOW;
                }
                else {
                    regs_[getFieldR0(cmdWord)] = stack_.top() << getFieldData(cmdWord);
                    stack_.pop();
                }
            }
                break;
            case SLLV_CMD :
            {
                if(stack_.size() == 0) {
                    return STACK_UNDERFLOW;
                }
                else {
                    regs_[getFieldR0(cmdWord)] = stack_.top() << regs_[getFieldR1(cmdWord)];
                    stack_.pop();
                }
            }
                break;
            case SRL_CMD :
            {
                if(stack_.size() == 0) {
                    return STACK_UNDERFLOW;
                }
                else {
                    regs_[getFieldR0(cmdWord)] = stack_.top() >> getFieldData(cmdWord);
                    stack_.pop();
                }
            }
                break;
            case SRA_CMD :
            {
                if(stack_.size() == 0) {
                    return STACK_UNDERFLOW;
                }
                else {
                    regs_[getFieldR0(cmdWord)] = stack_.top() >> getFieldData(cmdWord);
                    stack_.pop();
                }
            }
                break;
                // --------------------------------- Branches ---------------------------------------------------
            case BEQ_CMD :
            {
                if(getFieldR0(cmdWord) == getFieldR1(cmdWord))
                {
                    cmdCounter_ += getFieldData(cmdWord);
                }
            }
                break;
            case BGEZ_CMD :
            {
                if(regs_[getFieldR0(cmdWord)] >= 0)
                {
                    cmdCounter_ += getFieldData(cmdWord);
                }
            }
                break;
            case BGTZ_CMD :
            {
                if(getFieldR0(cmdWord) > 0)
                {
                    cmdCounter_ += getFieldData(cmdWord);
                }
            }
                break;
                // --------------------------------- Move data --------------------------------------------------
            case SW_CMD :
            {
                if(stack_.empty())
                {
                    return STACK_UNDERFLOW;
                }
                else
                {
                    regs_[getFieldR0(cmdWord)] = stack_.top();
                    stack_.pop();
                }

            }
                break;
            case LW_CMD :
            {
                stack_.push(regs_[getFieldR0(cmdWord)]);
            }
                break;
            case PS_CMD :
            {
                stack_.push(regs_[getFieldData(cmdWord)]);
            }
                break;
            case PSI_CMD :
            {
                stack_.push(getFieldData(cmdWord));
            }
                break;
        }
        ++cmdCounter_;
        DEBUG_INFO("PROCESSOR: Process 1 command.");
    }
    cmdCounter_ = 0;
    return OKAY;
}

#endif // _SWITCHER_H_
