//---------------------------------------------
//! @IDE CLion
//! @file Stack.cpp
//! Implements functions of a stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "Stack.hpp"

//------------------------------------------------
// Implementation
//------------------------------------------------
Stack::value_type *Stack::top() {
    if(size_ == 0)
        return nullptr;
    else {
        return &data_[size_-1];
    }
};

bool Stack::empty() {
    if(size_ == 0)
        return 1;
    return 0;
}

Stack::size_type Stack::size() {
    return size_;
}

bool Stack::push(value_type& value) {
    if(size_ == capacity_)
        return 0;
    else {
//        std::cout << "Push func " << value  << std::endl;
        data_[size_++] = value;
        return 1;
    }
}

bool Stack::pop() {
    if(size_ == 0)
        return 0;
    else {
        size_--;
        return 1;
    }
}