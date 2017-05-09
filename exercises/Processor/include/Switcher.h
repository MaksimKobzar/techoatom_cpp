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
    /* TODO все параметры шаблонных классов, которые необходимы в Switcher, приходится добавлять в параметры Switcher
        - это крайне неудобно, подумать как по-другому */
>class Switcher
{
        const size_t INSTR_WIDTH        = 6;
        const size_t REG_NUM_WIDTH      = 5;
        const size_t HALF_CMD           = 16; /* TODO = sizeof(T)/2; */
        using value_type                = T; /* TODO ограничить разнообразие возможных типов T */
    public:
        //---------------------------------------------
        //! @Constructor
        //! Create class Switcher
        //! Get 3 arguments:
        //! - Instruction memory,
        //! - Stack,
        //! - Registers.
        //---------------------------------------------
        explicit Switcher(
            const std::deque<value_type>    &cmdMemory,
            StackType                       &stack,
            std::array<value_type,REG_NUM>  &regs
        );
        Switcher(Switcher &other) = delete;
        ~Switcher();

        //---------------------------------------------
        //! @run:
        //! Run processing commands.
        //! If run failed return error code.
        //! Return codes:
        //! 0 - SUCCESS
        //! 1 - STACK_UNDERFLOW
        //! 2 - OUT_OF_MEM_RANGE
        //---------------------------------------------
        char run();

        //---------------------------------------------
        //! @getCmdCounter:
        //! Return cmdCounter_ value.
        //---------------------------------------------
        size_t getCmdCounter();

    private:
        //---------------------------------------------
        //! @clearLableTable
        //! Fill all table by zero.
        //---------------------------------------------
        void clearLableTable();

        //---------------------------------------------
        //! @fillLabelTable
        //! Run around all memory and put all found labels in LabelTable.
        //---------------------------------------------
        void fillLabelTable();

        //---------------------------------------------
        //! @switchCmds
        //! Switch all commands from instruction memory till the end.
        //! If run failed return error code.
        //! Return codes:
        //! 0 - SUCCESS,
        //! 1 - STACK_UNDERFLOW,
        //! 2 - OUT_OF_MEM_RANGE,
        //! 3 - UNFINISHED_RUN.
        //---------------------------------------------
        char switchCmds();

        //---------------------------------------------
        //! @getFieldInstr
        //! @getFieldR0
        //! @getFieldR1
        //! @getFieldData
        //! Accessory functions to get different fields of one command word
        //---------------------------------------------
        value_type getFieldInstr(value_type word) const;
        value_type getFieldR0(value_type word) const;
        value_type getFieldR1(value_type word) const;
        value_type getFieldData(value_type word) const;

        const std::deque<value_type>                    &cmdMemory_;
        StackType                                       &stack_;
        std::array<value_type, REG_NUM>                 &regs_;
        std::array<size_t, LABEL_TABLE_WIDTH>           labelTable_;
        size_t                                          cmdCounter_;
};

