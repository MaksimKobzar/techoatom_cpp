//---------------------------------------------
//! @file BoolOperation.h
//! Header file BoolOperation structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _BOOL_OPERATION_H_
#define _BOOL_OPERATION_H_

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
        //! @Constructor
        //! Destruct class BoolOperation
        //---------------------------------------------
        ~BoolOperation();

        //---------------------------------------------
        //! @Operators:
        //! 1) operator =
        //! 2) operator<<
        //---------------------------------------------
        const BoolOperation &operator=(const BoolOperation &other);
        const BoolOperation &operator=(bool value);
        friend std::ostream &operator<<(std::ostream &os, const BoolOperation &op);

    private:
        size_t      index_;
        unsigned   *word_;
        bool        value_;
    };
#endif // _BOOL_OPERATION_H_