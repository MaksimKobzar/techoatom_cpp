//---------------------------------------------
//! @IDE CLion
//! @file BoolOperation.hpp
//! Header file BoolOperation structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "BoolOperation.hpp"


// ---------------------------------------------------------
// Definitions for BoolOperation
//----------------------------------------------------------
explicit BoolOperation::BoolOperation(size_t index, unsigned &vec) :
    index_(index), vec_(vec) { }

bool BoolOperation::operator=(bool value)
{
    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - start operator=");
    #endif

    if(value)
    {
        vec_[index_/sizeof(unsigned)] = vec_[index_/sizeof(unsigned)] |
                                                    (1 << vec_.index_%sizeof(unsigned));
    }
    else {
        vec_[index_/sizeof(unsigned)] = vec_[index_/sizeof(unsigned)] &
                                                    (0 << vec_.index_%sizeof(unsigned));
    }

    #ifdef NDEBUG
        DEBUG_INFO("BoolOperation - end operator=");
    #endif
    return value;
}