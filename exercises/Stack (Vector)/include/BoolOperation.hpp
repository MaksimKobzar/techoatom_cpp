//---------------------------------------------
//! @IDE CLion
//! @file BoolOperation.hpp
//! Header file BoolOperation structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _BOOL_OPERATION_HPP_
#define _BOOL_OPERATION_HPP_

struct BoolOperation
{
    //---------------------------------------------
    //! @Constructor
    //! Create class BoolOperation
    //---------------------------------------------
    explicit BoolOperation(size_t index, unsigned &vec);

    //---------------------------------------------
    //! @Operators:
    //! operator =
    //---------------------------------------------
    bool BoolOperation::operator=(bool value);

private:
    size_t        index_;
    unsigned      &vec_;
};

#endif // _BOOL_OPERATION_HPP_