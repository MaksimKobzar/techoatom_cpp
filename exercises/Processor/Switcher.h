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
        const size_t REG_NUM_WIDTH      = log2(regs_.size()); // 5
        const size_t HALF_CMD           = sizeof(unsigned)/2; // 5
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
        //! Get different fields of comand word
        //---------------------------------------------
        value_type getFieldInstr(value_type word) const;
        value_type getFieldR0(value_type word) const;
        value_type getFieldR1(value_type word) const;
        value_type getFieldData(value_type word) const;

        //---------------------------------------------
        //! @Operators:
        //! operator =
        //! operator<<
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
#ifdef NDEBUG
    clearLableTable();
#endif
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::~Switcher()
{
#ifdef NDEBUG
    clearLableTable();
    cmdCounter_ = 0;
#endif
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldInstr(value_type word) const
{
    return(word >> (HALF_CMD + 2*REG_NUM_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldR0(value_type word) const
{
    return((word << INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldR1(value_type word) const
{
    return((word << REG_NUM_WIDTH + INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldData(value_type word) const
{
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
    for(auto i : labelTable_)
    {
        labelTable_[i] = 0;
    }
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::fillLabelTable()
{
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
    value_type cmdWord = 0;
    while((cmdWord = *(cmdMemoryPtr_ + cmdCounter_)) != '\0')
    {
        switch(getFieldInstr(cmdWord))
        {
            case NOOP_CMD :
            { }
                break;
                // --------------------------------- Ariphm -----------------------------------------------------
                /* #define func(name, op) \
                     case name :
                     {
                         if(stack_->size() < 2)
                         {
                             return STACK_UNDERFLOW;
                         }
                         else
                         {
                             T op1 = stack_->top();
                             stack_->pop();
                             T op2 = stack_->top();
                             stack_->pop();
                             regs_[getFieldR0(cmdWord)] = op1 op op2;
                         }
                     }
                     break;
                     #include "binaryOperators.h"
                 #undef func
             // --------------------------------- Logic ------------------------------------------------------
                 #define func(name, op, regNum) \
                     case name :
                     {
                         if(stack_->size() < 2)
                         {
                             return STACK_UNDERFLOW;
                         }
                         else
                         {
                             T op1 = stack_->top();
                             stack_->pop();
                             T op2 = getFieldData(cmdWord);
                             regs_[getFieldR0(cmdWord)] = op1 op op2;
                         }
                     }
                     break;
                     #include "unaryOperators.h"
                 #undef func*/
                // --------------------------------- Jumps ------------------------------------------------------
            case J_CMD :
            {
                if(0 <= getFieldData(cmdWord) && getFieldData(cmdWord) < cmdMemoryPtr_.capacity())
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
                if(0 <= getFieldData(cmdWord) && getFieldData(cmdWord) < cmdMemoryPtr_.capacity())
                {
                    cmdCounter_ = getFieldData(cmdWord);
                    stack_->push_back(cmdWord);
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
                if(0 <= regs_[getFieldR0(cmdWord)] && regs_[getFieldR0(cmdWord)] < cmdMemoryPtr_.capacity())
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
            case JR_CMD :
            {
                if(0 <= labelTable_[getFieldR0(cmdWord)] && labelTable_[getFieldR0(cmdWord)] < cmdMemoryPtr_.capacity())
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
                    regs_[getFieldR0(cmdWord)] = stack_->top() << getFieldData(cmdWord);
                    stack_->pop();
                }
            }
                break;
            case SLLV_CMD :
            {
                if(stack_.size() == 0) {
                    return STACK_UNDERFLOW;
                }
                else {
                    regs_[getFieldR0(cmdWord)] = stack_->top() << regs_[getFieldR1(cmdWord)];
                    stack_->pop();
                }
            }
                break;
            case SRL_CMD :
            {
                if(stack_.size() == 0) {
                    return STACK_UNDERFLOW;
                }
                else {
                    regs_[getFieldR0(cmdWord)] = stack_->top() >> getFieldData(cmdWord);
                    stack_->pop();
                }
            }
                break;
            case SRA_CMD :
            {
                if(stack_.size() == 0) {
                    return STACK_UNDERFLOW;
                }
                else {
                    regs_[getFieldR0(cmdWord)] = stack_->top() >> getFieldData(cmdWord);
                    stack_->pop();
                }
            }
                break;
                // --------------------------------- Branches ---------------------------------------------------
            case BEQ_CMD :
            {
                if(getFieldR0(cmdWord) == getFieldR1(cmdWord))
                {
                    cmdCounter_ += getFieldData();
                }
            }
                break;
            case BGEZ_CMD :
            {
                if(regs_[getFieldR0(cmdWord)] >= 0)
                {
                    cmdCounter_ += getFieldData();
                }
            }
                break;
            case BGTZ_CMD :
            {
                if(getFieldR0(cmdWord) > 0)
                {
                    cmdCounter_ += getFieldData();
                }
            }
                break;
                // --------------------------------- Move data --------------------------------------------------
            case SW_CMD :
            {
                if(stack_->empty())
                {
                    return STACK_UNDERFLOW;
                }
                else
                {
                    regs_[getFieldR0(cmdWord)] = stack_->top();
                    stack_->pop();
                }

            }
                break;
            case LW_CMD :
            {
                stack_->push_back(regs_[getFieldR0(cmdWord)]);
            }
                break;
            case PS_CMD :
            {
                stack_->push_back(regs_[getFieldData(cmdWord)]);
            }
                break;
            case PSI_CMD :
            {
                stack_->push_back(getFieldData(cmdWord));
            }
                break;
        }
        ++cmdCounter_;
    }
    cmdCounter_ = 0;
    return OKAY;
}

#endif // _SWITCHER_H_
