//---------------------------------------------
//! @IDE CLion
//! @file Stack.cpp
//! Implements functions of a stack class
//!
//! @author Maksim_Kobzar, 2017
// TODO add dump in file
//---------------------------------------------

#include "Stack.hpp"

#define ASSERT_OK() \
    if (!ok()) \
    { \
        dump(); \
        assert (!“Object is OK”); \
    }

const Stack::size_type POISON_INT = 1322;

//------------------------------------------------
Stack::Stack() : size_ (0), capacity_(capacity)
{
    std::cout << __func__ << std::endl;
}
//------------------------------------------------
Stack::~Stack() {
    size_ = POISON_INT;
}
//------------------------------------------------
Stack::value_type *Stack::top() {
    ASSERT_OK();
    if(size_ == 0)
        return nullptr;
    else {
        return &data_[size_-1];
    }
};
//------------------------------------------------
bool Stack::empty() {
    ASSERT_OK();
    if(size_ == 0)
        return 1;
    return 0;
}
//------------------------------------------------
Stack::size_type Stack::size() {
    ASSERT_OK();
    return size_;
}
//------------------------------------------------
Stack::size_type Stack::capacity() {
    ASSERT_OK();
    return capacity_;
}
//------------------------------------------------
bool Stack::push(value_type& value) {
    ASSERT_OK();
    if(size_ == capacity_)
        return 0;
    else {
        data_[size_++] = value;
        return 1;
    }
}
//------------------------------------------------
bool Stack::pop() {
    ASSERT_OK();
    if(size_ == 0)
        return 0;
    else {
        size_--;
        return 1;
    }
}
//------------------------------------------------
bool Stack::ok() {
    ASSERT_OK();
    return size_ <= capacity_;
}
//------------------------------------------------
bool Stack::dump() {
    cout << "|---------------------------------------------|" << endl;
    cout << "|                      Dump                   |" << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << "| SIZE " << size_ << "                         |"<< endl;
    cout << "| CAPACITY " << capacity_ << "                 |"<< endl;
    cout << "|---------------------------------------------|" << endl;
}
//------------------------------------------------
