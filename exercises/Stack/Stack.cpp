//---------------------------------------------
//! @IDE CLion
//! @file Stack.cpp
//! Implements a stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "Stack.h"


class Stack
{
public:

//    value_type	Container::value_type
//    size_type	Container::size_type
//    reference	Container::reference
//    const_reference	Container::const_reference

    typedef float value_type;
    typedef int size_type;


    //---------------------------------------------
    //! @Element_access
    //---------------------------------------------
    value_type *top();

    //---------------------------------------------
    //! @Capacity
    //---------------------------------------------
    bool empty();
    size_type size();

    //---------------------------------------------
    //! @Modifiers
    //---------------------------------------------
    bool push(value_type&& value);
    bool pop() { };

private:
    static const size_type capacity = 100; // Wthat is static const ?!
    value_type data_ [capacity];
    size_type size_;



    //------------------------------------------------
    // Implementation
    //------------------------------------------------
    value_type *top() {
        if(size_ == 0)
            return nullptr;
        else
            return &data_[size_];
    };

    bool empty() {
        if(size_ == 0)
            return 1;
        return 0;
    }

    size_type size() {
        return size_;
    }

    bool push(value_type&& value) {
        if(size_ == capacity)
            return 0;
        else {
            data_[size_++] = value;            
            return 1;
        }
    } 

    bool pop() {
        if(size_ == 0)
            return 0;
        else {
            size_--;            
            return 1;
        }
    }  


};