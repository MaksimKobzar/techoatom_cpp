//---------------------------------------------
//! @IDE CLion
//! @file BoolOperation.hpp
//! Header file BoolOperation structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _BOOL_OPERATION_HPP_
#define _BOOL_OPERATION_HPP_

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

struct BoolOperation
{
    //---------------------------------------------
    //! @Constructor
    //! Create class BoolOperation
    //---------------------------------------------
    explicit BoolOperation(size_t index, unsigned *word);

    //---------------------------------------------
    //! @Operators:
    //! operator =
    //---------------------------------------------
    bool operator=(bool value);

private:
    size_t        index_;
    unsigned      *word_;
};

#endif // _BOOL_OPERATION_HPP_