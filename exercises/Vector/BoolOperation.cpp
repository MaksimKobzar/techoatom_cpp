//---------------------------------------------
//! @IDE CLion
//! @file BoolOperation.hpp
//! Header file BoolOperation structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

//const unsigned DATA_WIDTH = 32;

#include "BoolOperation.hpp"

// ---------------------------------------------------------
// Definitions for BoolOperation
//----------------------------------------------------------
BoolOperation::BoolOperation(size_t index, unsigned *word) :
    index_(index), word_(word) { }

bool BoolOperation::operator=(bool value)
{
    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - start operator=");
    #endif

    if(value)
    {
        *word_ = *word_ | (1 << index_);
    }
    else {
        *word_ = *word_ & ~(1 << index_);
    }

    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - end operator=");
    #endif
    return value;
}