//---------------------------------------------
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
        //! operator<<
        //---------------------------------------------
        const BoolOperation &operator=(const BoolOperation &other);
        const BoolOperation &operator=(bool value) const;
        friend std::ostream &operator<<(std::ostream &os, const BoolOperation &op);

    private:
        size_t      index_;
        unsigned   *word_;
        bool        value_;
    };
#endif // _BOOL_OPERATION_HPP_