// -----------------------------------------------------------------------------------------------
// Implementation of methods
// -----------------------------------------------------------------------------------------------
template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::Switcher(
    const std::deque<value_type>    &cmdMemory,
    StackType                       &stack,
    std::array<value_type, REG_NUM> &regs
)
    : cmdMemory_ (cmdMemory), stack_(stack), regs_(regs), cmdCounter_(0)
{
    DEBUG_INFO("SWITCHER: Constructor.");
    clearLableTable();
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::~Switcher()
{
    DEBUG_INFO("SWITCHER: Destructor.");
    clearLableTable();
    #ifdef NDEBUG
        cmdCounter_ = 0;
    #endif
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldInstr(value_type word) const
{
    DEBUG_INFO("SWITCHER: Get Instr from Word.");
    return(word >> (HALF_CMD + 2*REG_NUM_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldR0(value_type word) const
{
    DEBUG_INFO("SWITCHER: Get $R0 from Word.");
    return((word << INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldR1(value_type word) const
{
    DEBUG_INFO("SWITCHER: Get $R1 from Word.");
    return((word << REG_NUM_WIDTH + INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
value_type Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getFieldData(value_type word) const
{
    DEBUG_INFO("SWITCHER: Get DATA from Word.");
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
char Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::run()
{
    DEBUG_INFO("SWITCHER: Run.");
    if(cmdCounter_ != 0)
    {
        return UNFINISHED_RUN;
    }
    fillLabelTable();
    return(switchCmds());
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
size_t Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::getCmdCounter()
{
    DEBUG_INFO("SWITCHER: getCmdCounter.");
    return cmdCounter_;
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::clearLableTable()
{
    DEBUG_INFO("SWITCHER: Clear Lable Table.");
    labelTable_.fill(0);
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::fillLabelTable()
{
    DEBUG_INFO("SWITCHER: Fill Lable table.");
    clearLableTable();
    while(cmdMemory_[cmdCounter_] != '\0')
    {
        if(cmdMemory_[cmdCounter_] & ((1 << HALF_CMD) - 1) == ':')
        {
            labelTable_[cmdMemory_[cmdCounter_] >> HALF_CMD] = cmdCounter_ + 1;
        }
        ++cmdCounter_;
    }
    cmdCounter_ = 0;
}


#define func(name, cmd_value, cmd_operator, arg_num) \
    template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH> \
    void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::name() \
    { \
        if(stack_.size() < arg_num) \
        { \
            return STACK_UNDERFLOW; \
        } \
        else \
        { \
           value_type op1 = stack_.top(); \
           value_type op2; \
           stack_.pop(); \
           if(arg_num == 2) \
           { \
                op2 = stack_.top(); \
                stack_.pop(); \
           } \
           else \
           { \
            value_type op2 = getFieldData(cmdWord); \
           } \
           regs_[getFieldR0(cmdWord)] = op1 cmd_operator op2; \
        } \
    }
#include "arlog_cmds.h"
#undef func

#define func(name, cmd_value, cmd_operator, arg_num) \
    template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH> \
    void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::name() \
    { \
        if(stack_.size() == 0) \
        { \
            return STACK_UNDERFLOW; \
        } \
        else \
        { \
            if(arg_num) \
            { \
                regs_[getFieldR0(cmdWord)] = stack_.top() cmd_operator getFieldData(cmdWord); \
            } \
            else \
            { \
                regs_[getFieldR0(cmdWord)] = stack_.top() cmd_operator regs_[getFieldR1(cmdWord)]; \
            } \
            stack_.pop(); \
        } \
    }
#include "shift_cmds.h"
#undef func


#define func(name, code, dw, with_zero, op, link) \
    template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH> \
    void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::name() \
    { \
        if(with_zero) \
        { \
            if(regs_[getFieldR0(cmdWord)] op 0) \
            { \
                cmdCounter_ = getFieldData(cmdWord); \
            } \
        } \
        else \
        { \
            if(regs_[getFieldR0(cmdWord)] op regs_[getFieldR1(cmdWord)]) \
            { \
                cmdCounter_ = getFieldData(cmdWord); \
            } \
        } \
        if(link) \
        { \
            returnStack.push(cmdCounter_); \
        }
    }
#include "branch_cmds.h"
#undef func


template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::j_cmd(value_type word)
{
    if(0 <= getFieldData(word) && getFieldData(word) < cmdMemory_.size())
    {
        cmdCounter_ = getFieldData(word);
    // continue;
    else
    {
        return OUT_OF_MEM_RANGE; // return Error Code
    }
}

template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
void Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::jal_cmd(value_type word)
{
    if(0 <= getFieldData(cmdWord) && getFieldData(cmdWord) < cmdMemory_.size())
    {
        cmdCounter_ = getFieldData(cmdWord);
        stack_.push(getFieldData(cmdWord));
        // continue;
    }
    else
    {
        return OUT_OF_MEM_RANGE; // return Error Code
    }
}


                case JAL_CMD :
                {
                    if(0 <= getFieldData(cmdWord) && getFieldData(cmdWord) < cmdMemory_.size())
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
                    if(0 <= regs_[getFieldR0(cmdWord)] && regs_[getFieldR0(cmdWord)] < cmdMemory_.size())
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
                    if(0 <= labelTable_[getFieldR0(cmdWord)] && labelTable_[getFieldR0(cmdWord)] < cmdMemory_.size())
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






template <typename value_type, const size_t REG_NUM, class StackType, const size_t LABEL_TABLE_WIDTH>
char Switcher<value_type, REG_NUM, StackType, LABEL_TABLE_WIDTH>::switchCmds()
{
    DEBUG_INFO("SWITCHER: SwicthCmds.");
    value_type cmdWord = 0;
    while((cmdWord = cmdMemory_[cmdCounter_]) != '\0')
    {   
        #ifdef NDEBUG
            std::cout << "cmdWord = " << std::hex << cmdMemory_[cmdCounter_] << std::endl;
            std::cout << "Instrac = " << std::hex << getFieldInstr(cmdWord) << std::endl;
        #endif // NDEBUG
        switch(getFieldInstr(cmdWord))
        {

            #define func(name, cmd_value, cmd_operator, arg_num) \
                case cmd_value : \
                { \
                    name(cmdWord); \
                } \
                break;
            #include "jump_cmds.h"
            #include "move_cmds.h"
            #include "nop_cmds.h"
            #include "branch_cmds.h"
            #include "shift_cmds.h"
            #include "arlog_cmds.h"
            #undef func
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
        DEBUG_INFO("PROCESSOR: Process one more command.");
    }
    cmdCounter_ = 0;
    return SUCCESS;
}

#endif // _SWITCHER_H_
