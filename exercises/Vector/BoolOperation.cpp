//---------------------------------------------
//! @file BoolOperation.cpp
//! Implementation of BoolOperation structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "BoolOperation.hpp"

// ---------------------------------------------------------
// Definitions for BoolOperation
//----------------------------------------------------------
BoolOperation::BoolOperation(size_t index, unsigned *word) :
    index_(index), word_(word), value_ (!!(*word_ & (1 << index_))) { }

const BoolOperation &BoolOperation::operator=(bool value)
{
    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - start operator=");
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
        DEBUG_INFO("BoolOperation - end operator=");
    #endif
    return *this;
}

const BoolOperation &BoolOperation::operator=(const BoolOperation &other) const
{
    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - start operator=");
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
        DEBUG_INFO("BoolOperation - end operator=");
    #endif
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BoolOperation& op)
{
    os << !!(*op.word_ & (1 << op.index_));
    return os;
}