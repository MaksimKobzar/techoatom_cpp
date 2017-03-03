//---------------------------------------------
//! @IDE CLion
//! @file Stack.cpp
//! Implements functions of a stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <fstream>
#include <iostream>
#include "Stack.hpp"

#define ASSERT_OK()     \
    if (!ok())          \
    {                   \
        dump();         \
    }

const Stack::size_type POISON_INT = 1322;

//------------------------------------------------
//Stack::Stack() : size_ (0), capacity_(capacity)
Stack::Stack() : size_ (0)
{
    std::cout << __func__ << std::endl;
}
//------------------------------------------------
Stack::~Stack() {
    size_ = POISON_INT;
}
//------------------------------------------------
Stack::value_type *Stack::top() {
//    ASSERT_OK();
    if(size_ == 0)
        return nullptr;
    else {
        return &data_[size_-1];
    }
};
//------------------------------------------------
bool Stack::empty() {
//    ASSERT_OK();
    if(size_ == 0)
        return 1;
    return 0;
}
//------------------------------------------------
Stack::size_type Stack::size() {
//    ASSERT_OK();
    return size_;
}
//------------------------------------------------
//Stack::size_type Stack::capacity() {
//    ASSERT_OK();
//    int cap = capacity_;
//    return cap;
//}
//------------------------------------------------
bool Stack::push(value_type& value) {
//    ASSERT_OK();
    if(size_ == capacity_)
        return 0;
    else {
        data_[size_++] = value;
        return 1;
    }
}
//------------------------------------------------
bool Stack::pop() {
//    ASSERT_OK();
    if(size_ == 0)
        return 0;
    else {
        size_--;
        return 1;
    }
}
//------------------------------------------------
bool Stack::ok() {
//    ASSERT_OK();
    return size_ <= capacity_;
}
//------------------------------------------------
bool Stack::dump() {
//    std::ofstream outputFile;
//    std::string outString;
//    outputFile.open("Dump.txt");
//    for (int i = 0; i < 6; ++i)
//    {
//        if      (i == 0) outString = "|---------------------------------------------|";
//        else if (i == 1) outString = "|                      Dump                   |" ;
//        else if (i == 2) outString = "|---------------------------------------------|" ;
//        else if (i == 3) outString = "  SIZE : ";
//        else if (i == 4) outString = "  CAPACITY : ";
//        else             outString = "|---------------------------------------------|" ;
//
//        if(i == 3) {
//            outputFile << outString << size_ << std::endl;
//            std::cout << outString << size_ << std::endl;
//        }
//        else if(i == 4) {
//            outputFile << outString << capacity_ << std::endl;
//            std::cout << outString << capacity_ << std::endl;
//        }
//        else {
//            outputFile  << outString << std::endl;
//            std::cout   << outString << std::endl;
//        }
//    }
//    outputFile.close();
    return 1;
}
//------------------------------------------------
