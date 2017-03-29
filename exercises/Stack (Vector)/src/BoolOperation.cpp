//---------------------------------------------
//! @file BoolOperation.cpp
//! Implementation of BoolOperation structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "BoolOperation.h"

// ---------------------------------------------------------
// Definitions for BoolOperation
//----------------------------------------------------------
BoolOperation::BoolOperation(size_t index, unsigned *word)
    : index_(index), word_(word), value_ (!!(*word_ & (1 << index_))) { }

~BoolOperation::BoolOperation()
  : {
    
}

const BoolOperation &BoolOperation::operator=(bool value)
{
    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - start bool assignment");
    #endif

    if(value)
    {
        *word_ = *word_ | (1 << index_);
    }
    else
    {
        *word_ = *word_ & ~(1 << index_);
    }

    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - end bool assignment");
    #endif
    return *this;
}

const BoolOperation &BoolOperation::operator=(const BoolOperation &other)
{
    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - start BoolOperation assignment");
    #endif

    value_ = other.value_;
    if(value_)
    {
        *word_ = *word_ |  (1 << index_);
    }
    else
    {
        *word_ = *word_ & ~(1 << index_);
    }

    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - end BoolOperation assignment");
    #endif
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BoolOperation& op)
{
    os << !!(*op.word_ & (1 << op.index_));
    return os;
}