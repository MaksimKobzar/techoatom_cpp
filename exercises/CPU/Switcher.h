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

    template<
        typename T = unsigned
    >class Switcher
    {
        using LABEL_TABLE_WIDTH = 32;
        using HALF_CMD = 16;
        using REG_NUM_WIDTH = 5;
        using INSTR_WIDTH = 6;
        using value_type =  T; /*TODO ограниченное разнообразие возможных T*/
        //---------------------------------------------
        //! @Constructor
        //! Create class Switcher
        //---------------------------------------------
        Switcher(const std::deque<value_type> &otherMemory, StackType &stack_, std::array<value_type> &otherRegs);
        Switcher(Switcher &other) = delete;
        ~Switcher();

        //---------------------------------------------
        //! @Constructor
        //! Get different fields of comand word
        //---------------------------------------------
        type_value getFieldInstr(value_type word) const;
        type_value getFieldR0(value_type word) const;
        type_value getFieldR1(value_type word) const;
        type_value getFieldData(value_type word) const;

        //---------------------------------------------
        //! @Operators:
        //! operator =
        //! operator<<
        //---------------------------------------------
        bool run();

    private:
        const std::deque<value_type>    &cmdMemoryPtr_;
        StackType                       &stack_;
        std::array<value_type>          &regs_;
        size_t                          cmdCounter_;
        std::array<size_t, LABEL_TABLE_WIDTH> labelTable_;
    };
#endif // _SWITCHER_H_

    template <typename value_type>
    Switcher::Switcher(const std::deque<value_type> &otherMemory, const std::array<value_type> &otherRegs)
        : cmdMemoryPtr_ (otherMemory), regs_ (otherRegs), cmdCounter_(0)
    {
        #ifdef NDEBUG
            clearLableTable();
        #endif
    }

    template <typename value_type>
    Switcher<value_type>::~Switcher()
    {
        #ifdef NDEBUG
            clearLableTable();
            cmdCounter_ = 0;
        #endif
    }

    template <typename value_type>
    value_type Switcher<value_type>::getFieldInstr(value_type word) const
    {
        return(word >> (HALF_CMD + 2*REG_NUM_WIDTH));
    }

    template <typename value_type>
    value_type Switcher::getFieldR0(value_type word) const
    {
        return((word << INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
    }

    template <typename value_type>
    value_type Switcher::getFieldR1(value_type word) const
    {
        return((word << REG_NUM_WIDTH + INSTR_WIDTH) >> (HALF_CMD + REG_NUM_WIDTH + INSTR_WIDTH));
    }

    template <typename value_type>
    value_type Switcher::getFieldData(value_type word) const
    {
        value_type instr = getFieldInstr(word);
        if( instr == J    ||
            instr == JAL  ||
        )
        {
            return(word & ((1 << (2*REG_NUM_WIDTH + HALF_CMD)) - 1));
        }
        else
        {
            return(word & ((1 << HALF_CMD) - 1));
        }
    }

    template <typename value_type>
    bool Switcher::setMemory(const std::deque<value_type> *memPtr)
    {
        if(memPtr == nullptr)
        {
            return false;
        }
        else
        {
            cmdMemoryPtr_ = memPtr;
            return true;
        }
    }

    template <typename value_type>
    bool Switcher::run()
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

    template <typename value_type>
    void clearLableTable()
    {
        for(auto i : labelTable_)
        {
            labelTable_[i] = 0;
        }
    }

    template <typename value_type>
    void Switcher::fillLabelTable()
    {
        clearLableTable();
        while(cmdMemoryPtr_[cmdCounter_]) != '\0')
        {
            if(cmdMemoryPtr_[cmdCounter_] & ((1 << HALF_CMD) - 1) == ':')
            {
                labelTable_[cmdMemoryPtr_[cmdCounter_] >> HALF_CMD] = cmdCounter_ + 1;
            }
            ++cmdCounter_;
        }
        cmdCounter_ = 0;
    }

    template <typename value_type>
    char Switcher::switchCmds()
    {
        T cmdWord = 0;
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
                        T op1 = stack_->front();
                        stack_->pop_front();
                        T op2 = stack_->front();
                        stack_->pop_front();
                        regs_[getFieldR0(cmdWord)] = op1 op op2;
                    }
                    break;
                    #include "binaryOperators.h"
                #undef func
            // --------------------------------- Logic ------------------------------------------------------
                #define func(name, op, regNum) \
                    case name :
                    {
                        T op1 = stack_->front();
                        stack_->pop_front();
                        T op2 = getFieldData(cmdWord);
                        regs_[getFieldR0(cmdWord)] = op1 op op2;
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
                        stackRet_.push_back(cmdWord);
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

                    /*
                    *    case J_CMD :
                    *    {
                    *        if(0 <= getFieldData(cmdWord) && getFieldData(cmdWord) < 32)
                    *        {
                    *            cmdCounter_ = labelTable_[getFieldData()];
                    *        }
                    *        else
                    *        {
                    *            return 2; // return Error Code
                    *        }
                    *    }
                    *    break;
                    */
            // --------------------------------- Shifts -----------------------------------------------------
                case SLL_CMD :
                {
                    if(stack_.size() == 0) {
                        return STACK_UNDERFLOW;
                    }
                    else {
                        regs_[getFieldR0(cmdWord)] = stack_->front() << getFieldData(cmdWord);
                        stack_->pop_front();
                    }
                }
                break;
                case SLLV_CMD :
                {
                    if(stack_.size() == 0) {
                        return STACK_UNDERFLOW;
                    }
                    else {
                        regs_[getFieldR0(cmdWord)] = stack_->front() << regs_[getFieldR1(cmdWord)];
                        stack_->pop_front();
                    }
                }
                break;
                case RLL_CMD :
                {
                    if(stack_.size() == 0) {
                        return STACK_UNDERFLOW;
                    }
                    else {
                        regs_[getFieldR0(cmdWord)] = stack_->front() >> getFieldData(cmdWord);
                        stack_->pop_front();
                    }
                }
                break;
                case SRA_CMD :
                {
                    if(stack_.size() == 0) {
                        return STACK_UNDERFLOW;
                    }
                    else {
                        regs_[getFieldR0(cmdWord)] = stack_->front() >> getFieldData(cmdWord);
                        stack_->pop_front();
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
                    if(getFieldR0(cmdWord) => 0)
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
                    if(stack->empty())
                    {
                        return STACK_UNDERFLOW;
                    }
                    else
                    {
                        regs_[getFieldR0(cmdWord)] = stack->front();
                        stack_->pop_front();
                    }

                }
                break;
                case LW_CMD :
                {
                    stack->push_back(regs_[getFieldR0(cmdWord)]);
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
        return 0;
    }
