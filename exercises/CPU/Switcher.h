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

    struct Switcher
    {
        using LABEL_TABLE_WIDTH = 10;
        using HALF_WORD = 16;
        //---------------------------------------------
        //! @Constructor
        //! Create class Switcher
        //---------------------------------------------
        explicit Switcher();
        explicit Switcher(const std::deque<unsigned> *other);
        Switcher(Switcher &other) = delete;

        //---------------------------------------------
        //! @Operators:
        //! operator =
        //! operator<<
        //---------------------------------------------
        bool setMemory(const std::deque<unsigned> *other);
        bool run();

    private:
        const std::deque<unsigned>           *cmdMemoryPtr_;
        size_t                                cmdCounter_;
        std::array<size_t, LABEL_TABLE_WIDTH> labelTable_;
    };
#endif // _SWITCHER_H_

    bool Switcher::setMemory(const std::deque<unsigned> *memPtr)
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

    bool Switcher::run()
    {
        if(cmdCounter_ != 0)
        {
            return false;
        }
        fillLabelTable();
        processCmds();
        return true;
    }


    void clearLableTable()
    {
        for(auto i : labelTable_)
        {
            labelTable_[i] = 0;
        }
    }

    void Switcher::fillLabelTable()
    {
        clearLableTable();
        while(*(cmdMemoryPtr_ + cmdCounter_) != '\0')
        {
            if(*(cmdMemoryPtr_ + cmdCounter_) & ((1 << HALF_WORD) - 1) == ':')
            {
                labelTable_[*(cmdMemoryPtr_ + cmdCounter_) >> HALF_WORD] = cmdCounter_;
            }
            ++cmdCounter_;
        }
        cmdCounter_ = 0;
    }


    char Switcher::processCmds()
    {
        unsigned cmdWord = 0;
        while((cmdWord = *(cmdMemoryPtr_ + cmdCounter_)) != '\0')
        {
            switch(cmdWord >> HALF_WORD)
            {
                case ADD_CMD :
                {
                    if(stack_->size() < 2)
                    {
                        return 1; // return Error Code
                    }
                    value_type op1 = stack_->front();
                    stack_->pop_front();
                    value_type op2 = stack_->front();
                    stack_->pop_front();
                    stack_->push_back(op1 + op2);
                }
                break;
                case ADDI_CMD :
                {
                    if(stack_->size() < 1)
                    {
                        return 1; // return Error Code
                    }
                    value_type op1 = stack_->front();
                    stack_->pop_front();
                    stack_->push_back(op1 + (cmdWord & ((1 << HALF_WORD) - 1)));
                }
                break;
                case AND_CMD :
                {
                    if(stack_->size() < 2)
                    {
                        return 1; // return Error Code
                    }
                    value_type op1 = stack_->front();
                    stack_->pop_front();
                    value_type op2 = stack_->front();
                    stack_->pop_front();
                    stack_->push_back(op1 & op2);
                }
                break;
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
                
            }
        }
        cmdCounter_ = 0;
        return 0;
    }
